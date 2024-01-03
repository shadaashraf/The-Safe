/*
 * DIO_prog.c

 *
 *  Created on: Dec 10, 2023
 *      Author: Doaa Rageh
 */


/* lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* lower layer */

/* DIO */
#include "DIO_int.h"
#include "DIO_private.h"
#include "DIO_config.h"


void MDIO_vSetPinDir(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Dir)
{
	if(copy_u8Dir == INPUT)
	{
		switch(copy_u8Port)
		{
		case DIO_PORTA:
			CLR_BIT(DDRA, copy_u8Pin);
			break;
		case DIO_PORTB:
			CLR_BIT(DDRB, copy_u8Pin);
			break;
		case DIO_PORTC:
			CLR_BIT(DDRC, copy_u8Pin);
			break;
		case DIO_PORTD:
			CLR_BIT(DDRD, copy_u8Pin);
			break;
		}
	}
	else if(copy_u8Dir == OUTPUT)
	{
		switch(copy_u8Port)
		{
		case DIO_PORTA:
			SER_BIT(DDRA, copy_u8Pin);
			break;
		case DIO_PORTB:
			SER_BIT(DDRB, copy_u8Pin);
			break;
		case DIO_PORTC:
			SER_BIT(DDRC, copy_u8Pin);
			break;
		case DIO_PORTD:
			SER_BIT(DDRD, copy_u8Pin);
			break;
		}
	}
}

void MDIO_vSetPinVal(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Val)
{
	if(copy_u8Val == LOW)
	{
		switch(copy_u8Port)
		{
		case DIO_PORTA:
			CLR_BIT(PORTA, copy_u8Pin);
			break;
		case DIO_PORTB:
			CLR_BIT(PORTB, copy_u8Pin);
			break;
		case DIO_PORTC:
			CLR_BIT(PORTC, copy_u8Pin);
			break;
		case DIO_PORTD:
			CLR_BIT(PORTD, copy_u8Pin);
			break;
		}
	}
	else if(copy_u8Val == HIGH)
	{
		switch(copy_u8Port)
		{
		case DIO_PORTA:
			SER_BIT(PORTA, copy_u8Pin);
			break;
		case DIO_PORTB:
			SER_BIT(PORTB, copy_u8Pin);
			break;
		case DIO_PORTC:
			SER_BIT(PORTC, copy_u8Pin);
			break;
		case DIO_PORTD:
			SER_BIT(PORTD, copy_u8Pin);
			break;
		}
	}
}

u8 MDIO_u8GetPinVal(u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 L_ReturnGet;
	switch(copy_u8Port)
	{
	case DIO_PORTA:
		L_ReturnGet = GET_BIT(PINA, copy_u8Pin);
		break;
	case DIO_PORTB:
		L_ReturnGet = GET_BIT(PINB, copy_u8Pin);
		break;
	case DIO_PORTC:
		L_ReturnGet = GET_BIT(PINC, copy_u8Pin);
		break;
	case DIO_PORTD:
		//localVariable = GET_BIT(PIND, copy_u8Pin);
		L_ReturnGet = GET_BIT(PIND, copy_u8Pin);
		break;
	}
	return L_ReturnGet;
}

void MDIO_vSetPortDir(u8 copy_u8Port, u8 copy_u8Dir)
{
	if(copy_u8Dir == INPUT)
	{
		switch(copy_u8Port)
		{
		case DIO_PORTA:
			DDRA = 0x00;
			break;
		case DIO_PORTB:
			DDRB = 0x00;
			break;
		case DIO_PORTC:
			DDRC = 0x00;
			break;
		case DIO_PORTD:
			DDRD = 0x00;
			break;
		}
	}
	else if(copy_u8Dir == OUTPUT)
	{
		switch(copy_u8Port)
		{
		case DIO_PORTA:
			DDRA = 0xFF;
			break;
		case DIO_PORTB:
			DDRB = 0xFF;
			break;
		case DIO_PORTC:
			DDRC = 0xFF;
			break;
		case DIO_PORTD:
			DDRD = 0xFF;
			break;
		}
	}
}

void MDIO_vSetPortVal(u8 copy_u8Port, u8 copy_u8Val)
{
	switch(copy_u8Port)
			{
			case DIO_PORTA:
				PORTA =copy_u8Val;
				break;
			case DIO_PORTB:
				PORTB =copy_u8Val;
				break;
			case DIO_PORTC:
				PORTC =copy_u8Val;
				break;
			case DIO_PORTD:
				PORTD = copy_u8Val;
				break;
			}
}

u8 MDIO_u8GetPortVal(u8 copy_u8Port)
{
	u8 L_ReturnGet;
	switch(copy_u8Port)
	{
	case DIO_PORTA:
		L_ReturnGet = PINA;
		break;
	case DIO_PORTB:
		L_ReturnGet = PINB;
		break;
	case DIO_PORTC:
		L_ReturnGet = PINC;
		break;
	case DIO_PORTD:
		L_ReturnGet = PIND;
		break;
	}
	return L_ReturnGet;
}




