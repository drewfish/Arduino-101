// Define `PIN_LED` to be the pin number on the Arduino board in which we've
// plugged the LED.  By defining this here it makes it easy for us to change
// the pin later and we'll only have to update the code in this one place.
// (This is a common practice which makes it easier to make changes later.)
#define PIN_LED 13

// This `setup()` function is called by Arduino exactly once, at the begining
// once the board has booted up.
// https://www.arduino.cc/en/Reference/Setup
void setup() {
  // The `pinMode()` function configures the pin to be either input or output.
  // https://www.arduino.cc/en/Reference/PinMode
  pinMode(PIN_LED, OUTPUT);
}

// This `loop()` function is called by Arduino again and again, until the
// board is reset or powered off.
// https://www.arduino.cc/en/Reference/Loop
void loop() {
  // The `digitalWrite()` function sets the pin to either HIGH (5 volts) or
  // LOW (0 volts, also called "ground").
  // https://www.arduino.cc/en/Reference/DigitalWrite
  digitalWrite(PIN_LED, HIGH);
  // The `delay()` function pauses this sketch for the specified number of
  // milliseconds. (There are 1000 milliseconds in one second.)
  // https://www.arduino.cc/en/Reference/Delay
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  delay(1000);
}
