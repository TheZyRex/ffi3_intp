################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Display/Src/_mcpr_aufgabe3.c \
../Drivers/Display/Src/mcpr_timer.c 

OBJS += \
./Drivers/Display/Src/_mcpr_aufgabe3.o \
./Drivers/Display/Src/mcpr_timer.o 

C_DEPS += \
./Drivers/Display/Src/_mcpr_aufgabe3.d \
./Drivers/Display/Src/mcpr_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Display/Src/%.o Drivers/Display/Src/%.su Drivers/Display/Src/%.cyclo: ../Drivers/Display/Src/%.c Drivers/Display/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Drivers/Display/Inc -I../Core/Inc -I../USB_HOST/App -I../USB_HOST/Target -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Display-2f-Src

clean-Drivers-2f-Display-2f-Src:
	-$(RM) ./Drivers/Display/Src/_mcpr_aufgabe3.cyclo ./Drivers/Display/Src/_mcpr_aufgabe3.d ./Drivers/Display/Src/_mcpr_aufgabe3.o ./Drivers/Display/Src/_mcpr_aufgabe3.su ./Drivers/Display/Src/mcpr_timer.cyclo ./Drivers/Display/Src/mcpr_timer.d ./Drivers/Display/Src/mcpr_timer.o ./Drivers/Display/Src/mcpr_timer.su

.PHONY: clean-Drivers-2f-Display-2f-Src

