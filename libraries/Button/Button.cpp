/**
 * Creator: Børre A. Opedal Lunde
 * Date created (yyyy/mm/dd): 2019/02/20
 * Date updated (yyyy/mm/dd): 2019/04/04
 */

#include "Arduino.h"
#include "Button.h"

/**
 * Constructor with no parameters.
 */
Button::Button() {}

/**
 * Constructor that registers the pin mode of the specified pin number.
 * @param  pin
 *         the pin number the button is connected to the Arduino board on.
 */
Button::Button(char pin) {
  setPinNumber(pin);
}

/**
 * Sets the pin number of the button. This function is necessary
 * if the constructor with no parameters has been used.
 * @param  pin
 *         the pin number the button is connected to the Arduino board on.
 */
void Button::setPinNumber(char pin) {
	_pin = pin;
	pinMode(_pin, INPUT);
}

/**
 * Updates the current state of the button.
 */
void Button::updateCurrentState() {
	_state = digitalRead(_pin);
}

/**
 * Updates the previous state of the button.
 */
void Button::updatePreviousState() {
	_previousState = _state;
}

/**
 * Updates both previous and current state of the button.
 */
void Button::update() {
	updatePreviousState();
	updateCurrentState();
}

/**
 * Returns true if the button is
 * pressed, and false otherwise.
 */
boolean Button::isPressed() {
  // If the button state is HIGH, the button is pressed and the function returns true.
  return _state == HIGH;
}

/**
 * Returns true if the current state
 * is different from the previous state.
 */
boolean Button::hasSwitchedState() {
	return _state != _previousState;
}

/**
 * Returns the pin number of the button. The number of
 * the port it is connected to on the Arduino board.
 */
char Button::getPin() {
  return _pin;
}