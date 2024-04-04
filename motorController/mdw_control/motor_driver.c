/**
 * @file
 *
 * @brief		Middleware layer for controlling motor rotation.
 *
 */

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "../mdw_control/motor_driver.h"

#include "drv_low.h"


extern void MotorDriverInit(void)
{
	DrvLowInitController();
}


extern void MotorDriverStartMotor(void)
{
	DrvLowStartMotor();
}


extern void MotorDriverMoveForward(uint16_t speed_u16)
{
	DrvLowMotorMoveForward(DRV_LOW_RIGHT_MOTOR, speed_u16);
	DrvLowMotorMoveForward(DRV_LOW_LEFT_MOTOR, speed_u16);
}


extern void MotorDriverMoveBackward(uint16_t speed_u16)
{
	DrvLowMotorMoveReverse(DRV_LOW_RIGHT_MOTOR, speed_u16);
	DrvLowMotorMoveReverse(DRV_LOW_LEFT_MOTOR, speed_u16);
}


extern void MotorDriverStopMotor(DrvLowMotorSelectorEn selector_en)
{
	DrvLowStopMotor(DRV_LOW_RIGHT_MOTOR);
	DrvLowStopMotor(DRV_LOW_LEFT_MOTOR);
}
