// Pin Definitions
const int relay_9 = 3;                 // Generator Speed Sensor (9)
const int relay_power_indicator = 4;   // Power Indicator (39)
const int relay_10 = 5;                // Starter Speed Sensor (10)
const int relay_13 = 8;                // Electric Motor (13) - Only motor used
const int relay_fuel_pump = 6;         // Fuel Pump
const int led1 = 13;                   // LED Indicator
const int switchPin = 2;               // Toggle switch (active LOW)

bool sequenceStarted = false;
bool prevSwitchState = HIGH;
unsigned long startTime = 0;

void setup() {
  Serial.begin(9600);

  // Configure all pins as OUTPUT
  pinMode(relay_9, OUTPUT);
  pinMode(relay_power_indicator, OUTPUT);
  pinMode(relay_10, OUTPUT);
  pinMode(relay_13, OUTPUT);
  pinMode(relay_fuel_pump, OUTPUT);
  pinMode(led1, OUTPUT);

  // Configure switch pin as input with internal pull-up resistor
  pinMode(switchPin, INPUT_PULLUP);

  // Reset all relays and indicators to LOW
  resetSystem();
  Serial.println("System Initialized: Toggle switch to start...");
}

void loop() {
  int currentSwitchState = digitalRead(switchPin);

  // Detect falling edge (toggle from HIGH to LOW)
  if (!sequenceStarted && prevSwitchState == HIGH && currentSwitchState == LOW) {
    Serial.println("Switch Toggled ON: Waiting 4 seconds before starting...");
    delay(2000);  // Delay before starting the sequence

    sequenceStarted = true;
    startTime = millis();

    // Step 1: Turn ON Motor and Fuel Pump
    digitalWrite(relay_13, HIGH);
    digitalWrite(relay_fuel_pump, HIGH);
    Serial.println("Sequence Started: Motor (13) and Fuel Pump turned ON.");
  }

  prevSwitchState = currentSwitchState;

  if (sequenceStarted) {
    unsigned long currentTime = millis() - startTime;

    // Step 2: After 2 seconds, turn ON Generator Speed Sensor (relay_9)
    if (currentTime >= 2000 && currentTime < 3000) {
      digitalWrite(relay_9, HIGH);
      Serial.println("2s: Generator Speed Sensor (9) turned ON.");
    }

    // Step 3: After 14.5 seconds, turn OFF Motor and turn ON Power Indicator (relay_power_indicator)
    if (currentTime >= 14500 && currentTime < 15500) {
      digitalWrite(relay_13, LOW);
      Serial.println("14.5s: Motor (13) turned OFF.");

      digitalWrite(relay_power_indicator, HIGH);
      Serial.println("14.5s: Power Indicator (39) turned ON.");
    }

    // Step 4: After 20.5 seconds, turn ON Starter Speed Sensor (relay_10)
    if (currentTime >= 20500 && currentTime < 21500) {
      digitalWrite(relay_10, HIGH);
      Serial.println("20.5s: Starter Speed Sensor (10) turned ON.");
    }

    // Step 5: After 38 seconds, turn OFF Fuel Pump and blink LED once
    if (currentTime >= 38500 && currentTime < 39500) {
      digitalWrite(relay_fuel_pump, LOW);
      Serial.println("38s: Fuel Pump turned OFF.");

      digitalWrite(led1, HIGH);
      delay(500);
      digitalWrite(led1, LOW);
      Serial.println("38s: Status LED blinked once.");

      // End sequence and reset system
      sequenceStarted = false;
      resetSystem();
      Serial.println("Sequence complete. Toggle switch OFF then ON to restart.");
    }
  }
}

void resetSystem() {
  // Set all outputs to LOW (OFF)
  digitalWrite(relay_9, LOW);
  digitalWrite(relay_power_indicator, LOW);
  digitalWrite(relay_10, LOW);
  digitalWrite(relay_13, LOW);
  digitalWrite(relay_fuel_pump, LOW);
  digitalWrite(led1, LOW);
}
