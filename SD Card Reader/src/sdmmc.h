/*
 * sdmmc.h
 *
 *  Created on: Oct 31, 2018
 *      Author: routheauxke
 */

#ifndef SDMMC_H_
#define SDMMC_H_

/*
 * SDMMC Registers, found on page 1293 of the manual.
 */

//Full Addresses
//	SDMMC1
#define POWER		(volatile uint32_t*) 0x40012C00
#define CLKCR		(volatile uint32_t*) 0x40012C04
#define ARG			(volatile uint32_t*) 0x40012C08
#define CMD			(volatile uint32_t*) 0x40012C0C
#define RESPCMD		(volatile uint32_t*) 0x40012C10
#define RESP1		(volatile uint32_t*) 0x40012C14
#define RESP2		(volatile uint32_t*) 0x40012C18
#define RESP3		(volatile uint32_t*) 0x40012C1C
#define RESP4		(volatile uint32_t*) 0x40012C20
#define DTIMER		(volatile uint32_t*) 0x40012C24
#define DLEN		(volatile uint32_t*) 0x40012C28
#define DCTRL		(volatile uint32_t*) 0x40012C2C
#define DCOUNT		(volatile uint32_t*) 0x40012C30
#define STA			(volatile uint32_t*) 0x40012C34
#define ICR			(volatile uint32_t*) 0x40012C38
#define MASK		(volatile uint32_t*) 0x40012C3C
#define FIFOCNT		(volatile uint32_t*) 0x40012C48
#define FIFO		(volatile uint32_t*) 0x40012C80

//Register bit fields
//	SDMMCx_POWER
#define PWRCTRL		0 // [1:0]
//  SDMMCx_CLKCR
#define HWFC_EN		14
#define NEGEDGE		13
#define WIDBUS		11 // [1:0]
#define BYPASS		10
#define PWRSAV		9
#define CLKEN		8
#define CLKDIV		0 // [7:0]
//  SDMMCx_ARG
#define CMDARG		0 // [31:0]
//  SDMMCx_CMD
#define SDIO_SUS	11
#define CPSMEN		10
#define WAITPEND	9
#define WAITINT		8
#define WAITRESP	6 // [1:0]
#define CMDINDEX	0 // [5:0]
//  SDMMCx_RESPCMD
#define RESP_CMD	0 // [5:0]
//  SDMMCx_RESP1
#define CARDSTAT1	0 // [31:0]
//  SDMMCx_RESP2
#define CARDSTAT2	0 // [31:0]
//  SDMMCx_RESP3
#define CARDSTAT3	0 // [31:0]
//  SDMMCx_RESP4
#define CARDSTAT4	0 // [31:0]
//  SDMMCx_DTIMER
#define DATATIME	0 // [31:0]
//  SDMMCx_DLEN
#define DATALENGTH	0 // [24:0]
//  SDMMCx_DCTRL
#define SDIOEN		11
#define RWMOD		10
#define RWSTOP		9
#define RWSTART		8
#define DBLOCKSIZE	4 // [3:0]
#define DMAEN		3
#define DTMODE		2
#define DTDIR		1
#define DTEN		0
//  SDMMCx_DCOUNT
#define DATACOUNT	0 // [24:0]
//  SDMMCx_STA
#define SDIOIT		22
#define RXDAVL		21
#define TXDAVL		20
#define RXFIFOE		19
#define TXFIFOE		18
#define RXFIFOF		17
#define TXFIFOF		16
#define RXFIFOHF	15
#define TXFIFOHE	14
#define RXACT		13
#define TXACT		12
#define CMDACT		11
#define DBCKEND		10
#define DATAEND		8
#define	CMDSENT		7
#define CMDREND		6
#define RXOVERR		5
#define TXUNDERR	4
#define DTIMEOUT	3
#define CTIMEOUT	2
#define DCRCFAIL	1
#define CCRCFAIL	0
//  SDMMCx_ICR
#define SDIOITC		22
#define DBCKENDC	10
#define DATAENDC	8
#define CMDSENTC	7
#define CMDRENDC	6
#define RXOVERRC	5
#define TXUNDERRC	4
#define DTIMEOUTC	3
#define CTIMEOUTC	2
#define DCRCFAILC	1
#define CCRCFAILC	0
//  SDMMCx_MASK
#define SDIOITIE	22
#define RXDAVLIE	21
#define TXDAVLIE	20
#define RXFIFOEIE	19
#define TXFIFOEIE	18
#define RXFIFOFIE	17
#define TXFIFOFIE	16
#define RXFIFOHFIE	15
#define TXFIFOHEIE	14
#define RXACTIE		13
#define TXACTIE		12
#define CMDACTIE	11
#define DBCKENDIE	10
#define DATAENDIE	8
#define	CMDSENTIE	7
#define CMDRENDIE	6
#define RXOVERRIE	5
#define TXUNDERRIE	4
#define DTIMEOUTIE	3
#define CTIMEOUTIE	2
#define DCRCFAILIE	1
#define CCRCFAILIE	0
//  SDMMCx_FIFOCNT
#define FIFOCOUNT	0 // [23:0]
//  SDMMCx_FIFO
#define FIFODATA	0 // [31:0]


#endif /* SDMMC_H_ */
