/**
 * Creator: Børre A. Opedal Lunde
 * Date created (yyyy/mm/dd): 2019/02/20
 * Date updated (yyyy/mm/dd): 2019/04/04
 */

#include "Arduino.h"
#include "Led.h"

/**
 * Constructor with no parameters.
 */
Led::Led() {}

/**
 * Constructor that registers the pin mode of the specified pin number.
 * @param  pin
 *		   the pin number the LED is connected to the Arduino board on.
 */
Led::Led(char pin) {
  setPinNumber(pin);
}

/**
 * Sets the pin number of the LED. This function is necessary
 * if the constructor with no parameters has been used.
 * @param  pin
 *         the pin number the LED is connected to the Arduino board on.
 */
void Led::setPinNumber(char pin) {
	_pin = pin;
	_state = LOW;
	pinMode(_pin, OUTPUT);
}

/**
 * Returns the pin number of the LED.
 */
char Led::getPinNumber() {
	return _pin;
}

/**
 * Sets the state of the LED, on (HIGH) or off (LOW).
 * @param  state
 *         the state of the LED, on (HIGH) or off (LOW).
 */
void Led::setState(char state) {
  _state = state;
  digitalWrite(_pin, _state);
}

/**
 * Returns whether the led is turned on (HIGH) or off (LOW). 
 */
boolean Led::isOn() {
  return _state == HIGH;
}