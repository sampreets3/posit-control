/**
 * @file
 *
 * @brief		Low level driver for motor controller.
 *
 */

/******************************************************************************
 * Include Header Files
 ******************************************************************************/
#include "drv8874.h"

#include "stm32f1xx_hal.h"
#include "tim.h"

/******************************************************************************
 * Macro Constant Declarations
 ******************************************************************************/
#define DRV_LOW_RIGHT_MOTOR_PIN_1		GPIO_PIN_7
#define DRV_LOW_RIGHT_MOTOR_PIN_2		GPIO_PIN_6
#define DRV_LOW_LEFT_MOTOR_PIN_1		GPIO_PIN_2
#define DRV_LOW_LEFT_MOTOR_PIN_2		GPIO_PIN_3

#define DRV_LOW_BRAKE_DUTY_CYCLE		1u

/******************************************************************************
 * Extern Function Definitions
 ******************************************************************************/

extern void DrvLowInitController(void)
{
    GPIO_InitTypeDef GPIO_InitStructA = {0};
    GPIO_InitTypeDef GPIO_InitStructB = {0};

    /* Initialise GPIO pins for PWM of M1 */
    GPIO_InitStructA.Pin   = DRV_LOW_LEFT_MOTOR_PIN_1  | DRV_LOW_LEFT_MOTOR_PIN_2;
    GPIO_InitStructA.Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructA.Pull  = GPIO_NOPULL;
    GPIO_InitStructA.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStructA);

    /* Initialise GPIO pins for PWM of M2 */
    GPIO_InitStructB.Pin   = DRV_LOW_RIGHT_MOTOR_PIN_1 | DRV_LOW_RIGHT_MOTOR_PIN_2;
    GPIO_InitStructB.Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStructB.Pull  = GPIO_NOPULL;
    GPIO_InitStructB.Speed = GPIO_SPEED_FREQ_HIGH;

    HAL_GPIO_Init(GPIOB, &GPIO_InitStructB);

    DrvLowStopMotor(DRV_LOW_RIGHT_MOTOR);
    DrvLowStopMotor(DRV_LOW_LEFT_MOTOR);
}



extern void DrvLowStartMotor(DrvLowMotorSelectorEn selector_en, DrvLowMotorDirectionEn dir_en, uint16_t speed_u16)
{
	if(selector_en == DRV_LOW_RIGHT_MOTOR)
	{
		if(dir_en == DRV_LOW_DIR_FW)
		{
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, speed_u16);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0u);
		}
		else
		{
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0u);
			__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, speed_u16);
		}
	}
	else if(selector_en == DRV_LOW_LEFT_MOTOR)
	{
		if(dir_en == DRV_LOW_DIR_FW)
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, speed_u16);
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0u);
		}
		else
		{
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0u);
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, speed_u16);
		}
	}
	else
	{
		/* Do nothing */
	}
}


extern void DrvLowMotorMoveForward(DrvLowMotorSelectorEn selector_en, uint16_t speed_u16)
{
	if(selector_en == DRV_LOW_RIGHT_MOTOR)
	{
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, speed_u16);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, 0u);
	}
	else if(selector_en == DRV_LOW_LEFT_MOTOR)
	{
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, speed_u16);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0u);
	}
	else
	{
		/* Do nothing */
	}
}


extern void DrvLowMotorMoveReverse(DrvLowMotorSelectorEn selector_en, uint16_t speed_u16)
{
	if(selector_en == DRV_LOW_RIGHT_MOTOR)
	{
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0u);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, speed_u16);
	}
	else if(selector_en == DRV_LOW_LEFT_MOTOR)
	{
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, 0u);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, speed_u16);
	}
	else
	{
		/* Do nothing */
	}
}


extern void DrvLowStopStopMotor(DrvLowMotorSelectorEn selector_en)
{
	if(selector_en == DRV_LOW_RIGHT_MOTOR)
	{
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, DRV_LOW_BRAKE_DUTY_CYCLE);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, DRV_LOW_BRAKE_DUTY_CYCLE);
	}
	else if(selector_en == DRV_LOW_LEFT_MOTOR)
	{
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, DRV_LOW_BRAKE_DUTY_CYCLE);
		__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, DRV_LOW_BRAKE_DUTY_CYCLE);
	}
	else
	{
		/* Do nothing */
	}
}

