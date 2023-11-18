/*
 * posit_hal.c
 *
 *  Created on: Nov 14, 2023
 *      Author: user
 */

#include "posit_hal.h"
#include "string.h"

void demoFunction(void)
{
	uint8_t response_u8 = 255;
}


uint16_t TransmitDataFrame(char* buffer)
{
	/* Determine the length of the buffer */
	uint16_t bufLen = strlen(buffer);

	/* Transmit the data-frame through the USB */
	uint16_t dataLen = (uint16_t)(CDC_Transmit_FS((uint8_t *)buffer, (uint8_t)strlen(buffer)));

	/* Compare the buffer length with the received buffer length */

	return dataLen;
}
