/*
 * spi.c
 *
 *  Created on: Nov 29, 2018
 *      Author: routheauxke
 */

#include "spi.h"

void spiConfig()
{
	//Write proper GPIO registers: Configure GPIO for MOSI, MISO and SCK pins.

	//Write to the SPI_CR1 register:
		//Configure the serial clock baud rate using the BR[2:0] bits
		//	(Note: 4).

		//Configure the CPOL and CPHA bits combination to define one
		//	of the four relationships between the data transfer and the
		//	serial clock (CPHA must be cleared in NSSP mode).
		//	(Note: 2 - except the case when CRC is enabled at TI mode).

		//Select simplex or half-duplex mode by configuring RXONLY or
		//	BIDIMODE and BIDIOE (RXONLY and BIDIMODE can't be set at the
		//	same time).

		//Configure the LSBFIRST bit to define the frame format (Note: 2).

		//Configure the CRCL and CRCEN bits if CRC is needed (while
		//	SCK clock signal is at idle state).

		//Configure SSM and SSI (Notes: 2 & 3).

		//Configure the MSTR bit (in multimaster NSS configuration,
		//	avoid conflict state on

		//NSS if master is configured to prevent MODF error).

	//Write to SPI_CR2 register:
		//Configure the DS[3:0] bits to select the data length for the
		//	transfer.

		//Configure SSOE (Notes: 1 & 2 & 3).

		//Set the FRF bit if the TI protocol is required (keep NSSP
		//	bit cleared in TI mode).

		//Set the NSSP bit if the NSS pulse mode between two data units
		//	is required (keep CHPA and TI bits cleared in NSSP mode).

		//Configure the FRXTH bit. The RXFIFO threshold must be aligned
		//	to the read access size for the SPIx_DR register.

		//Initialize LDMA_TX and LDMA_RX bits if DMA is used in packed
		//	mode.

	//Write to SPI_CRCPR register: Configure the CRC polynomial if
	//	needed.

	//Write proper DMA registers: Configure DMA streams dedicated for
	//	SPI Tx and Rx in DMA registers if the DMA streams are used.

/*
	Note:
	Step is not required in slave mode.
	Step is not required in TI mode.
	Step is not required in NSSP mode.
	Step is not required in slave mode except slave working at TI mode
*/
}

//Returns 0 when successful
//Returns 1 when slave register did not have data to transmit.
int spiEnable()
{
	int retval = 0;

	//The slave data register must already have data ready to transmit.

	//SCK must be idle corresponding to selected polarity.

	//Enable SPI slave before the master sends the clock.

	//If master is full-duplex or transmit-only, the next write to
	//	TXFIFO will trigger master communication. Otherwise, master will
	//	communicate after SPI is enabled.

}

void spiDisable()
{
	//Does NOT check for data packing usage.

	//If in receive-only mode, for either half-duplex or simplex:
	if((SPI1_CR1[BIDIMODE] == HALFDUPLEX && SPI1_CR1[BIDIOE] == RECEIVEONLYHALFDUPLEX)
		|| (SPI1_CR1[BIDIMODE] == FULLDUPLEX && SPI1_CR1[RXONLY] == SIMPLEXRECEIVE))
	{
		//Clear SPE when the last frame is ongoing
		//TODO Find out how to determine if a frame is the last frame.

		//Wait until BSY = 0 (indicates last frame is processed)


		//Read data until FRLVL = 00 (indicates all received data is read)

	//Otherwise
	}else{

		//Wait until FTLVL = 00 (indicates there is no data to transmit)

		//Wait until BSY = 0 (indicates the last frame is processed)

		//Clear SPE

		//Read data until FRLVL = 00 (indicates all received data has
		//	been read)
	}
}

//TODO Interrupt triggered by RXNE, when data is stored in RXFIFO and
//	crosses FRXTH threshold.
//Returns 16-bit value
uint16_t readAccess(){

}

//TODO Interrupt triggered by TXE, when TXFIFO is half full or less.
void writeAccess(){
	//Data is pulled from
}

//Returns
uint32_t getInfo(){

}

