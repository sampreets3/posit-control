/**
 * @file
 *
 * @brief        Header file for low interface driver module for motor
 * 				 controller.
 *
 */

#ifndef DRV8874_H_
#define DRV8874_H_

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "stdint.h"

/******************************************************************************
 * Type Declarations
 ******************************************************************************/
typedef enum
{
	DRV_LOW_DIR_FW,
	DRV_LOW_DIR_REV,
} DrvLowMotorDirectionEn; /* Enumerator for selecting direction of rotation in
							 open loop run. */

typedef enum
{
	DRV_LOW_LEFT_MOTOR,
	DRV_LOW_RIGHT_MOTOR,
} DrvLowMotorSelectorEn; /* Enumerator for selecting the motor. */

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
 * @brief   Start the motor at a input speed and direction in open loop use case.
 *
 * @param	selector_en : Motor selector.
 * @param	dir_en      : Direction selector.
 * @param	speed_u16   : Speed of the motor.
 *
 * @return  None
 */
extern void DrvLowStartMotor(DrvLowMotorSelectorEn selector_en, DrvLowMotorDirectionEn dir_en, uint16_t speed_u16);

/**
 * @brief   Forward rotation of the motor.
 *
 * @param	selector_en : Motor selector.
 * @param	speed_u16   : Speed of the motor, which is duty cycle for pwm.
 *
 * @return  None
 */
extern void DrvLowMotorMoveForward(DrvLowMotorSelectorEn selector_en, uint16_t speed_u16);

/**
 * @brief   Reverse rotation of the motor.
 *
 * @param	selector_en : Motor selector.
 * @param	speed_u16   : Speed of the motor, which is duty cycle for pwm.
 *
 * @return  None
 */
extern void DrvLowMotorMoveReverse(DrvLowMotorSelectorEn selector_en, uint16_t speed_u16);

/**
 * @brief   Stop motor running.
 *
 * @param	selector_en   : Motor selector.
 *
 * @return  None
 */
extern void DrvLowStopMotor(DrvLowMotorSelectorEn selector_en);

#endif /* DRV8874_H_ */
