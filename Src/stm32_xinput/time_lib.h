#ifndef __time_lib_H
#define __time_lib_H

#include "stdint.h"


void TIME_init( TIM_HandleTypeDef htim );
uint32_t TIME_getMicros( void );
uint32_t TIME_getMillis( void );

void add_millis( void );


#endif
