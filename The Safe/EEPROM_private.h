/*
 * EEPROM_private.h
 *
 *  Created on: Jan 3, 2024
 *      Author: Shada122
 */

#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEARL 		 *((volatile u8*)0x3F)
#define EEARH 		 *((volatile u8*)0x3E)
#define EEDR  		 *((volatile u8*)0x3D)
#define EECR         *((volatile u8*)0x3C)
#define EECR_EEMWE			2
#define EECR_EEWE			1
#define EECR_EERE			0

#endif /* EEPROM_PRIVATE_H_ */
