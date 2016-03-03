/**
 * PWM Robot
 *
 * Test sketch for pwm robot
 *
 *	author: João Campos
 *
 *
 *
 */

// include PWM Robot library for robot
#include "PWMRobot.h"

// --------------------------------------------------------------------------- Motors
const int motorLeft[] = {9, 3};
const int motorRight[] = {10, 11};

PWMRobot InovaHackerRobot(motorLeft,motorRight);
int x = 0;
// --------------------------------------------------------------------------- Setup
void setup() {
Serial.begin(9600);

//begin robot
InovaHackerRobot.setup();
}

// --------------------------------------------------------------------------- Loop

void loop() {



    // move forward 2 seconds with half speed
      InovaHackerRobot.setSpeed(x, x);
      InovaHackerRobot.driveForward();
      delay(2000);
      x=x+20;


  }
