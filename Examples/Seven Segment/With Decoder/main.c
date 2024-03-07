/*
 * NTI_R7.c
 *
 * Created: 3/5/2024 2:10:04 PM
 * Author : Ahmed Mohammed
 */ 

#include "common.h"

#include "DIO_interface.h"
#include "SevenSegment_Interface.h"

int main(void)
{
	SevenSegment_voidDIOInit();
	
    while(1)
    {
        //TODO:: Please write your application code
		
		SevenSegment_voidWriteFourDigits(1234);
    }
}

