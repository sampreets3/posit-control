#ifndef __POSIT_HAL_H__
#define __POSIT_HAL_H__

#include "stdint.h"
#include "stdio.h"
#include "stm32f1xx.h"

/**
 * Defined Macros
 */

typedef struct
{
	int countsPerRevolution;	/* Stores the counts per revolution for the given encoder. */
	int encoderValue;	/* Stores the raw encoder value. */
	float angle;							/* Stores the equivalent motor angle [rad]. */
	float velocity;							/* Integrates the angle over time to get the velocity of the motor [rad/s] */
} MotorState;



void demoFunction(void);

/**
 * @brief Transmits a Data frame over the USB FS Virtual COM Port.
 *
 * @param  buffer The data-frame to be transmitted.
 *
 * @return txLen  The length of the transmitted buffer.
 */

uint16_t TransmitDataFrame(char* buffer);

/**
 * @brief Receives a Data frame from the USB_FS Virtual COM Port.
 *
 * @return rxBuf   The received data-frame from the USB Host.
 */
char* ReceiveDataFrame(void);

#endif
