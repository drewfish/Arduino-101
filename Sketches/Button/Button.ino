// Define `PIN_BUTTON` to be the pin number on the Arduino board in which we've
// plugged the button.
#define PIN_BUTTON 11
#define PIN_LED 13    // LED plugged into pin 13

void setup() {
  pinMode(PIN_LED, OUTPUT);   // Initialize LED pin as output
  pinMode(PIN_BUTTON, INPUT); // Initialize button pin as input
}

void loop() {
  // The digitalRead() button returns the state of the button, `HIGH` if it's
  // 5 volts or `LOW` if it's 0 volts.
  // If the pin is not connected to anything, digitalRead() will return a
  // random value.
  // https://www.arduino.cc/en/Reference/DigitalRead
  int button_state = digitalRead(PIN_BUTTON); // Read the current state of the button.
  if (button_state == HIGH) {     // If the button is pressed...
    digitalWrite(PIN_LED, HIGH);  // turn on the LED,
  } else {                        // otherwise...
    digitalWrite(PIN_LED, LOW);   // turn off the LED.
  }
}
