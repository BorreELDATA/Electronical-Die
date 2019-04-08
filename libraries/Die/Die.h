/**
 * Creator: Børre A. Opedal Lunde
 * Date created (yyyy/mm/dd): 2019/02/20
 * Date updated (yyyy/mm/dd): 2019/04/08
 */

#ifndef Die_h
#define Die_h

#include "Arduino.h"

class Die {
  public:
    Die();
    void roll();
    void toggleCheating();
    boolean isCheating();
    boolean hasThrown();
    byte getResult();
  private:
    void rollFairly();
    void rollUnfairly();
    char _result;
    boolean _thrown;
    boolean _cheat;
};

#endif
