/*
 * spi.h
 *
 *  Created on: Oct 30, 2018
 *      Author: routheauxke
 */

#ifndef SPI_H_
#define SPI_H_

/*
 * SPI and I2S registers, found on page 1146 of the manual
 *
 * The peripheral registers can be accessed by half-words
 * (16-bit) or words (32-bit). SPI_DR in addition can be
 * accessed by 8-bit access.
 */

//Full Addresses
//	SPI 1
#define SPI1_CR1	(volatile uint32_t*) 0x40013000
#define SPI1_CR2	(volatile uint32_t*) 0x40013004
#define SPI1_SR		(volatile uint32_t*) 0x40013008
#define SPI1_DR		(volatile uint32_t*) 0x4001300C
#define SPI1_CRCPR	(volatile uint32_t*) 0x40013010
#define SPI1_RXCRCR	(volatile uint32_t*) 0x40013014
#define SPI1_TXCRCR	(volatile uint32_t*) 0x40013018
#define SPI1I2SCFGR	(volatile uint32_t*) 0x4001301C
#define SPI1_I2SPR	(volatile uint32_t*) 0x40013020
//	SPI 2
#define SPI2_CR1	(volatile uint32_t*) 0x40003800
#define SPI2_CR2	(volatile uint32_t*) 0x40003804
#define SPI2_SR		(volatile uint32_t*) 0x40003808
#define SPI2_DR		(volatile uint32_t*) 0x4000380C
#define SPI2_CRCPR	(volatile uint32_t*) 0x40003810
#define SPI2_RXCRCR	(volatile uint32_t*) 0x40003814
#define SPI2_TXCRCR	(volatile uint32_t*) 0x40003818
#define SPI2I2SCFGR	(volatile uint32_t*) 0x4000381C
#define SPI2_I2SPR	(volatile uint32_t*) 0x40003820
//	SPI 3
#define SPI3_CR1	(volatile uint32_t*) 0x40003C00
#define SPI3_CR2	(volatile uint32_t*) 0x40003C04
#define SPI3_SR		(volatile uint32_t*) 0x40003C08
#define SPI3_DR		(volatile uint32_t*) 0x40003C0C
#define SPI3_CRCPR	(volatile uint32_t*) 0x40003C10
#define SPI3_RXCRCR	(volatile uint32_t*) 0x40003C14
#define SPI3_TXCRCR	(volatile uint32_t*) 0x40003C18
#define SPI3I2SCFGR	(volatile uint32_t*) 0x40003C1C
#define SPI3_I2SPR	(volatile uint32_t*) 0x40003C20
//	SPI 4
#define SPI4_CR1	(volatile uint32_t*) 0x40013400
#define SPI4_CR2	(volatile uint32_t*) 0x40013404
#define SPI4_SR		(volatile uint32_t*) 0x40013408
#define SPI4_DR		(volatile uint32_t*) 0x4001340C
#define SPI4_CRCPR	(volatile uint32_t*) 0x40013410
#define SPI4_RXCRCR	(volatile uint32_t*) 0x40013414
#define SPI4_TXCRCR	(volatile uint32_t*) 0x40013418
#define SPI4I2SCFGR	(volatile uint32_t*) 0x4001341C
#define SPI4_I2SPR	(volatile uint32_t*) 0x40013420
//	SPI 5
#define SPI5_CR1	(volatile uint32_t*) 0x40015000
#define SPI5_CR2	(volatile uint32_t*) 0x40015004
#define SPI5_SR		(volatile uint32_t*) 0x40015008
#define SPI5_DR		(volatile uint32_t*) 0x4001500C
#define SPI5_CRCPR	(volatile uint32_t*) 0x40015010
#define SPI5_RXCRCR	(volatile uint32_t*) 0x40015014
#define SPI5_TXCRCR	(volatile uint32_t*) 0x40015018
#define SPI5I2SCFGR	(volatile uint32_t*) 0x4001501C
#define SPI5_I2SPR	(volatile uint32_t*) 0x40015020
//	SPI 6
#define SPI6_CR1	(volatile uint32_t*) 0x40015400
#define SPI6_CR2	(volatile uint32_t*) 0x40015404
#define SPI6_SR		(volatile uint32_t*) 0x40015408
#define SPI6_DR		(volatile uint32_t*) 0x4001540C
#define SPI6_CRCPR	(volatile uint32_t*) 0x40015410
#define SPI6_RXCRCR	(volatile uint32_t*) 0x40015414
#define SPI6_TXCRCR	(volatile uint32_t*) 0x40015418
#define SPI6I2SCFGR	(volatile uint32_t*) 0x4001541C
#define SPI6_I2SPR	(volatile uint32_t*) 0x40015420

//Register bit fields
//	SPIx_CR1 control register 1
#define BIDIMODE	15// Enable half-duplex
#define 	FULLDUPLEX 0
#define		HALFDUPLEX 1
#define BIDIOE		14// Receive or transmit only, half-duplex only
#define		TRANSMITONLYHALFDUPLEX 0
#define		RECEIVEONLYHALFDUPLEX  1
#define CRCEN		13// Enable CRC calculations
#define CRCNEXT		12// Send CRC (must be done right after write)
#define CRCL		11// CRC length (0 = 8-bit)(1 = 16-bit)
#define RXONLY		10// Receive-only (0 = full-duplex)
#define		SIMPLEXRECEIVE 1
#define SSM			9 // Replace NSS input with SSI
#define SSI			8 // Internal slave select
#define LSBFIRST	7 // Frame format (0 = MSB first)(1 = LSB first)
#define SPE			6 // SPI enable
#define BR			3 // [2:0] Baud rate (PCLK / 2^(1+ this value))
#define MSTR		2 // Enable master mode
#define CPOL		1 // Clock polarity
#define CPHA		0 // Clock phase (0 = first transition)(1 = second)
//	SPIx_CR2 control register 2
#define LDMA_TX		14// Num data frames in TXFIFO (0 = even)(1 = odd)
#define LDMA_RX		13// Num data frames in RXFIFO (0 = even)(1 = odd)
#define FRXTH		12// Set threshold for RXFIFO
#define DS			8 // [3:0] Data frame size for SPI transfer(0011=4)
#define TXEIE		7 // Enable write access interrupts
#define RXNEIE		6 // Enable read access interrupts
#define ERRIE		5 // Enable error interrupts
#define FRF			4 // Frame format (0 = Motorola)(1 = TI)
#define NSSP		3 // Enable NSS pulse
#define SSOE		2 // Enable SS output
#define TXDMAEN		1 // Enable DMA for Tx
#define RXDMAEN		0 // Enable DMA for Rx
//	SPIx_SR status register
#define FTLVL		11// [1:0] TXFIFO occupancy level(0,1/4,1/2,1)
#define FRLVL		9 // [1:0] RXFIFO occupancy level(0,1/4,1/2,1)
#define FRE			8 // Frame format error flag
#define BSY			7 // Busy flag (hardware only)
#define OVR			6 // Overrun error flag
#define MODF		5 // Mode fault flag
#define CRCERR		4 // CRC error flag
#define UDR			3 // Underrun error flag (Not used for SPI)
#define CHSIDE		2 // Channel side(Not used for SPI)
#define TXE			1 // Tx buffer empty flag
#define RXNE		0 // Rx buffer empty flag
//	SPIx_DR
#define DR			0 // [15:0] Data register for read or write values.
//	SPIx_CRCPR
#define CRCPOLY		0 // [15:0] CRC polynomial (Default is 0x0007)
//	SPIx_RXCRCR
#define RXCRC		0 // [15:0] Rx CRC calculation
//	SPIx_TXCRCR
#define TXCRC		0 // [15:0] Tx CRC calculation
//  SPIx_I2SCFGR
#define ASTRTEN		12// Enable asynchronous start
#define I2SMOD		11// Select I2S mode (0=SPI)(1=I2S)
#define I2SE		10// Enable I2S (Not used for SPI)
#define I2SCFG		8 // [1:0] I2S config (Not used for SPI)
#define PCMSYNC		7 // PCM frame (Not used for SPI)
#define I2SSTD		4 // [1:0] (Not used for SPI)
#define CKPOL		3 // (Not used for SPI)
#define DATLEN		1 // [1:0] (Not used for SPI)
#define CHLEN		0 // (Not used for SPI)
//	SPIx_I2SPR
#define MCKOE		9 // (Not used for SPI)
#define ODD			8 // (Not used for SPI)
#define I2SDIV		0 // [7:0] (Not used for SPI)


#endif /* SPI_H_ */
