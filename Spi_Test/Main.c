#include "stm32f10x.h"
#include "GPIO_Config.h"
#include "SPI.h"
#include "delay.h"


/*------------------- For  Master Mode----------------------*/



uint16_t  incr=123;
uint8_t Read_Data[10];
uint8_t Write_Data[10];
SPI_Properties propSPI;



int main(){


	
propSPI.SPI_Settings.SPIx=SPI1;
propSPI.SPI_Settings.CPhase=SPI_CPhase_High;
propSPI.SPI_Settings.BaudRatePrescaler= SPI_PCLK_DIV_16;	
propSPI.SPI_Settings.CPol=SPI_CPol_Low;	
propSPI.SPI_Settings.DataSize= SPI_DataSize_8Bit;
propSPI.SPI_Settings.Direction=SPI_Direction_2line_uni;
propSPI.SPI_Settings.Mode= SPI_Mode_Master;
propSPI.SPI_Settings.MSBorLSB=SPI_MSB;
propSPI.SPI_Settings.NSS=SPI_NSS_Software;
propSPI.State= SPI_STATE_READY;	
propSPI.Transciver.Rx_data=Read_Data;
propSPI.Transciver.Tx_data=Write_Data;
propSPI.Irq_State = Irq_State_No_Interrupt;
	
SPI_Init(&propSPI);	


	
	
	
while(1){

 
	Write_Data[0]=0x01;
	Write_Data[1]=0x02;
	Write_Data[2]=0x03;
	Write_Data[3]=0x04;
SPI_Master_Tx(&propSPI,0x23);
SPI_Master_Rx(&propSPI);	
	
	
}





}





void SPI1_IRQHandler(void)
{


	SPI_Irqn(&propSPI);

	

}





