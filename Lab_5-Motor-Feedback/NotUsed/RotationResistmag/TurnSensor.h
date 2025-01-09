// Turnsensor.h provides functions for configuring the
// Zumo 32U4's gyro, calibrating it, and using it to
// measure how much the robot has turned about its Z axis.
//
// This file should be included once in your sketch,
// somewhere after you define objects named buttonA,
// display, and imu.

#pragma once

#include <Wire.h>

// These constants represent turns of 45, 90, and approximately 1 degree.
const int32_t turnAngle45 = 0x20000000;
const int32_t turnAngle90 = turnAngle45 * 2;
const int32_t turnAngle1 = (turnAngle45 + 22) / 45;

uint32_t turnAngle = 0; // The amount the robot has turned since the last reset
int16_t turnRate; // The current angular rate of the magnetometer
int16_t magOffset; // The average reading obtained from the magnetometer's Z axis during calibration
uint16_t magLastUpdate = 0; // Helps keep track of how much time has passed between readings


// This should be called to set the starting point for measuring
// a turn.  After calling this, turnAngle will be 0.
void turnSensorReset()
{
  magLastUpdate = micros();
  turnAngle = 0;
}

// Read the gyro and update the angle.  This should be called as
// frequently as possible while using the gyro to do turns.
void turnSensorUpdate()
{
  // Read the measurements from the magnetometer.
  imu.read();
  turnRate = imu.m.z - magOffset;

  // Figure out how much time has passed since the last update (dt)
  uint16_t m = micros();
  uint16_t dt = m - magLastUpdate;
  magLastUpdate = m;

  // Multiply dt by turnRate in order to get an estimation of how
  // much the robot has turned since the last update.
  // (angular change = angular velocity * time)
  int32_t d = (int32_t)turnRate * dt;

  // The units of d are gyro digits times microseconds.  We need
  // to convert those to the units of turnAngle, where 2^29 units
  // represents 45 degrees.  The conversion from gyro digits to
  // degrees per second (dps) is determined by the sensitivity of
  // the gyro: 0.07 degrees per second per digit.
  //
  // (0.07 dps/digit) * (1/1000000 s/us) * (2^29/45 unit/degree)
  // = 14680064/17578125 unit/(digit*us)
  turnAngle += (int64_t)d * 14680064 / 17578125;
}

/* This should be called in setup() to enable and calibrate the
gyro.  It uses the display, yellow LED, and button A.  While the
display shows "Gyro cal", you should be careful to hold the robot
still.

The digital zero-rate level of the gyro can be as high as
25 degrees per second, and this calibration helps us correct for
that. */
void turnSensorSetup()
{
  Wire.begin();
  imu.init();
  imu.enableDefault();
  imu.configureForTurnSensing();

   display.clear();
  display.print(F("Mag cal"));

  ledYellow(1);
  delay(500);

  // Calibrate the magnetometer.
  int32_t total = 0;
  int targ = 256;
  for (uint16_t i = 0; i < targ; i++)
  {
    // Wait for new data to be available, then read it.
    while(!imu.magDataReady()) {}
    imu.read();
    total += imu.m.z;
    display.gotoXY(0, 1);
    display.print(i);
    display.print("/");
    display.print(targ);
  
  }
  ledYellow(0);
  magOffset = total / targ;

  // Display the angle (in degrees from -180 to 180) until the
  // user presses A.
  display.clear();
  turnSensorReset();
  while (!buttonA.getSingleDebouncedRelease())
  {
    turnSensorUpdate();
    display.gotoXY(0, 0);
    display.print((((int32_t)turnAngle >> 16) * 360) >> 16);
    display.print(F("   "));
  }
  display.clear();
}
