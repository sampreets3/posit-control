/*
 * posit_motor.h
 *
 *  Created on: Nov 18, 2023
 *      Author: user
 */

#ifndef POSIT_CORE_INC_POSIT_MOTOR_H_
#define POSIT_CORE_INC_POSIT_MOTOR_H_

#include "stdint.h"
#include "stdio.h"
#include "stm32f1xx.h"

#include "posit_hal.h"

/**
 * Sets the motor to the desired angular position [rad].
 */
uint32_t SetMotorCmdPosition(MotorState* motor, float cmdPos);

/**
 * Sets the motor to the desired speed. [rad/s]
 */
uint32_t SetMotorCmdVelocity(MotorState* motor, float cmdVel);

/**
 * Returns the angular position of the motor [rad]
 */
float GetMotorAngle(int motorId);

/**
 * Returns the raw encoder position of the motor.
 */
float GetMotorEncoderValue(int motorId);


#endif /* POSIT_CORE_INC_POSIT_MOTOR_H_ */
