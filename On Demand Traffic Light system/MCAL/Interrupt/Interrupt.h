/*
 * Interrupt.h
 *
 * Created: 1/2/2023 11:37:42 AM
 *  Author: ahmed bahaa
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "../../type.h"
#include "../DIO/DIO.h"

typedef enum EN_InterruptsError_t {
	Interrupt_API_OK, Interrupt_API_Error
}EN_InterruptsError_t;

typedef enum EN_Interrupt_Sense_t{
	Falling_edge,Raising_Edge,Low_level,Logical_Change
	}EN_Interrupt_Sense_t;
	
EN_InterruptsError_t Enable_External_INT0 (EN_Interrupt_Sense_t Intrrupt_sense); //enables INT0 interrupt
void Test_Interrupt_API(void); //function for testing APIs

#endif /* INTERRUPT_H_ */