#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit)							((reg) |= (1 << (bit)))
#define CLEAR_BIT(reg, bit)							((reg) &= ~(1 << (bit)))
#define READ_BIT(reg, bit)							(((reg) >> (bit)) & 0x1)
#define TOGGLE_BIT(reg, bit)						((reg) ^= (1 << (bit)))

#define WRITE_REG_POS(reg, mask, pos, val)			((reg) = ((reg) & (~((mask) << (pos)))) | ((val) << (pos)))
#define WRITE_REG(reg, mask, val)					((reg) = ((reg) & (~(mask))) | (val))

#define CLEAR_REG(reg, mask)						((reg) &= ~(mask))
#define SET_REG(reg, mask)							((reg) |= (mask))

#define READ_REG_POS(reg, mask, pos)				(((reg) >> (pos)) & (mask))
#define READ_REG(reg, mask)							((reg) & (mask))

#define TOGGLE_REG_POS(reg, mask, pos)				((reg) ^= ((mask) << (pos)))
#define TOGGLE_REG(reg, mask)						((reg) ^= (mask))


#define F_CPU	8000000UL

#include <util/delay.h>

#endif
