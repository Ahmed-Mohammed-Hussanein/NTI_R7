#ifndef STD_TYPE_H_
#define STD_TYPE_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef unsigned long long u64;
typedef signed long long s64;

typedef float f32;
typedef double f64;

typedef enum
{
	false = 0,
	true

} bool;

#ifndef NULL

#define NULL (void*)0

#endif

#endif
