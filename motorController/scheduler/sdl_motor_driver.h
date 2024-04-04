/**
 * @file
 *
 * @brief		Scheduler to test motor control driver.
 *
 */

#ifndef SDL_MOTOR_DRIVER_H_
#define SDL_MOTOR_DRIVER_H_

/******************************************************************************
 * Include Header Files
 ******************************************************************************/

/******************************************************************************
 * Static Function Declarations
 ******************************************************************************/

/******************************************************************************
 * Extern Function Definitions
 ******************************************************************************/
/**
 * @brief   Test scheduler init.
 *
 * @return  None
 */
extern void SdlMotorDriverInit(void);

/**
 * @brief   Test scheduler run.
 *
 * @return  None
 */
extern void SdlMotorDriverRun(void);

#endif /* SDL_MOTOR_DRIVER_H_ */
