################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drv_low/drv_low.c 

OBJS += \
./drv_low/drv_low.o 

C_DEPS += \
./drv_low/drv_low.d 


# Each subdirectory must supply rules for building sources it contributes
drv_low/%.o drv_low/%.su drv_low/%.cyclo: ../drv_low/%.c drv_low/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/Users/aniket/STM32CubeIDE/workspace_1.14.0/PositMotorController/motorControl" -I"/Users/aniket/STM32CubeIDE/workspace_1.14.0/PositMotorController/drv_low" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drv_low

clean-drv_low:
	-$(RM) ./drv_low/drv_low.cyclo ./drv_low/drv_low.d ./drv_low/drv_low.o ./drv_low/drv_low.su

.PHONY: clean-drv_low

