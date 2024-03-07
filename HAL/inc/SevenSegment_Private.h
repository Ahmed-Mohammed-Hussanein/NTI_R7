/*
 * SevenSegment_Private.h
 *
 * Created: 3/7/2024 2:09:52 PM
 *  Author: mah
 */ 


#ifndef SEVENSEGMENT_PRIVATE_H_
#define SEVENSEGMENT_PRIVATE_H_

#include "SevenSegment_Config.h"

#define BCD_OUTPUT(NUM)			(DEC_##NUM)

#if SEVEN_SEGMENT_COMMON_MODE == SEVEN_SEGMENT_COMMON_ANODE

#define DEC_0					(0x40)
#define DEC_1					(0x79)
#define DEC_2					(0x24)
#define DEC_3					(0x30)
#define DEC_4					(0x19)
#define DEC_5					(0x12)
#define DEC_6					(0x02)
#define DEC_7					(0x78)
#define DEC_8					(0x00)
#define DEC_9					(0x10)

#elif SEVEN_SEGMENT_COMMON_MODE == SEVEN_SEGMENT_COMMON_CATHODE

#define DEC_0					(0xBF)
#define DEC_1					(0x86)
#define DEC_2					(0xDB)
#define DEC_3					(0xCF)
#define DEC_4					(0xE6)
#define DEC_5					(0xED)
#define DEC_6					(0xFD)
#define DEC_7					(0x87)
#define DEC_8					(0xFF)
#define DEC_9					(0xEF)

#endif					


#endif /* SEVENSEGMENT_PRIVATE_H_ */