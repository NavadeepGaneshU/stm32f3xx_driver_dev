################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/stm32f303xx_gpio_driver.c \
../drivers/src/stm32f303xx_spi_driver.c 

OBJS += \
./drivers/src/stm32f303xx_gpio_driver.o \
./drivers/src/stm32f303xx_spi_driver.o 

C_DEPS += \
./drivers/src/stm32f303xx_gpio_driver.d \
./drivers/src/stm32f303xx_spi_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F3 -DSTM32F303RETx -DNUCLEO_F303RE -c -I../Inc -I"C:/Users/Navadeep/OneDrive/Documents/EmbDev/stm32f3xx_drivers/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

