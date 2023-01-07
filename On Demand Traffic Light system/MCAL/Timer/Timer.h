/*
 * Timer.h
 *
 * Created: 12/29/2022 11:32:56 AM
 *  Author: ahmed bahaa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../type.h"
#include <avr/io.h>
#include "../DIO/DIO.h"



typedef enum EN_Timer_Prescaler_t{
	No_Prescaler,CLK_8,CLK_64,CLK_256,CLK_1024
	}EN_Timer_Prescaler_t;
	
typedef enum EN_TimerErorr_t{
	API_OK, API_Error
}EN_TimerErorr_t;

// Timer0 API
EN_TimerErorr_t Timer0_init_normal(void);// sets the timer mode
EN_TimerErorr_t Timer0_set(uint8_t Timer_initial_value); // sets initial timer value 
EN_TimerErorr_t Timer0_start(EN_Timer_Prescaler_t prescaler);//start timer
EN_TimerErorr_t Timer0_clear_overflow_flag(void);
EN_TimerErorr_t Timer0_stop(void);// stops timer*/
EN_TimerErorr_t Timer0_5sec_delay(void);// generates a 5 seconds delay
void test_timer0_API (void); //function for testing APIs


// Timer2_API
EN_TimerErorr_t Timer2_init_normal(void);// sets the timer mode
EN_TimerErorr_t Timer2_set(uint8_t Timer_initial_value); // sets initial timer value 
EN_TimerErorr_t Timer2_start(EN_Timer_Prescaler_t prescaler);//start timer
EN_TimerErorr_t Timer2_clear_overflow_flag(void);
EN_TimerErorr_t Timer2_stop();// stops timer*/
EN_TimerErorr_t Timer2_5sec_delay(void);// generates a 500ms delay
void test_timer2_API (void); //function for testing APIs






#endif /* TIMER_H_ */