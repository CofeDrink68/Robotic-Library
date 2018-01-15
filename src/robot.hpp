// Cpyright : Vincent SAHLER, 2018

#include "Arduino.h"

struct myMoteur
{
  int pins[3];
  int state;
};
typedef struct myMoteur Motor;
void actializeMotor(Motor* mg, Motor* md);

class LinesCapt{
  public:
    int states[5];
    int pins[5];
    int detector[32][5];
    int detectorLen = 0;
    LinesCapt(int inpins[5]);
    int detect();
    int addDetector(int detectorValues[5]); // return value id
};
