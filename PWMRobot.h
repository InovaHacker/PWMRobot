/*
  PWMRobot.h - Library for PWMRobot extends BaseRobot with pwm functionalities.
  Created by João Campos.
  Released into the public domain.
  works only with the control pins
  - advantage -  uses less pins
  - disadvantage - needs to work with pwm pins
*/

#ifndef PWMRobot_h
#define PWMRobot_h

#include "Arduino.h"
#include <math.h>

class PWMRobot
{
  public:
    PWMRobot(const int * motorLeft, const int * motorRight);
    void setup();
    void move(int motorLeftSpeed, int motorRightSpeed);
    void setSpeed(int motorLeftSpeed, int motorRightSpeed);
    void stop();
    void driveLeft();
    void driveRight();
    void driveForward();
    void driveBackward();
    void stopBridge();

  private:
   const  int * _motorLeft;
   const  int * _motorRight;
   int _motorLeftSpeed;
   int _motorRightSpeed;
};


#endif
