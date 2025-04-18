/* This demo shows how the Zumo can use its gyroscope to detect
when it is being rotated, and use the motors to resist that
rotation.

This code was tested on a Zumo with 4 NiMH batteries and two 75:1
HP micro metal gearmotors.  If you have different batteries or
motors, you might need to adjust the PID constants.

Be careful to not move the robot for a few seconds after starting
it while the gyro is being calibrated.  During the gyro
calibration, the yellow LED is on and the words "Gyro cal" are
shown on the display.

After the gyro calibration is done, press button A to start the
demo.  If you try to turn the Zumo, or put it on a surface that
is turning, it will drive its motors to counteract the turning.

This demo only uses the Z axis of the gyro, so it is possible to
pick up the Zumo, rotate it about its X and Y axes, and then put
it down facing in a new position. */

#include <Wire.h>
#include <Zumo32U4.h>

// This is the maximum speed the motors will be allowed to turn.
// A maxSpeed of 400 lets the motors go at top speed.  Decrease
// this value to impose a speed limit.
const int16_t maxSpeed = 400;

// Change next line to this if you are using the older Zumo 32U4
// with a black and green LCD display:
 Zumo32U4LCD display;
//Zumo32U4OLED display;

Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;
Zumo32U4IMU imu;

#include "TurnSensor.h"
// track the time between turns
uint16_t delays = 0;
// interval between turns, milliseconds
uint16_t interval = 3000;

void setup()
{
  turnSensorSetup();
  delay(500);
  turnSensorReset();

  display.clear();
  display.print(F("Try to"));
  display.gotoXY(0, 1);
  display.print(F("turn me!"));
}

void loop()
{
  // Read the gyro to update turnAngle, the estimation of how far
  // the robot has turned, and turnRate, the estimation of how
  // fast it is turning.
  turnSensorUpdate();

  // Adjust the PID loop so the robot's target orientation shifts by 90 degrees.
  if((millis() - delays) > interval){
    turnAngle += turnAngle90;
    delays = millis();
  }
  // Calculate the motor turn speed using proportional and
  // derivative PID terms.  Here we are a using a proportional
  // constant of 56 and a derivative constant of 1/20.
  int32_t turnSpeed = -(int32_t)turnAngle / (turnAngle1 / 56)
    - turnRate / 20;

  // Constrain our motor speeds to be between
  // -maxSpeed and maxSpeed.
  turnSpeed = constrain(turnSpeed, -maxSpeed, maxSpeed);
  motors.setSpeeds(-turnSpeed, turnSpeed);
  display.gotoXY(0, 0);
  display.print(turnAngle);

}
