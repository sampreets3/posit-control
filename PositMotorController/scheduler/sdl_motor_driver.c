/**
 * @file
 *
 * @brief		Scheduler to test motor control driver.
 *
 */

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "stdbool.h"
#include "motor_driver.h"
#include "stm32f1xx_hal.h"

/******************************************************************************
 * Module Global Variables
 ******************************************************************************/
static uint16_t speed_gu16 = 0u;
static bool flag_b = false;

/******************************************************************************
 * Extern Function Definitions
 ******************************************************************************/

extern void SdlMotorDriverInit(void)
{
	MotorDriverInit();
}

extern void SdlMotorDriverRun(void)
{
	if(flag_b == false)
	{
		MotorDriverStartMotor(DRV_LOW_RIGHT_MOTOR, DRV_LOW_DIR_FW, 10u);
		MotorDriverStartMotor(DRV_LOW_RIGHT_MOTOR, DRV_LOW_DIR_REV, 10u);
		MotorDriverStartMotor(DRV_LOW_LEFT_MOTOR, DRV_LOW_DIR_FW, 10u);
		MotorDriverStartMotor(DRV_LOW_LEFT_MOTOR, DRV_LOW_DIR_REV, 10u);

		flag_b = true;
	}

	while(speed_gu16 != 80u)
	{
		MotorDriverMoveForward(speed_gu16);
		HAL_Delay(1000uL);
		MotorDriverMoveBackward(speed_gu16);

		speed_gu16 += 10u;
	}

	speed_gu16 = 0u;
}

/******************************************************************************
 * Callback Function Definitions
 ******************************************************************************/
