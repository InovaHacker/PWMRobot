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

// --------------------------------------------------------------------------- Setup
void setup() {
Serial.begin(9600);

//begin robot
InovaHackerRobot.setup();
}

// --------------------------------------------------------------------------- Loop

void loop() {

      // stop the motors 5 seconds
      InovaHackerRobot.stopBridge();
      delay(5000);

    // move forward 2 seconds with half speed
      InovaHackerRobot.setSpeed(128, 128);
      InovaHackerRobot.driveForward();
      delay(2000);

      // move forward 2 seconds with maximum speed
      InovaHackerRobot.setSpeed(255, 255);
      InovaHackerRobot.driveForward();
      delay(2000);

    // move backward 2 seconds with half speed
      InovaHackerRobot.setSpeed(128, 128);
      InovaHackerRobot.driveBackward();
      delay(2000);
      // move backward 2 seconds with maximum speed
      InovaHackerRobot.setSpeed(255, 255);
      InovaHackerRobot.driveBackward();
      delay(2000);

      // set robot a half speed
      InovaHackerRobot.setSpeed(128, 128);

     // turn right 2 seconds

      InovaHackerRobot.driveRight();
      delay(2000);


     // turn left 2 seconds
      InovaHackerRobot.driveLeft();
      delay(2000);


  }
