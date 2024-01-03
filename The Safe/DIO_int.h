#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define INPUT      0
#define OUTPUT     1

#define DIO_PORTA  0
#define DIO_PORTB  1
#define DIO_PORTC  2
#define DIO_PORTD  3

#define LOW        0
#define HIGH       1

#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

void MDIO_vSetPinDir(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Dir);
void MDIO_vSetPinVal(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Val);
u8 MDIO_u8GetPinVal(u8 copy_u8Port, u8 copy_u8Pin);

void MDIO_vSetPortDir(u8 copy_u8Port, u8 copy_u8Dir);
void MDIO_vSetPortVal(u8 copy_u8Port, u8 copy_u8Val);
u8 MDIO_u8GetPortVal(u8 copy_u8Port);

#endif
