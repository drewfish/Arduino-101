#define PIN_LED 13

// The current brightness of the LED.
int brightness = 0;
// This variable is how much we'll change the brightness, either `1` to
// increase the brightness or `-1` to decrease the brightness.
int slope = 1;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // Change the brightness, either up or down.
  brightness += slope;

  // If we reach maximum brightness we'll change the slope so that next time
  // we'll dim the LED.  As we reach minimum brightness we'll change the slope
  // so next we'll brighten the LED.
  if (brightness >= 255) {
    slope = -1;
  } else if (brightness <= 0) {
    slope = 1;
  }

  // The `analogWrite()` function makes the pin blink on and off very fast.
  // The ratio of time spent on to time spent off is called Pulse Width
  // Modulation (PWM).  Only those pins with a tilde (~) on the board next to
  // them support PWM.  The value ranges from 0 to 255 representing the ratio
  // of on to off -- 0 is always off and 255 is always on.  Once this function
  // returns the Arduino will blink the pin in the background, so our sketch
  // will continue to run.
  // https://www.arduino.cc/en/Reference/AnalogWrite
  // Human persistance of vision is unable to see very fast blinking and will
  // interpret the on:off ratio as brightness.
  analogWrite(PIN_LED, brightness);

  // Wait a little bit before adjusting the brightness again.
  delay(2);
}
