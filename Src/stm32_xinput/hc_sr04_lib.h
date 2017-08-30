#ifndef __hc_sr04_lib_H
#define __hc_sr04_lib_H

#include "stdint.h"
#include "stm32f1xx_hal.h"

#define FREQ_72MHZ 	10
#define FREQ_32MHZ 	6
#define FREQ_8MHZ 	2


#define MAX_SENSOR_DISTANCE 500 // Maximum sensor distance = 500 cm
#define US_ROUNDTRIP_CM 57      

typedef struct{
	GPIO_TypeDef  *GPIOx;
	uint32_t Pin;       
	
} Sonar_PinStruct;

extern uint8_t Sonar_InterruptionMode;				// 0x00 = InterruptionMode disable

void Sonar_Init( Sonar_PinStruct triggerPin, Sonar_PinStruct echoPin );
int32_t Sonar_Read();
void Delay_Microseconds(uint32_t time);

#endif
