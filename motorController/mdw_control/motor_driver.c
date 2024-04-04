/**
 * @file
 *
 * @brief		Middleware layer for controlling motor rotation.
 *
 */

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "motor_driver.h"
#include "drv_low.h"

/******************************************************************************
 * Extern Function Definitions
 ******************************************************************************/
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
	DrvLowMotorMoveForward(speed_u16);
}


extern void MotorDriverMoveBackward(uint16_t speed_u16)
{
	DrvLowMotorMoveReverse(speed_u16);
}


extern void MotorDriverStopMotor(DrvLowMotorSelectorEn selector_en)
{
	DrvLowStopMotor();
	DrvLowStopMotor();
}
