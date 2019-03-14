################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/bsp_driver_sd.c \
../Src/dma.c \
../Src/fatfs.c \
../Src/fatfs_platform.c \
../Src/gpio.c \
../Src/main.c \
../Src/sd_diskio.c \
../Src/sdmmc.c \
../Src/spi.c \
../Src/stm32f7xx_hal_msp.c \
../Src/stm32f7xx_it.c \
../Src/system_stm32f7xx.c 

OBJS += \
./Src/bsp_driver_sd.o \
./Src/dma.o \
./Src/fatfs.o \
./Src/fatfs_platform.o \
./Src/gpio.o \
./Src/main.o \
./Src/sd_diskio.o \
./Src/sdmmc.o \
./Src/spi.o \
./Src/stm32f7xx_hal_msp.o \
./Src/stm32f7xx_it.o \
./Src/system_stm32f7xx.o 

C_DEPS += \
./Src/bsp_driver_sd.d \
./Src/dma.d \
./Src/fatfs.d \
./Src/fatfs_platform.d \
./Src/gpio.d \
./Src/main.d \
./Src/sd_diskio.d \
./Src/sdmmc.d \
./Src/spi.d \
./Src/stm32f7xx_hal_msp.d \
./Src/stm32f7xx_it.d \
./Src/system_stm32f7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Inc" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Middlewares/Third_Party/FatFs/src" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/routheauxke/Documents/College1718/CE3101/workspacy/stm32spi/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


