#include "PWMRobot.h"


/**
 * @Constructor
 */
PWMRobot::PWMRobot(const int * motorLeft, const int * motorRight):
    _motorLeft(motorLeft), _motorRight(motorRight) {}
/**
 * [PWMRobot::setup set motor pins to OUTPUT]
 */
void PWMRobot::setup()
{
  int i;
  for(i = 0; i < 2; i++){
    pinMode(_motorLeft[i], OUTPUT);
    pinMode(_motorRight[i], OUTPUT);
  }

}
//----------------------------- Robot Movement

/**
 * Use this function with joystick
 * Negative values means backward, and positive values mean forward
 *
 */
void PWMRobot::move(int motorLeftSpeed, int motorRightSpeed){

  if(motorLeftSpeed<0||motorRightSpeed<0){
    PWMRobot::driveBackward();
  }else{
    PWMRobot::driveForward();
  }
//  motorLeftSpeed = std::abs(motorLeftSpeed);
  //motorRightSpeed = std::abs(motorRightSpeed);
  setSpeed(motorLeftSpeed, motorRightSpeed);

}
/**
 * [PWMRobot::setSpeed set speed for the 2 motors]
 * @param motorLeftSpeed  [pwm for left motor]
 * @param motorRightSpeed [pwm for right motor]
 */
void PWMRobot::setSpeed(int motorLeftSpeed, int motorRightSpeed){
_motorLeftSpeed = motorLeftSpeed;
_motorRightSpeed = motorRightSpeed;
}






// --------------------------- Drivers for H bridge-----------------
void PWMRobot::driveForward()
{
  analogWrite(_motorLeft[0], _motorLeftSpeed);
  digitalWrite(_motorLeft[1], LOW);

  analogWrite(_motorRight[0], _motorRightSpeed);
  digitalWrite(_motorRight[1], LOW);

}

void PWMRobot::driveBackward()
{
  digitalWrite(_motorLeft[0], LOW);
  analogWrite(_motorLeft[1], _motorLeftSpeed);

  digitalWrite(_motorRight[0], LOW);
  analogWrite(_motorRight[1], _motorRightSpeed);
}



void PWMRobot::driveLeft()
{
  digitalWrite(_motorLeft[0], LOW);
  analogWrite(_motorLeft[1], _motorLeftSpeed);

  analogWrite(_motorRight[0], _motorRightSpeed);
  digitalWrite(_motorRight[1], LOW);

}

void PWMRobot::driveRight()
{
  analogWrite(_motorLeft[0], _motorLeftSpeed);
  digitalWrite(_motorLeft[1], LOW);

  digitalWrite(_motorRight[0], LOW);
  analogWrite(_motorRight[1], _motorRightSpeed);

}

void PWMRobot::stopBridge()
{
  digitalWrite(_motorLeft[0], LOW);
  digitalWrite(_motorLeft[1], LOW);

  digitalWrite(_motorRight[0], LOW);
  digitalWrite(_motorRight[1], LOW);
  delay(25);

}
