/**
 * Creator: Børre A. Opedal Lunde
 * Date created (yyyy/mm/dd): 2019/02/20
 * Date updated (yyyy/mm/dd): 2019/04/04
 */

#include "Die.h"
#include "Arduino.h"

/**
 * Empty Die constructor.
 */
Die::Die() {}

/**
 * Rolls the die. The die is rolled unfairly if cheating is enabled, otherwise it is rolled fairly.
 */
void Die::roll() {
	if (_cheat) {
		rollUnfairly();
	} else {
		rollFairly();
	}
}

/**
 * Rolls the die fairly. The function randomly selects one of the possible
 * results (from 1 to 6). All possible results are equally likely to be chosen.
 */
void Die::rollFairly() {
	char possibleResults[] = {1, 2, 3, 4, 5, 6};
	// The number of elements in the array can be found by
	// dividing the total length by one element, assuming
	// every element in the array holds the same number of bytes.
	char numberOfElements = sizeof(possibleResults) / sizeof(possibleResults[0]);
	_result = possibleResults[random(0, numberOfElements)];
	_thrown = true;
}

/**
 * Rolls the die unfairly. There is a 50% chance of cheating and 50% chance of rolling fairly.
 */
void Die::rollUnfairly() {
	// 50% chance of getting 0.
	if (random(0, 2) == 0) {
		_result = 6;
		_thrown = true;
		return;
	}
	rollFairly();
}

/**
 * Toggles cheating on or off.
 */
void Die::toggleCheating() {
	_cheat = !_cheat;
}

/**
 * Returns the result of the last roll. Return type is byte instead of char because
 * char couldn't be read in serial monitor in main program for unknown reasons (showed
 * as space).
 */
byte Die::getResult() {
	return _result;
}

/**
 * Returns true if the die has been thrown before.
 */
boolean Die::hasThrown() {
	return _thrown;
}

/**
 * Returns true if cheating is enabled.
 */
boolean Die::isCheating() {
	return _cheat;
}