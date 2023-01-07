/*
 * Button.c
 *
 * Created: 12/29/2022 11:24:31 AM
 *  Author: user
 */ 

#include "Button.h"
// calls the function that enables INT0 Interrupts and sets interrupt sense
EN_ButtonErorr_t Button_interrupt_config (EN_Interrupt_Sense_t Sense){
	Enable_External_INT0(Sense);
	return Button_API_OK;
}

// this function tests API 
// when button is pressed ISR is executed which toggles pin 0 PORT A between ON and OFF
void Test_Button_API(void){
	DIO_init(0,PORT_A,OUT);
	Button_interrupt_config(Raising_Edge);
	while (1){
	}
}

/*int main(){
	Test_Button_API();
	
}

ISR(INT0_vect){
	DIO_toggle(0,PORT_A);
}*/