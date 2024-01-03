#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

void HLCD_vInit(void);
void HLCD_vSendCommand(u8 Copy_u8Cmd);
void HLCD_vSendData(u8 Copy_u8Data);
void HLCD_vSendString(u8 *u8DATA);
void HLCD_vClearScrean(void);
void HLCD_vGotoXY(u8 Copy_u8PositionX,u8 Copy_u8PositionY);
void HLCD_vWriteNumber(u16 Copy_u16Number);
#endif
