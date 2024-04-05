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
#include "drv8874.h"

/******************************************************************************
 * Extern Function Definitions
 ******************************************************************************/
extern void MotorDriverInit(void)
{
	DrvLowInitController();
}


extern void MotorDriverStartMotor(DrvLowMotorSelectorEn selector_en, DrvLowMotorDirectionEn dir_en, uint16_t speed_u16)
{
	DrvLowStartMotor(selector_en, dir_en, speed_u16);
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
	DrvLowStopMotor(selector_en);
}
