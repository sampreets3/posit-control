/**
 * @file
 *
 * @brief        Header file for low interface driver module for motor
 * 				 controller.
 *
 */

#ifndef DRV_LOW_H_
#define DRV_LOW_H_

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "stdint.h"

/******************************************************************************
 * Type Declarations
 ******************************************************************************/
typedef enum
{
	DRV_LOW_LEFT_MOTOR,
	DRV_LOW_RIGHT_MOTOR,
} DrvLowMotorSelectorEn;

/******************************************************************************
 * Extern Function Declarations
 ******************************************************************************/

/**
 * @brief   Init the low level driver. Initialise gpio and timer.
 *
 * @return  None
 */
extern void DrvLowInitController(void);

/**
 * @brief   Start the motor at a input speed and direction.
 *
 * @return  None
 */
extern void DrvLowStartMotor(void);

/**
 * @brief   Forward rotation of the motor.
 *
 * @param	speed_u16   : Speed of the motor, which is duty cycle for pwm.
 *
 * @return  None
 */
extern void DrvLowMotorMoveForward(uint16_t speed_u16);

/**
 * @brief   Reverse rotation of the motor.
 *
 * @param	speed_u16   : Speed of the motor, which is duty cycle for pwm.
 *
 * @return  None
 */
extern void DrvLowMotorMoveReverse(uint16_t speed_u16);

/**
 * @brief   Stop motor running.
 *
 * @return  None
 */
extern void DrvLowStopMotor(void);

#endif /* DRV_LOW_H_ */
