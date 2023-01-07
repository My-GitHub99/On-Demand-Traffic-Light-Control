/*
 * Button.h
 *
 * Created: 12/29/2022 11:25:16 AM
 *  Author: ahmed bahaa
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/Interrupt/Interrupt.h"
#include "../../type.h"
#include <avr/io.h>

typedef enum EN_ButtonErorr_t{
	Button_API_OK, Button_API_Error
}EN_ButtonErorr_t;

EN_ButtonErorr_t Button_interrupt_config (EN_Interrupt_Sense_t Sense); // enables external Interrupt INT0 for button and sets Interrupt sense
void Test_Button_API(void); // function to test API






#endif /* BUTTON_H_ */