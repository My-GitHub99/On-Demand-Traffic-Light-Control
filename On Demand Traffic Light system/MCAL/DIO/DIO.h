/*
 * DIO.h
 *
 * Created: 12/29/2022 11:32:45 AM
 *  Author: ahmed bahaa
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../type.h"
#include <avr/io.h>
//Macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 1
#define OUT 0

#define HIGH 1
#define LOW 0

typedef enum EN_DIOErorr_t{
	DIO_API_OK, DIO_API_Error
}EN_DIOErorr_t;


// Driver's API Prototypes
EN_DIOErorr_t DIO_init (uint8_t pin_number,uint8_t port,uint8_t port_direction ); // sets pin direction as input or output
EN_DIOErorr_t DIO_write (uint8_t pin_number,uint8_t port,uint8_t value ); // sets pin as high or low
EN_DIOErorr_t DIO_toggle (uint8_t pin_number,uint8_t port); // Toggles pin
EN_DIOErorr_t DIO_read (uint8_t pin_number,uint8_t port,uint8_t *value );// read pin status
void Test_DIO_API(void); // function for testing APIs



#endif /* DIO_H_ */