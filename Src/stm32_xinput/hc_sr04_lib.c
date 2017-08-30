#include "hc_sr04_lib.h" 
#include "stm32f1xx_hal.h"
#include "stm32f1xx.h"

#include "time_lib.h"

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

Sonar_PinStruct _triggerPin;				// Struct with PORT and PIN
Sonar_PinStruct _echoPin;

uint32_t _maxDistance;
uint32_t _maxEchoTime;							// 

uint8_t Sonar_InterruptionMode;	

void Sonar_Init( Sonar_PinStruct triggerPin, Sonar_PinStruct echoPin ){
	// Save the pins
	_triggerPin = triggerPin;
	_echoPin = echoPin;
		
	// Set to LOW the trigger pin
	HAL_GPIO_WritePin( triggerPin.GPIOx, triggerPin.Pin, GPIO_PIN_RESET );
}

int32_t Sonar_Read( ){
	uint32_t start_time;
	
	HAL_GPIO_WritePin(_triggerPin.GPIOx, _triggerPin.Pin, RESET);
	
	start_time =  TIME_getMicros();
	while( (TIME_getMicros() - start_time) < 10 );
	
	HAL_GPIO_WritePin(_triggerPin.GPIOx, _triggerPin.Pin, SET);
	
	start_time =  TIME_getMicros();
	while( (TIME_getMicros() - start_time) < 10 );
	
	HAL_GPIO_WritePin(_triggerPin.GPIOx, _triggerPin.Pin, RESET);
	
	uint32_t echo_start = 0;
	uint32_t state = 0;
	
	start_time =  TIME_getMicros();

	while(1){
		
		if( (TIME_getMicros() - start_time) > 500000 ){
			return -1;
			
		}
		
		if( state == 0 && HAL_GPIO_ReadPin(_echoPin.GPIOx, _echoPin.Pin) == 1 ){
			echo_start = TIME_getMicros();
			state = 1;
		
		}else if( state == 1 && HAL_GPIO_ReadPin(_echoPin.GPIOx, _echoPin.Pin) == 0 ){
			return TIME_getMicros() - echo_start;
			
		}
		
	}
	
}

