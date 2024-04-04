/**
 * @file
 *
 * @brief		Scheduler to test motor control driver.
 *
 */

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "motor_driver.h"
#include "stm32f1xx_hal.h"
/******************************************************************************
 * Module Global Variables
 ******************************************************************************/
static uint16_t speed_gu16 = 10u;

/******************************************************************************
 * Extern Function Definitions
 ******************************************************************************/

extern void SdlMotorDriverInit(void)
{
	MotorDriverInit();
}

extern void SdlMotorDriverRun(void)
{
	MotorDriverStartMotor();

	if(speed_gu16 != 0u)
	{
		DrvLowMotorMoveForward(speed_gu16);
		HAL_Delay(1000uL);
		MotorDriverMoveBackward(speed_gu16);

		speed_gu16 += 10u;
	}
}

/******************************************************************************
 * Callback Function Definitions
 ******************************************************************************/
