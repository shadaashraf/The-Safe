/*
 * DIO_prog.c

 *
 *  Created on: Dec 10, 2023
 *      Author: Doaa Rageh
 */


/* lib */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* DIO */
#include "DIO_int.h"

/* lower layer */
#include "HLCD_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"


void HLCD_vInit(void){
	//0-set LCD pins config
	MDIO_vSetPortDir(DATA_PORT,OUTPUT);
	MDIO_vSetPinDir(CTR_PORT,LCD_E,OUTPUT);
	MDIO_vSetPinDir(CTR_PORT,LCD_RS,OUTPUT);
	MDIO_vSetPinDir(CTR_PORT,LCD_RW,OUTPUT);
	//1-Delay for 40ms
	_delay_ms(40);
	//2- send function set command
	HLCD_vSendCommand(LCD_FUNCTION_SET);
	//3-delay for 40ms
	//4-send cmd for display on/off
	HLCD_vSendCommand(LCD_DISPLY_ON_OFF);
	//5-delay for 40ms
	//6-send command "clear LCD screen"
	HLCD_vSendCommand(LCD_CLEAR);
	_delay_ms(1);
}
void HLCD_vSendCommand(u8 Copy_u8Cmd){

	//CLR RS TO SEND CMD
	MDIO_vSetPinVal(CTR_PORT,LCD_RS,LOW);
	//CLR RW TO WRITE
	MDIO_vSetPinVal(CTR_PORT,LCD_RW,LOW);
	//Send cmd
	MDIO_vSetPortVal(DATA_PORT,Copy_u8Cmd);
	// set lcd enable
	MDIO_vSetPinVal(CTR_PORT,LCD_E,HIGH);
	//wait for 1ms
	_delay_ms(1);
	//clr lcd enable
	MDIO_vSetPinVal(CTR_PORT,LCD_E,LOW);
}
void HLCD_vSendData(u8 Copy_u8Data){
	//CLR RS TO SEND DATA
	MDIO_vSetPinVal(CTR_PORT,LCD_RS,HIGH);
	//CLR RW TO WRITE
	MDIO_vSetPinVal(CTR_PORT,LCD_RW,LOW);
	//Send DATA
	MDIO_vSetPortVal(DATA_PORT,Copy_u8Data);
	// set lcd enable
	MDIO_vSetPinVal(CTR_PORT,LCD_E,HIGH);
	//wait for 1ms
	_delay_ms(1);
	//clr lcd enable
	MDIO_vSetPinVal(CTR_PORT,LCD_E,LOW);
}
void HLCD_vSendString(u8 *u8DATA){
	u8 i=0;
	while(u8DATA[i])
	{
		HLCD_vSendData(u8DATA[i]);
		i++;
	}
}

void HLCD_vClearScrean(void){
	HLCD_vSendCommand(LCD_CLEAR);
}
void HLCD_vGotoXY(u8 Copy_u8PositionX,u8 Copy_u8PositionY){
	u8 local=0;
	if(Copy_u8PositionY==0)
	{
		local=Copy_u8PositionX;
	}
	else if(Copy_u8PositionY==1)
	{
		local=Copy_u8PositionX+40;
	}
	HLCD_vSendCommand(local+128);
}
void HLCD_vWriteNumber(u16 Copy_u16Number){

}
