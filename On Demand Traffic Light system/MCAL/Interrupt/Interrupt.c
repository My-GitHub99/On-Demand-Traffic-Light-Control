/*
 * Interrupt.c
 *
 * Created: 1/2/2023 11:37:32 AM
 *  Author: ahmed bahaa
 */ 

#include "Interrupt.h"

uint8_t mode=0;

// this function enables the external INT0
//function takes an argument of type enum that indicates the required Interrupt sense for the external interrupt INT0
// steps: enable global interrupt, enable interrupt sense in MCUCR register based on the input sense , enable INT0
EN_InterruptsError_t Enable_External_INT0 (EN_Interrupt_Sense_t Intrrupt_sense){
	
	switch(Intrrupt_sense){
		
		case Raising_Edge:
		sei();
		MCUCR|= (1<<0) | (1<<1);
		GICR|=(1<<6);
		return Interrupt_API_OK;
		break;
		
		case Falling_edge:
		sei();
		MCUCR|= (1<<1);
		GICR|=(1<<6);
		return Interrupt_API_OK;
		break;
		
		case Logical_Change:
		sei();
		MCUCR|= (1<<0);
		GICR|=(1<<6);
		return Interrupt_API_OK;
		break;
		
		case Low_level:
		sei();
		MCUCR|= 0x00;
		GICR|=(1<<6);
		return Interrupt_API_OK;
		break;
		
		default:
		return Interrupt_API_Error;
	}
}

// this function tests Interrupt driver API
// if push button is pushed, pin 0 PORT A is changed between on , off  
void Test_Interrupt_API(){
	DIO_init(0,PORT_A,OUT);
	Enable_External_INT0 (Raising_Edge);
	while(1){
		switch (mode){
			
			case 0:
			DIO_write(0,PORT_A,HIGH);
			break;
			
			
			case 1:
			DIO_write(0,PORT_A,LOW);
			break;
			
		}
	}
	
}


/*int main (){
	
Test_Interrupt_API();
return 0;
	}



ISR (INT0_vect){
	if(mode<1){
	mode++;
	}
	else{
	mode=0;
	}
}*/
	