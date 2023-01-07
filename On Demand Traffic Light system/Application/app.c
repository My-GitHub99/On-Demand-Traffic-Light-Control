/*
 * app.c
 *
 * Created: 12/29/2022 11:26:34 AM
 *  Author: ahmed bahaa
 */ 

#include "app.h"

uint8_t car_red_LED_flag =0;
uint8_t car_yellow_LED_flag=0;
EN_Mode_t *Mode;

void App_Start (){
	LED_Config();
	Button_interrupt_config (Falling_edge);
	Mode=(EN_Mode_t*)malloc(sizeof(EN_Mode_t));
	
	while(1){
		*Mode = Normal_Mode;
		car_red_LED_flag =0;
		car_yellow_LED_flag=0;
		LED_OUT(Car_Green,ON);
		LED_OUT(Ped_Red,ON);
		Traffic_LED_Delay(Mode);
		LED_OUT(Car_Green,OFF);
		car_yellow_LED_flag=1;
		LED_Blink_5sec(Car_Yellow,Mode);
		
		while (car_red_LED_flag==0){
		 LED_OUT(Car_Yellow,OFF);
		 LED_OUT(Car_Red,ON);
		 car_yellow_LED_flag=0;
		 car_red_LED_flag = 1;
		 Traffic_LED_Delay(Mode);
		 LED_OUT(Car_Red,OFF);
		 car_yellow_LED_flag=1;
		 LED_Blink_5sec(Car_Yellow,Mode);
		 LED_OUT(Car_Yellow,OFF);
		}
	}
}


	
/*int main(){
		App_Start();
	}*/
	

	ISR (INT0_vect){
		Pedestrain_Context_switch();
	}
	
	void Pedestrain_Context_switch(){
		if(car_red_LED_flag == 1 && car_yellow_LED_flag==0 ){
			LED_OUT(Ped_Red,OFF);
			LED_OUT(Ped_Green,ON);
			Ped_LED_Delay();
			LED_OUT(Car_Red,OFF);
			LED_Blink_5sec(Both_Yellow_LEDS,Mode);
			LED_OUT(Ped_Green,OFF);
			LED_OUT(Ped_Yellow,OFF);
			LED_OUT(Car_Yellow,OFF);
			LED_OUT(Ped_Red,ON);
			*Mode = Pedestrain_Mode;
			
		}
		
		else{
			LED_OUT(Ped_Red,ON);
			LED_OUT(Car_Green,OFF);
			LED_Blink_5sec(Both_Yellow_LEDS,Mode);
			LED_OUT(Ped_Yellow,OFF);
			LED_OUT(Ped_Red,OFF);
			LED_OUT(Ped_Green,ON);
			LED_OUT(Car_Red,ON);
			Ped_LED_Delay();
			LED_OUT(Car_Red,OFF);
			LED_Blink_5sec(Both_Yellow_LEDS,Mode);
			LED_OUT(Ped_Yellow,OFF);
			LED_OUT(Car_Yellow,OFF);
			LED_OUT(Ped_Red,ON);
			LED_OUT(Ped_Green,OFF);
			*Mode = Pedestrain_Mode;
		}
	}