/*
 * EEPROM_interface.h
 *
 *  Created on: Jan 3, 2024
 *      Author: Shada122
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


/*
Function Name        : EEPROM_write
Function Returns     : void
Function Arguments   : unsigned short address, unsigned char data
Function Description :  write one byte to the given  address.
*/
void EEPROM_write(unsigned short address, unsigned char data );
/*
Function Name        : EEPROM_read
Function Returns     : unsigned char
Function Arguments   :  unsigned short address
Function Description :  read one byte from the given  address.
*/
unsigned char EEPROM_read( unsigned short address );

#endif /* EEPROM_INTERFACE_H_ */
