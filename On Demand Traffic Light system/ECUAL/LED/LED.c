/*
 * LED.c
 *
 * Created: 12/29/2022 11:25:31 AM
 *  Author: ahmed bahaa
 */ 

//LEDS Hardware Configuration
// Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
// Three LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2

#include "LED.h"

EN_Mode_t *ptr = NULL;

// sets pin 0, 1 , 2 in both PORT A and B as Output
 EN_LEDErorr_t LED_Config (void){
	 DIO_init(0,PORT_A,OUT); //Car_GREEN
	 DIO_init(1,PORT_A,OUT); // CAR_YELLOW
	 DIO_init(2,PORT_A,OUT); //CAR_RED
	 
	 DIO_init(0,PORT_B,OUT); //PED_GREEN
	 DIO_init(1,PORT_B,OUT); // PED_YELLOW
	 DIO_init(2,PORT_B,OUT); //PED_RED
	 return LED_API_OK;
 }
 
 // makes LEDS ON,OFF or blink based on input arguments 
 EN_LEDErorr_t LED_OUT(EN_LEDS_t led, EN_LED_Output_t output){
	 switch (led){
		 case Car_Green:
		 
		 switch (output) {
			case ON:
			DIO_write(0,PORT_A,HIGH);
			return LED_API_OK;
			break;
			
			case OFF:
			DIO_write(0,PORT_A,LOW);
			return LED_API_OK;
			break;
			
			case Blink:
			DIO_toggle(0,PORT_A);
			return LED_API_OK;
			break;
			
			default:
			return LED_API_Error;
			
		 }
		 
		 case Car_Yellow:
		 
		 switch (output) {
			 case ON:
			 DIO_write(1,PORT_A,HIGH);
			 return LED_API_OK;
			 break;
			 
			 case OFF:
			 DIO_write(1,PORT_A,LOW);
			 return LED_API_OK;
			 break;
			 
			 case Blink:
			 DIO_toggle(1,PORT_A);
			 return LED_API_OK;
			 break;
			 
			 default:
			 return LED_API_Error;
		
	 }
	 
	 case Car_Red:
	 
	 switch (output) {
		 case ON:
		 DIO_write(2,PORT_A,HIGH);
		 return LED_API_OK;
		 break;
		 
		 case OFF:
		 DIO_write(2,PORT_A,LOW);
		 return LED_API_OK;
		 break;
		 
		 case Blink:
		 DIO_toggle(2,PORT_A);
		 return LED_API_OK;
		 break;
		 
		 default:
		 return LED_API_Error;

	 }
	 
	 case Ped_Green:
	 
	 switch (output) {
		 case ON:
		 DIO_write(0,PORT_B,HIGH);
		 return LED_API_OK;
		 break;
		 
		 case OFF:
		 DIO_write(0,PORT_B,LOW);
		 return LED_API_OK;
		 break;
		 
		 case Blink:
		 DIO_toggle(0,PORT_B);
		 return LED_API_OK;
		 break;
		 
		 default:
		 return LED_API_Error;
	 }
	 
	 case Ped_Yellow:
	 
	 switch (output) {
		 case ON:
		 DIO_write(1,PORT_B,HIGH);
		 return LED_API_OK;
		 break;
		 
		 case OFF:
		 DIO_write(1,PORT_B,LOW);
		 return LED_API_OK;
		 break;
		 
		 case Blink:
		 DIO_toggle(1,PORT_B);
		 return LED_API_OK;
		 break;
		 
		 default:
		 return LED_API_Error;
	 }
	 
	  case Ped_Red:
	  
	  switch (output) {
		  case ON:
		  DIO_write(2,PORT_B,HIGH);
		  return LED_API_OK;
		  break;
		  
		  case OFF:
		  DIO_write(2,PORT_B,LOW);
		  return LED_API_OK;
		  break;
		  
		  case Blink:
		  DIO_toggle(2,PORT_B);
		  return LED_API_OK;
		  break;
		  
		  default:
		  return LED_API_Error;
	  }
	  
	  default:
	  return LED_API_Error;
	 
 }
 
 }
 
// this function blink yellow Leds for 5 seconds, the desired yellow led to be blinked is passed to the function by user
// the timers overflow loop checks the current mode of operation whether it is the normal mode or pedestrian mode
// if mode == pedestrain mode , break from counting and return to the main code
// else ,  continue counting

 EN_LEDErorr_t LED_Blink_5sec (EN_LEDS_t led,EN_Mode_t *mode){
	uint8_t overflow_count0 =0;
	switch (led){
	
	case Car_Yellow:
	 Timer0_init_normal();
	 Timer0_set(0);
	 Timer0_start(CLK_1024);
	 while(overflow_count0< 19){
		 if(*mode==Pedestrain_Mode){
			 Timer0_clear_overflow_flag();
			 break;
		 }
		 while((TIFR & (1<<0))==0);
		 DIO_toggle(1,PORT_A);
		 Timer0_clear_overflow_flag();
		 overflow_count0++;
	 }
	 DIO_write(1,PORT_A,LOW);
	 return LED_API_OK;
	 break;
	 
	 case Ped_Yellow:
	 overflow_count0 =0;
	 Timer2_init_normal();
	 Timer2_set(0);
	 Timer2_start(CLK_1024);
	 while(overflow_count0< 19){
		 if(*mode==Pedestrain_Mode){
			  Timer2_clear_overflow_flag();
			  break;
		 }
		 while((TIFR & (1<<6))==0);
		 DIO_toggle(1,PORT_B);
		 Timer2_clear_overflow_flag();
		 overflow_count0++;
	}
	  DIO_write(1,PORT_B,LOW);
	  return LED_API_OK;
	  break;
	 
	 case Both_Yellow_LEDS:
	 overflow_count0 =0;
	 Timer2_init_normal();
	 Timer2_set(0);
	 Timer2_start(CLK_1024);
	 while(overflow_count0< 19){
		  if(*mode==Pedestrain_Mode){
			   Timer2_clear_overflow_flag();
			   break;
		  }
		 while((TIFR & (1<<6))==0);
		 DIO_toggle(1,PORT_A);
		 DIO_toggle(1,PORT_B);
		 Timer2_clear_overflow_flag();
		 overflow_count0++;
	 }
	 DIO_write(1,PORT_A,LOW);
	 DIO_write(1,PORT_B,LOW);
	 
	 return LED_API_OK;
	 break;
	 
	 
	 default:
	 return LED_API_Error; 
 }
 return LED_API_OK;
 }
 
// this function makes a delay for 5 sec., maintaining the Traffic LEDS status on or off for 5 sec.
// the timers overflow loop checks the current mode of operation whether it is the normal mode or pedestrian mode (changed by pushing the button)
// if mode == pedestrain mode , break from the delay while loop and return to the main code
// else , continue counting
 
 EN_LEDErorr_t Traffic_LED_Delay(EN_Mode_t *mode){
	 uint8_t overflow_count0=0;
	 Timer0_init_normal();
	 Timer0_set(0);
	 Timer0_start(CLK_1024); 
	 while(overflow_count0< 19){
		  if(*mode==Pedestrain_Mode){
			  Timer0_clear_overflow_flag();
			  break;
		  }
		 while((TIFR & (1<<0))==0);
		 Timer0_clear_overflow_flag();
		 overflow_count0++;
	 }
	  
	 Timer0_stop();
	 return LED_API_OK;
 }
 
 // this function makes a delay for 5 sec., maintaining the Traffic LEDS status on or off for 5 sec.
 // the timers overflow loop checks the current mode of operation whether it is the normal mode or pedestrian mode (changed by pushing the button)
 // if mode == pedestrain mode , break from the delay while loop and return to the main code
 // else , continue counting
 EN_LEDErorr_t Ped_LED_Delay(void){
	 uint8_t overflow_count2=0;
	 Timer2_init_normal();
	 Timer2_set(0);
	 Timer2_start(CLK_1024);
	 while(overflow_count2< 19){
		 while((TIFR & (1<<6))==0);
		 Timer2_clear_overflow_flag();
		 overflow_count2++;
	 }
	 Timer2_stop();
	 return LED_API_OK;
 }
 
 // this function tests the LED drivers API
 // Lights the Traffic green led for 5 sec. 
 //then blinks both yellow leds for 5 sec. 
 // then traffic is red and PED green led is on for 5 sec.
 // then blink both leds
 // return to the begining of the loop
 
 void test_LED_API (void){
	 
	LED_Config();
	EN_Mode_t *ptr = NULL;
	ptr=(EN_Mode_t*) malloc(sizeof(EN_Mode_t));
	*ptr = Normal_Mode;
	 while(1){
		 LED_OUT(Car_Green,ON);
		 Traffic_LED_Delay(ptr);
		 LED_OUT(Car_Green,OFF);
		 LED_Blink_5sec(Both_Yellow_LEDS,Normal_Mode);
		 LED_OUT(Car_Red,ON);
		 LED_OUT(Ped_Green,ON);
		 Ped_LED_Delay();
		 LED_OUT(Car_Red,OFF);
		 LED_OUT(Ped_Green,OFF);
		 LED_Blink_5sec(Both_Yellow_LEDS,Normal_Mode);
		 LED_OUT(Car_Yellow,OFF);
		 LED_OUT(Ped_Yellow,OFF);
		
	 }
 }
 
/*int main(){
	 test_LED_API();
	 return 0;
 }*/