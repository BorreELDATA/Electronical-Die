/**
 * Creator: Børre A. Opedal Lunde
 * Date created (yyyy/mm/dd): 2019/02/20
 * Date updated (yyyy/mm/dd): 2019/04/08
 */

#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led {
  public:
    Led();
    Led(char pin);
    void setPinNumber(char pin);
    char getPinNumber();
    void setState(char state);
    boolean isOn();
  private:
    char _pin;
    char _state;
};

#endif
