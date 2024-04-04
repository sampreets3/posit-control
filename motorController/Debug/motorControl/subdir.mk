################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../motorControl/motor_driver.c 

OBJS += \
./motorControl/motor_driver.o 

C_DEPS += \
./motorControl/motor_driver.d 


# Each subdirectory must supply rules for building sources it contributes
motorControl/%.o motorControl/%.su motorControl/%.cyclo: ../motorControl/%.c motorControl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/Users/aniket/STM32CubeIDE/workspace_1.14.0/PositMotorController/motorControl" -I"/Users/aniket/STM32CubeIDE/workspace_1.14.0/PositMotorController/drv_low" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-motorControl

clean-motorControl:
	-$(RM) ./motorControl/motor_driver.cyclo ./motorControl/motor_driver.d ./motorControl/motor_driver.o ./motorControl/motor_driver.su

.PHONY: clean-motorControl

