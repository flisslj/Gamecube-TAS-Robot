/*
 * gpio.h
 *
 *  Created on: Oct 31, 2018
 *      Author: routheauxke
 */

#ifndef GPIO_H_
#define GPIO_H_


/*
 * GPIO stuff, found on page 70 of the manual
 */

#define QuadSPI_CR	(volatile uint32_t*) 0xA0001000
#define FMC_CR		(volatile uint32_t*) 0xA0000000
#define RNG			(volatile uint32_t*) 0x50060800
#define HASH		(volatile uint32_t*) 0x50060400
#define CRYP		(volatile uint32_t*) 0x50060000
#define DCMI		(volatile uint32_t*) 0x50050000
#define USB_OTG_FS	(volatile uint32_t*) 0x50000000
#define USB_OTG_HS	(volatile uint32_t*) 0x40040000
#define DMA2D		(volatile uint32_t*) 0x4002B000
#define ETH_MAC		(volatile uint32_t*) 0x40028000
#define DMA2		(volatile uint32_t*) 0x40026400
#define DMA1		(volatile uint32_t*) 0x40026000
#define BKPSRAM		(volatile uint32_t*) 0x40024000
#define FIR			(volatile uint32_t*) 0x40023C00
#define RCC			(volatile uint32_t*) 0x40023800
#define CRC			(volatile uint32_t*) 0x40023000
#define GPIOK		(volatile uint32_t*) 0x40022800
#define GPIOJ		(volatile uint32_t*) 0x40022400
#define GPIOI		(volatile uint32_t*) 0x40022000
#define GPIOH		(volatile uint32_t*) 0x40021C00
#define GPIOG		(volatile uint32_t*) 0x40021800
#define GPIOF		(volatile uint32_t*) 0x40021400
#define GPIOE		(volatile uint32_t*) 0x40021000
#define GPIOD		(volatile uint32_t*) 0x40020C00
#define GPIOC		(volatile uint32_t*) 0x40020800
#define GPIOB		(volatile uint32_t*) 0x40020400
#define GPIOA		(volatile uint32_t*) 0x40020000
#define LCD_TFT		(volatile uint32_t*) 0x40016800
#define SAI2		(volatile uint32_t*) 0x40015C00
#define SAI1		(volatile uint32_t*) 0x40015800
#define SPI6		(volatile uint32_t*) 0x40015400
#define SPI5		(volatile uint32_t*) 0x40015000
#define TIM11		(volatile uint32_t*) 0x40014800
#define TIM10		(volatile uint32_t*) 0x40014400
#define TIM9		(volatile uint32_t*) 0x40014000
#define EXTI		(volatile uint32_t*) 0x40013C00
#define SYSCFG		(volatile uint32_t*) 0x40013800
#define SPI4		(volatile uint32_t*) 0x40013400
#define SPI1		(volatile uint32_t*) 0x40013000
#define SDMMC1		(volatile uint32_t*) 0x40012C00
#define ADC123		(volatile uint32_t*) 0x40012000
#define USART6		(volatile uint32_t*) 0x40011400
#define USART1		(volatile uint32_t*) 0x40011000
#define TIM8		(volatile uint32_t*) 0x40010400
#define TIM1		(volatile uint32_t*) 0x40010000
#define UART8		(volatile uint32_t*) 0x40007C00
#define UART7		(volatile uint32_t*) 0x40007800
#define DAC			(volatile uint32_t*) 0x40007400
#define PWR			(volatile uint32_t*) 0x40007000
#define HDMI-CEC	(volatile uint32_t*) 0x40006C00
#define CAN2		(volatile uint32_t*) 0x40006800
#define CAN1		(volatile uint32_t*) 0x40006400
#define I2C4		(volatile uint32_t*) 0x40006000
#define I2C3		(volatile uint32_t*) 0x40005C00
#define I2C2		(volatile uint32_t*) 0x40005800
#define I2C1		(volatile uint32_t*) 0x40005400
#define UART5		(volatile uint32_t*) 0x40005000
#define UART4		(volatile uint32_t*) 0x40004C00
#define USART3		(volatile uint32_t*) 0x40004800
#define USART2		(volatile uint32_t*) 0x40004400
#define SPDIFRX		(volatile uint32_t*) 0x40004000
#define SPI3		(volatile uint32_t*) 0x40003C00
#define SPI2		(volatile uint32_t*) 0x40003800
#define IWDG		(volatile uint32_t*) 0x40003000
#define WWDG		(volatile uint32_t*) 0x40002C00
#define RTC_BKP		(volatile uint32_t*) 0x40002800
#define LPTIM1		(volatile uint32_t*) 0x40002400
#define TIM14		(volatile uint32_t*) 0x40002000
#define TIM13		(volatile uint32_t*) 0x40001C00
#define TIM12		(volatile uint32_t*) 0x40001800
#define TIM7		(volatile uint32_t*) 0x40001400
#define TIM6		(volatile uint32_t*) 0x40001000
#define TIM5		(volatile uint32_t*) 0x40000C00
#define TIM4		(volatile uint32_t*) 0x40000800
#define TIM3		(volatile uint32_t*) 0x40000400
#define TIM2		(volatile uint32_t*) 0x40000000


#endif /* GPIO_H_ */
