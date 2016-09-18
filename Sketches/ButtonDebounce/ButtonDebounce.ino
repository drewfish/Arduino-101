//
// Since buttons are not perfect, when being pressed or released the metal
// contacts in them can sometimes bounce together.  This happens very quickly
// but the Arduino is very quick and can see this as a bunch of separate
// button presses and releases.  Usually your program cares about the button
// press as a human experiences it, so we need to reinterpret this series
// of very quick press/release transitions into a single press or release.
// We call this "debouncing" the button.
//
// The algorithm below waits until the button has not changed for 50
// milliseconds (.050 seconds) before acting on the "debounced" state.
// We use the millis() function which returns the number of milliseconds
// which have elapsed since the Arduino was reset or turned on.
// https://www.arduino.cc/en/Reference/Millis
//


#define PIN_BUTTON 11
#define PIN_LED 13
// milliseconds before a change should be registered
#define DEBOUNCE_TIMEOUT 50

// The state (HIGH or LOW) of the button the last time we read it.
int button_lastread_state;
// When we last saw the button change (measured in milliseconds since
// the Arduino started).
long button_lastchange_time;
// The last state of the button after we've debounced it.
int button_lastdebounced_state;
// The state to which we've set the LED.  We keep track of this so that we
// can flip it back and forth between HIGH and LOW.
int led_state = LOW;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_LED, led_state);

  button_lastread_state = digitalRead(PIN_BUTTON);
  button_lastchange_time = millis();
  button_lastdebounced_state = button_lastread_state;
}

void loop() {
  int button_current_state = digitalRead(PIN_BUTTON);

  // If the button state has changed then capture the time that the change
  // occurred.
  if (button_current_state != button_lastread_state) {
    button_lastchange_time = millis();
    // Save for next iteration through loop().
    button_lastread_state = button_current_state;
  }

  // If we've gone DEBOUNCE_TIMEOUT without the button pin changing then the
  // pin has stabilized and is no longer bouncing.
  if ((millis() - button_lastchange_time) > DEBOUNCE_TIMEOUT) {
    // We also check that the value that it has stabilized to is different
    // than what we last reported.
    if (button_lastdebounced_state != button_current_state) {
      button_lastdebounced_state = button_current_state;

      // We only change the LED if the button was pressed (HIGH).
      if (button_lastdebounced_state == HIGH) {
        led_state = !led_state;
        digitalWrite(PIN_LED, led_state);
      }
    }
  }
}
