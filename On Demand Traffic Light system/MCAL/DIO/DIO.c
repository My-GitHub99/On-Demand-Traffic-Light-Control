/*
 * DIO.c
 *
 * Created: 12/29/2022 11:31:51 AM
 *  Author: ahmed bahaa
 */ 
#include <stdio.h>
#include "DIO.h"
#include "../Timer/Timer.h"


//function takes pin number, port number and direction (input or output) from user
// depending on the port chosen the corresponding DDR register value will be changed according to the required pin number
// if direction is INPUT, bit is cleared, if output bit is set to 1
EN_DIOErorr_t DIO_init (uint8_t pin_number,uint8_t port,uint8_t port_direction ){
	switch (port){
		
		case PORT_A:
		if(port_direction == IN){
			DDRA &= ~(1<<pin_number);
			return DIO_API_OK;
		}
		else if(port_direction == OUT){
			DDRA |= (1<<pin_number);
			return DIO_API_OK;
		}
		else{
			return DIO_API_Error;
		}
		break;
		
		case PORT_B:
		if(port_direction == IN){
			DDRB&=~(1<<pin_number);
			return DIO_API_OK;
		}
		else if(port_direction == OUT){
			DDRB|=(1<<pin_number);
			return DIO_API_OK;
		}
		else{
			return DIO_API_Error;
		}
		break;
		
		case PORT_C:
		if(port_direction == IN){
			DDRC&=~(1<<pin_number);
			return DIO_API_OK;
		}
		else if(port_direction == OUT){
			DDRC|=(1<<pin_number);
			return DIO_API_OK;
		}
		else{
			return DIO_API_Error;
		}
		break;
		
		case PORT_D:
		if(port_direction == IN){
			DDRD&=~(1<<pin_number);
			return DIO_API_OK;
		}
		else if(port_direction == OUT){
			DDRD|=(1<<pin_number);
			return DIO_API_OK;
		}
		else{
			return DIO_API_Error;
		}
		break;
		
		default:
		return DIO_API_Error;
	}
}

//this function writes High or low on desired pin
// if value is LOW, bit is cleared in PORT register, if HIGH bit is set to 1
// function returns API ok status if everything is ok
EN_DIOErorr_t DIO_write (uint8_t pin_number,uint8_t port,uint8_t value ){
	switch(port){
	case PORT_A:
	if(value == LOW){
		PORTA &=~(1<<pin_number);
		return DIO_API_OK;
	}
	else if(value == HIGH){
		PORTA|=(1<<pin_number);
		return DIO_API_OK;
	}
	else{
		return DIO_API_Error;
	}
	break;
	
	case PORT_B:
	if(value == LOW){
		PORTB &=~(1<<pin_number);
		return DIO_API_OK;
	}
	else if(value == HIGH){
		PORTB|=(1<<pin_number);
		return DIO_API_OK;
	}
	else{
		return DIO_API_Error;
	}
	break;
	
	case PORT_C:
	if(value == LOW){
		PORTC &=~(1<<pin_number);
		return DIO_API_OK;
	}
	else if(value == HIGH){
		PORTC|=(1<<pin_number);
		return DIO_API_OK;
	}
	else{
		return DIO_API_Error;
	}
	break;
	
	if(value == LOW){
		PORTD &=~(1<<pin_number);
		return DIO_API_OK;
	}
	else if(value == HIGH){
		PORTD|=(1<<pin_number);
		return DIO_API_OK;
	}
	else{
		return DIO_API_Error;
	}
	break;
	
	default:
	return DIO_API_Error;
}
}

// this function toggles the pin between high and low status using Xor operator
// function returns API_Ok status if everything is ok
EN_DIOErorr_t DIO_toggle (uint8_t pin_number,uint8_t port){
	switch(port){
	case PORT_A:
		PORTA ^=(1<<pin_number);
		return DIO_API_OK;
	    break;
	
	case PORT_B:
	PORTB ^=(1<<pin_number);
	return DIO_API_OK;
	break;
	
	case PORT_C:
	PORTC ^=(1<<pin_number);
	return DIO_API_OK;
	break;
	
	case PORT_D:
	PORTD ^=(1<<pin_number);
	return DIO_API_OK;
	break;
	
    default:
    return DIO_API_Error;
}
}

//this function reads the status of each pin from PIN status register
// function returns API_Ok status if everything is ok
EN_DIOErorr_t DIO_read (uint8_t pin_number,uint8_t port,uint8_t *value ){
	switch(port){
		case PORT_A:
		*value = PINA &((1<<pin_number)>>pin_number);
		return DIO_API_OK;
		break;
		
		case PORT_B:
		*value= PINB &((1<<pin_number)>>pin_number);
		return DIO_API_OK;
		break;
		
		case PORT_C:
		*value= PINC &((1<<pin_number)>>pin_number);
		return DIO_API_OK;
		break;
		
		case PORT_D:
		*value = PIND &((1<<pin_number)>>pin_number);
		return DIO_API_OK;
		break;
		
		default:
		return DIO_API_Error;
	}
}
// test function for testing DIO_API
// toggle pin 1 portA every 5 sec
// if pin 0 port A is high, pin0 port B will be high
void Test_DIO_API(void){
	DIO_init(0,PORT_A,OUT);
	DIO_init(1,PORT_A,OUT);
	DIO_init(0,PORT_B,OUT);
	uint8_t *ptr=NULL;
	while (1){
		DIO_write(0,PORT_B,HIGH);
		DIO_toggle(1,PORT_A);
		DIO_read(0,PORT_B,ptr);
		(*ptr == 1)? DIO_write(0,PORT_A,HIGH) : DIO_write(0,PORT_A,LOW);
		Timer0_5sec_delay();
	}
}


/*int main (){
	Test_DIO_API();
return 0;	
}*/