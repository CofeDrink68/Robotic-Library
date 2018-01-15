# Robotic-Library
Arduino

My own library for robot controlling:
- L298N H-bridge supported,
- Line detector supported

Structures :
  - Motor, for L298N Motor (2 Pins)

Functions :
  - void actualizeMotor(Motor mG, Motor mD), actualize the motor with Motor.state integer

Classes :
  - LinesCapt
    - __init__(int pins[5]), 5 pins of the detector, pinMode is made
    - int addDetector(int values[5]), values = values (1=on, 0=off) of the detector, return detectorId
    - int detect(), return -1 if the patern is not recognized, or the id of the recognized patern (the first declarated when multiples detector are the same)

This library is written by Vincent SAHLER, the 14/01/2018
