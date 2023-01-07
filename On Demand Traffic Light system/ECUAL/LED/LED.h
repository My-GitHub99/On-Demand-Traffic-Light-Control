/*
 * LED.h
 *
 * Created: 12/29/2022 11:26:04 AM
 *  Author: ahmed bahaa
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../type.h"
#include "../../MCAL/Timer/Timer.h"
#include <avr/io.h>
#include <stdlib.h>

typedef enum EN_LED_Output_t{
	ON,OFF,Blink
	}EN_LED_Output_t;
	
typedef enum EN_LEDS_t{
	Car_Green, Car_Yellow, Car_Red, Ped_Green, Ped_Yellow, Ped_Red, Both_Yellow_LEDS
}EN_LEDS_t;

typedef enum EN_LEDErorr_t{
	LED_API_OK, LED_API_Error
}EN_LEDErorr_t;

typedef enum EN_Mode_t{
	Normal_Mode, Pedestrain_Mode
}EN_Mode_t;

 EN_LEDErorr_t LED_Config (void); // sets Led's pins configuration 
 EN_LEDErorr_t LED_OUT(EN_LEDS_t led, EN_LED_Output_t output); // output high or low on LED
 EN_LEDErorr_t LED_Blink_5sec(EN_LEDS_t led,EN_Mode_t *mode); // blinks yellow leds for 5 sec
 EN_LEDErorr_t Traffic_LED_Delay(EN_Mode_t *mode); // creates a delay for traffic leds for 5 seconds using Timer0
 EN_LEDErorr_t Ped_LED_Delay(void); // creates a delay for pedestrain leds for 5 seconds using timer2
 void Test_LEDS_API (void); // function to test APIs


#endif /* LED_H_ */