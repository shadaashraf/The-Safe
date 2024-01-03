#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SER_BIT(reg, bitNum) reg |= (1<<bitNum)
#define CLR_BIT(reg, bitNum) reg &= ~(1<<bitNum)
#define GET_BIT(reg, bitNum) reg &= ~(1<<bitNum)
#define TOGGLE_BIT(reg, bitNum) (reg>>bitNum)&1


#endif
