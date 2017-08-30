#include "stm32f1xx_hal.h"
#include <time_lib.h>


TIM_HandleTypeDef _htim;

static uint32_t time_us;
static uint32_t time_ms;

void TIME_init( TIM_HandleTypeDef htim ){
	_htim = htim;
	
	time_us = 0;
	time_ms = 0;
	
	HAL_TIM_Base_Start_IT(&htim);

}

uint32_t TIME_getMicros(){
	time_us = __HAL_TIM_GET_COUNTER(&_htim);
	
	uint32_t micros = time_ms * 1000;
	micros += time_us;
	
	return micros;
}

uint32_t TIME_getMillis(){
	
	return time_ms;
	
}

void add_millis(){
	time_ms++;
}