// Copyright : Vincent SAHLER, 2018

#include "robot.hpp"
#include "Arduino.h"

void actualizeMotor(Motor* mg, Motor* md)
{
  if(mg->state==0)
  {
    analogWrite(mg->pins[0], 0);
  }
  else if(mg->state < 0)
  {
    analogWrite(mg->pins[0], mg->state*5);
    digitalWrite(mg->pins[1], HIGH);
    digitalWrite(mg->pins[2], LOW);
  }
  else
  {
    analogWrite(mg->pins[0], mg->state*5);
    digitalWrite(mg->pins[1], LOW);
    digitalWrite(mg->pins[2], HIGH);
  }

  if(md->state==0)
  {
    analogWrite(md->pins[0], 0);
  }
  else if(md->state < 0)
  {
    analogWrite(md->pins[0], md->state*5);
    digitalWrite(md->pins[1], HIGH);
    digitalWrite(md->pins[2], LOW);
  }
  else
  {
    analogWrite(md->pins[0], md->state*5);
    digitalWrite(md->pins[1], LOW);
    digitalWrite(md->pins[2], HIGH);
  }
}

LinesCapt::LinesCapt(int inpins[5])
{
  memcpy(pins, inpins, 5*sizeof(int));
  for(int x=0;x<5;x++)
    pinMode(pins[x], INPUT);
}

int LinesCapt::addDetector(int detectorValues[5])
{
  detectorLen++;
  for(int it=0;it<5;it++)
    detector[detectorLen-1][it] = detectorValues[it];

  return detectorLen-1;
}

int LinesCapt::detect()
{
  bool result;
  int resultIndex = 0;

  for(int x=0;x<5;x++)
    if(digitalRead(pins[x]) == HIGH)  states[x] = 1;
    else                              states[x] = 0;

  for(int it=0;it<detectorLen;it++)
  {
    resultIndex++;
    result = true;
    for(int x=0;x<5;x++)
    {
      if(result && states[x]==detector[it][x])
      {result = true;}else{result = false;}
    }
    if(result)
      break;
  }
  if(!result) resultIndex = -1;
  return resultIndex;
}
