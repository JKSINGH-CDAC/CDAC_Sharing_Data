while(1)
	{
		//3.SET 9th bit of the output data register to make I/O pin-12 as HIGH
		*pPortDOutReg |= ( 1 << 9);

		//introduce small human observable delay
		//This loop executes for 10K times
		for(uint32_t i=0 ; i < 300000 ; i++ );

		//Tun OFF the LED
		*pPortDOutReg &= ~( 1 << 9);

		for(uint32_t i=0 ; i < 300000 ; i++ );
	}
	
	
	
	
	/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdint.h>

int main(void)
{
	uint32_t  volatile *const pClkCtrlReg =   (uint32_t*)0x40023830;
	uint32_t  volatile *const pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t  volatile *const pPortDOutReg =  (uint32_t*)0x40020C14;

	uint32_t volatile *const pPortAModeReg = (uint32_t*)0x40020000;
	uint32_t const volatile *const pPortAInReg =   (uint32_t*)0x40020010;


	//enable the clock for GPOID , GPIOA peripherals in the AHB1ENR
	*pClkCtrlReg |= ( 1 << 3);
	*pClkCtrlReg |= ( 1 << 0);

    //configuring PD12 as output
	*pPortDModeReg &= ~( 3 << 24);
	//make 24th bit position as 1 (SET)
	*pPortDModeReg |= ( 1 << 24);

	//Configure PA0 as input mode (GPIOA MODE REGISTER)
	*pPortAModeReg &= ~(3 << 0);

	while(1)
	{
		//read the pin status of the pin PA0 (GPIOA INPUT DATA REGISTER)
		uint8_t  pinStatus = (uint8_t)(*pPortAInReg & 0x1); //zero out all other bits except bit 0

		if(pinStatus){
			//turn on the LED
			*pPortDOutReg |= ( 1 << 12);
		}else{
			//turn off the LED
			*pPortDOutReg &= ~( 1 << 12);
		}
	}

}
