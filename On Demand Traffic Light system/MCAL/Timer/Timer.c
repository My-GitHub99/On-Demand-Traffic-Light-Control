/*
 * Timer.c
 *
 * Created: 12/29/2022 11:33:19 AM
 *  Author: ahmed bahaa
 */ 
#include <stdio.h>
#include <math.h>
#include "Timer.h"

#define F_CPU 1000000


//Timer 0 calculations------->>>>> 5 seconds delay
// CLK prescaler = F_CLK/1024
// required delay time for testing API = 5 sec
// max delay time = 260 ms
//required number of overflows = 19
// add additional overflow cycle as it takes a cycle to roll and raise timer flag

//Timer 2 calculations ------->>>>> 500ms delay
// CLK prescaler = F_CLK/256
// T_tick = 2.56* 10^-4
//T_max_delay = 0.65536 s
// N_overflow = 7.629 ~ 8
// initial_value = 11.859 ~ 12


// sets timer0 on normal mode
EN_TimerErorr_t Timer0_init_normal(void){
TCCR0=0x00; // setting normal mode
return API_OK;
}

// sets initial value in TCNT0 register based on the delay's calculations
EN_TimerErorr_t Timer0_set(uint8_t Timer_initial_value){
	TCNT0=Timer_initial_value;
	return API_OK;
}

//sets timer prescaler based on the input enum type and starts timer
EN_TimerErorr_t Timer0_start(EN_Timer_Prescaler_t prescaler){
	switch (prescaler){
	case No_Prescaler:
	TCCR0|=(1<<0);
	break;
	
	case CLK_8:
	TCCR0|=(1<<1);
	break;
	case CLK_64:
	TCCR0|=(1<<0);
	TCCR0|=(1<<1);
	break;
	
	case CLK_256:
	TCCR0|=(1<<2);
	break;
	
	case CLK_1024:
	TCCR0|=(1<<0);
	TCCR0|=(1<<2);
	break;
	}
	return API_OK;
}

// this function clears overflow flag
EN_TimerErorr_t Timer0_clear_overflow_flag(void){
	TIFR|=(1<<0);
	return API_OK;
}

// this function stops Timer0
EN_TimerErorr_t Timer0_stop(void){
	TCCR0=0x00; // stop timer
	return API_OK;
}
 
 // this function generates a delay for 5 seconds
 // after each overflow, overflow flag is cleared and counter starts counting again 
 // when number of overflows reachs 19, timer stops
 
EN_TimerErorr_t Timer0_5sec_delay(void){
	uint8_t overflow_count0=0;
	Timer0_init_normal();
	Timer0_set(0);
	Timer0_start(CLK_1024);
	while(overflow_count0< 19){
		while((TIFR & (1<<0))==0);
			Timer0_clear_overflow_flag();
			overflow_count0++;
		}
	Timer0_stop();
	return API_OK;
}

// pin 1 in port A is on for 5 sec., then pin 0 port A is on and pin1 port A is off for 5 sec.
void test_timer0_API (void){
	
	DIO_init(0,PORT_A,OUT);
	DIO_init(1,PORT_A,OUT);

	while(1){
		DIO_write(1,PORT_A,HIGH);
		Timer0_5sec_delay();

		DIO_write(1,PORT_A,LOW);
		DIO_write(0,PORT_A,HIGH);
		Timer0_5sec_delay();
		DIO_write(0,PORT_A,LOW);
	}
}

// Timer 2 API
// sets timer2 on normal mode
EN_TimerErorr_t Timer2_init_normal(void){
	TCCR2=0x00; // setting normal mode
	return API_OK;
}
// sets initial value in TCNT2 register based on the delay's calculations
EN_TimerErorr_t Timer2_set(uint8_t Timer_initial_value){
	TCNT2=Timer_initial_value;
	return API_OK;
}
//sets timer prescaler based on the input enum type and starts timer
EN_TimerErorr_t Timer2_start(EN_Timer_Prescaler_t prescaler){
	switch (prescaler){
		case No_Prescaler:
		TCCR2|=(1<<0);
		break;
		
		case CLK_8:
		TCCR2|=(1<<1);
		break;
		case CLK_64:
		TCCR2|=(1<<0);
		TCCR2|=(1<<1);
		break;
		
		case CLK_256:
		TCCR2|=(1<<2);
		break;
		
		case CLK_1024:
		TCCR2|=(1<<0);
		TCCR2|=(1<<1);
		TCCR2|=(1<<2);
		break;
	}
	return API_OK;
}
// this function clears overflow flag
EN_TimerErorr_t Timer2_clear_overflow_flag(void){
	TIFR|=(1<<6);
	return API_OK;
}
// this function stops Timer2
EN_TimerErorr_t Timer2_stop(void){
	TCCR2=0x00; // stop timer
	return API_OK;
}
// this function generates a delay for 5 seconds
// after each overflow, overflow flag is cleared and counter starts counting again
// when number of overflows reachs 19, timer stops
EN_TimerErorr_t Timer2_5sec_delay(void){
	uint8_t overflow_count2=0;
	Timer2_init_normal();
	Timer2_set(0);
	Timer2_start(CLK_1024);
	overflow_count2=0;
	while(overflow_count2< 19){
		while((TIFR & (1<<6))==0);
		Timer2_clear_overflow_flag();
		overflow_count2++;
	}
	Timer2_stop();
	return API_OK;
}

// pin 1 in port A is on for 5 sec., then pin 0 port A is on and pin1 port A is off for 5 sec.
void test_timer2_API (void){
	
	DIO_init(0,PORT_B,OUT);
	DIO_init(1,PORT_B,OUT);
	while(1){
		DIO_write(0,PORT_B,HIGH);
		Timer2_5sec_delay();
		DIO_write(0,PORT_B,LOW);
		DIO_write(1,PORT_B,HIGH);
		Timer2_5sec_delay();
        DIO_write(1,PORT_B,LOW);
	}
}



/*int main(){
//test_timer0_API();
test_timer2_API();
return 0;
}*/