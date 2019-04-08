/**
 * Creator: Børre A. Opedal Lunde
 * Date created (yyyy/mm/dd): 2019/02/20
 * Date updated (yyyy/mm/dd): 2019/04/08
 */
 
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
  public:
    Button();
    Button(char pin);
    void setPinNumber(char pin);
    void updateCurrentState();
    void updatePreviousState();
    void update();
    boolean isPressed();
    boolean hasSwitchedState();
    char getPin();
  private:
    char _pin;
    char _state;
    char _previousState;
};

#endif
