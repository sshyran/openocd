/***************************************************************************
 *   Copyright (C) 2006 by Magnus Lundin                                   *
 *   lundin@mlu.mine.nu                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef STELLARIS_FLASH_H
#define STELLARIS_FLASH_H

#include "flash.h"

typedef struct stellaris_flash_bank_s
{
	/* chip id register */
	uint32_t did0;
	uint32_t did1;
	uint32_t dc0;
	uint32_t dc1;

	char * target_name;

	uint32_t sramsiz;
	uint32_t flshsz;
	/* flash geometry */
	uint32_t num_pages;
	uint32_t pagesize;
	uint32_t pages_in_lockregion;

	/* nv memory bits */
	uint16_t num_lockbits;
	uint32_t lockbits;

	/* main clock status */
	uint32_t rcc;
	uint8_t  mck_valid;
	uint32_t mck_freq;
} stellaris_flash_bank_t;

/* STELLARIS control registers */
#define SCB_BASE	0x400FE000
#define	DID0		0x000
#define	DID1		0x004
#define	DC0			0x008
#define	DC1			0x010
#define	DC2			0x014
#define	DC3			0x018
#define	DC4			0x01C

#define	RIS			0x050
#define	RCC			0x060
#define	PLLCFG		0x064

#define FMPRE		0x130
#define FMPPE		0x134
#define USECRL		0x140

#define FLASH_CONTROL_BASE	0x400FD000
#define FLASH_FMA	(FLASH_CONTROL_BASE | 0x000)
#define FLASH_FMD	(FLASH_CONTROL_BASE | 0x004)
#define FLASH_FMC	(FLASH_CONTROL_BASE | 0x008)
#define FLASH_CRIS	(FLASH_CONTROL_BASE | 0x00C)
#define FLASH_CIM	(FLASH_CONTROL_BASE | 0x010)
#define FLASH_MISC	(FLASH_CONTROL_BASE | 0x014)

#define AMISC	1
#define PMISC	2

#define AMASK	1
#define PMASK	2

/* Flash Controller Command bits */
#define FMC_WRKEY	(0xA442 << 16)
#define FMC_COMT	(1 << 3)
#define FMC_MERASE	(1 << 2)
#define FMC_ERASE	(1 << 1)
#define FMC_WRITE	(1 << 0)

/* STELLARIS constants */

#endif /* STELLARIS_H */
