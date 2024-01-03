/*
 * EEPROM_prog.c
 *
 *  Created on: Jan 3, 2024
 *      Author: Shada122
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"

void EEPROM_write(unsigned short address, unsigned char data ){

		EEARL=(char)address;
		EEARH=(char)(address>>8);
		/*set up data register*/
		EEDR=data;
		/*write logical one to EEMWE*/
		SET_BIT(EECR, EECR_EEMWE);
		/*start EEPROM write by setting EEWE*/
		SET_BIT(EECR,EECR_EEWE);
		/* wait for completion of write operation*/
		while(GET_BIT(EECR,EECR_EEWE)==1);
}

unsigned char EEPROM_read( unsigned short address ){
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	/*start EEPROM read by setting EERE*/
	SET_BIT(EECR,EECR_EERE);
	/*return data from data register*/
	return EEDR ;
}
