/**
 *  Electronical die made out of LEDs is rolled by pressing
 *  a button. Rolling unfairly is enabled/disabled by writing
 *  'c', the cheat character, to the serial monitor. When
 *  cheating is enabled, you are more likely to roll six.
 *
 *  Author: Børre A. Opedal Lunde
 *  Date created (yyyy/mm/dd): 2019/02/20
 *  Date updated (yyyy/mm/dd): 2019/04/08
 */

#include <Button.h>
#include <Led.h>
#include <Die.h>

// To improve readability of the code, HIGH and LOW is redefined ON and
// OFF. This because it is more intuitive to understand the behaviour of
// an LED by turning it on or off, rather than setting it high or low.
#define ON HIGH
#define OFF LOW

const char CHEAT_CHARACTER = 'c';

Die die;
Button button(2); //                                    Digital pin:  2
Led ledTL(13);    // TL: top-left        Die layout:    Digital pin: 13
Led ledTR(9);     // TR: top-right      |---------- |   Digital pin:  9
Led ledL(12);     // L:  left           | TL     TR |   Digital pin: 12
Led ledC(10);     // C:  centre         |  L  C  R  |   Digital pin: 10
Led ledR(8);      // R:  right          | BL     BR |   Digital pin:  8
Led ledBL(11);    // BL: bottom-left    |-----------|   Digital pin: 11
Led ledBR(7);     // BR: bottom-right                   Digital pin:  7

void showDieFace(char number);

/**
 *  The code in setup is run once the program starts.
 */
void setup() {
  Serial.begin(9600);  // Baud rate 9600 Bd.
}

/**
 *  The code in loop is repeated all the time, after setup is finished.
 */
void loop() {
  // Updates the button's previous and current state. This is necessary
  // in order to check if the button is pressed or has switched state.
  button.update();

  // Toggle cheating if the cheat character is sent to the serial monitor.
  if (Serial.read() == CHEAT_CHARACTER) die.toggleCheating();

  // Only continue the code if the button is pressed and the button
  // has switched state. This makes sure the button only registers a
  // press once, even when it is held in for a long period of time.
  if (!button.isPressed() || !button.hasSwitchedState()) return;

  // The die rolls unfairly when cheating
  // is enabled, otherwise it rolls fairly.
  die.roll();

  // Shows the die face received from the result of the roll of the die.
  showDieFace(die.getResult());

  // Debug message in serial monitor outputs the result of the roll.
  Serial.println("Die result: " + (String) die.getResult() + ".");
}

/**
 *  Turns on the LEDs of the given die face and turns off the rest.
 *  @param  number 
 *          the number that represents the die face to be shown.
 *          
 *  F.e.: if the number is 3, LEDs of die face
 *  three is turned on, and the rest turned off.
 */
void showDieFace(char number) {
  switch (number) {
    case 1: // Shows die face one.
      ledTL.setState(OFF);
      ledTR.setState(OFF);
      ledL.setState(OFF);
      ledC.setState(ON);
      ledR.setState(OFF);
      ledBL.setState(OFF);
      ledBR.setState(OFF);
      break;
    case 2: // Shows die face two.
      ledTL.setState(ON);
      ledTR.setState(OFF);
      ledL.setState(OFF);
      ledC.setState(OFF);
      ledR.setState(OFF);
      ledBL.setState(OFF);
      ledBR.setState(ON);
      break;
    case 3: // Shows die face three.
      ledTL.setState(ON);
      ledTR.setState(OFF);
      ledL.setState(OFF);
      ledC.setState(ON);
      ledR.setState(OFF);
      ledBL.setState(OFF);
      ledBR.setState(ON);
      break;
    case 4: // Shows die face four.
      ledTL.setState(ON);
      ledTR.setState(ON);
      ledL.setState(OFF);
      ledC.setState(OFF);
      ledR.setState(OFF);
      ledBL.setState(ON);
      ledBR.setState(ON);
      break;
    case 5: // Shows die face five.
      ledTL.setState(ON);
      ledTR.setState(ON);
      ledL.setState(OFF);
      ledC.setState(ON);
      ledR.setState(OFF);
      ledBL.setState(ON);
      ledBR.setState(ON);
      break;
    case 6: // Shows die face six.
      ledTL.setState(ON);
      ledTR.setState(ON);
      ledL.setState(ON);
      ledC.setState(OFF);
      ledR.setState(ON);
      ledBL.setState(ON);
      ledBR.setState(ON);
      break;
    default: Serial.println("Should not reach here.");
  }
}
