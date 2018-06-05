#include "stdint.h"
#include "stm32f10x.h"
#include "GPIO_Config.h"
#include "delay.h"

__IO uint32_t input;
__IO uint32_t priority=0x00;
GPIO_Port_Properties protB,protC,protE,protD,protA;

void EXTI15_10_IRQHandler(){

	if(checkPR(Pin10)){
writePin(protB,Pin15,one);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);
			delay_ms(500);
		clear_interrupt(Pin10);
	}
	
		if(checkPR(Pin11)){
writePin(protB,Pin15,zero);
writePin(protB,Pin14,one);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);
				delay_ms(500);
	clear_interrupt(Pin11);
	}
	
	if(checkPR(Pin12)){
writePin(protB,Pin15,one);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);
		delay_ms(500);
writePin(protB,Pin15,zero);
writePin(protB,Pin14,one);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);

delay_ms(500);
writePin(protB,Pin15,zero);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,one);
writePin(protB,Pin12,zero);
delay_ms(500);
writePin(protB,Pin15,zero);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,one);		
delay_ms(500);
writePin(protB,Pin15,zero);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);			
		
	clear_interrupt(Pin12);
	}	
	
	if(checkPR(Pin13)){
writePin(protB,Pin15,zero);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,one);
			delay_ms(500);
	clear_interrupt(Pin13);
	}
	
		if(checkPR(Pin14)){

writePin(protB,Pin15,one);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,one);
			delay_ms(500);
writePin(protB,Pin15,zero);
writePin(protB,Pin14,one);	
writePin(protB,Pin13,one);
writePin(protB,Pin12,zero);
	clear_interrupt(Pin14);
	}
		
			if(checkPR(Pin15)){

writePin(protB,Pin15,one);
writePin(protB,Pin14,one);	
writePin(protB,Pin13,one);
writePin(protB,Pin12,one);
			delay_ms(500);
writePin(protB,Pin15,zero);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);
	clear_interrupt(Pin15);
	}

	
	

}



int main(){
 

	
	
	
	      protA.GPIO_Port_Name=PortC;
        protA.GPIOx=GPIOC;
	
        protA.pins[0]=Pin10;
	      protA.Mode[0]=Mode_Input_In_PullDown;
	
	      protA.pins[1]=Pin11;
	      protA.Mode[1]=Mode_Input_In_PullDown;
	       
	      protA.pins[2]=Pin12;
	      protA.Mode[2]=Mode_Input_In_PullDown;
        
       	protA.pins[3]=Pin13;
	      protA.Mode[3]=Mode_Input_In_PullDown;
				
				protA.pins[4]=Pin14;
	      protA.Mode[4]=Mode_Input_In_PullDown;
	
       	protA.pins[5]=Pin15;
	      protA.Mode[5]=Mode_Input_In_PullDown;
				
	      setUpPort(protA);
	
	
        protB.GPIO_Port_Name=PortB;
        protB.GPIOx=GPIOB;
	
        protB.pins[0]=Pin15;
	      protB.Mode[0]=Mode_Output_2MHz_Push_Pull;
	
	      protB.pins[1]=Pin14;
	      protB.Mode[1]=Mode_Output_2MHz_Push_Pull;
	
	      protB.pins[2]=Pin13;
	      protB.Mode[2]=Mode_Output_2MHz_Push_Pull;
	
	      protB.pins[3]=Pin12;
	      protB.Mode[3]=Mode_Output_2MHz_Push_Pull;
        
        setUpPort(protB);
        
        
				Interrupt_Init(PortC,Pin10,Rising_Edge,Priority_10,EXTI15_10_IRQn);
        Interrupt_Init(PortC,Pin11,Rising_Edge,Priority_10,EXTI15_10_IRQn);
				Interrupt_Init(PortC,Pin12,Rising_Edge,Priority_10,EXTI15_10_IRQn);
				Interrupt_Init(PortC,Pin13,Rising_Edge,Priority_10,EXTI15_10_IRQn);
				Interrupt_Init(PortC,Pin14,Rising_Edge,Priority_10,EXTI15_10_IRQn);
				Interrupt_Init(PortC,Pin15,Rising_Edge,Priority_10,EXTI15_10_IRQn);
        
        
        while(1){

      
			writePin(protB,Pin15,zero);
writePin(protB,Pin14,zero);	
writePin(protB,Pin13,zero);
writePin(protB,Pin12,zero);
			  
        


}
				


}
