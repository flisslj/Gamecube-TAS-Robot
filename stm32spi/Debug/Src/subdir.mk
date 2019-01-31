################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/crc.c \
../Src/dma.c \
../Src/gpio.c \
../Src/main.c \
../Src/spi.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_it.c \
../Src/system_stm32f7xx.c 

OBJS += \
./Src/crc.o \
./Src/dma.o \
./Src/gpio.o \
./Src/main.o \
./Src/spi.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_it.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/crc.d \
./Src/dma.d \
./Src/gpio.d \
./Src/main.d \
./Src/spi.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_it.d \
./Src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Inc" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/CMSIS/Include"  -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


