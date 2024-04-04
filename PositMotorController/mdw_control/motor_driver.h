/**
 * @file
 *
 * @brief        Header file for middleware layer for motor
 * 				 controller.
 *
 */

#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "stdint.h"
#include "drv_low.h"

/******************************************************************************
 * Extern Function Declarations
 ******************************************************************************/

/**
 * @brief   Init the low level driver. Initialise gpio and timer.
 *
 * @return  None
 */
extern void MotorDriverInit(void);

/**
 * @brief   Start the motor intially.
 *
 * @return  None
 */
extern void MotorDriverStartMotor(void);

/**
 * @brief   Move the motor forward.
 *
 * @param	speed_u16   : Speed of the motor, which is duty cycle for pwm.
 *
 * @return  None
 */
extern void MotorDriverMoveForward(uint16_t speed_u16);

/**
 * @brief   Move the motor in reverse.
 *
 * @param	speed_u16   : Speed of the motor, which is duty cycle for pwm.
 *
 * @return  None
 */
extern void MotorDriverMoveBackward(uint16_t speed_u16);

/**
 * @brief   Stop motor running.
 *
 * @param	selector_en : Pass the motor to be selected.
 *
 * @return  None
 */
extern void MotorDriverStopMotor(DrvLowMotorSelectorEn selector_en);

#endif /* MOTOR_DRIVER_H_ */
