#include "stm32f4xx.h"
#include "stm32f401xe.h"
#include "stdint.h"
/*
Plan
I want an external pushbutton that can toggle an external LED when its pressed

Execution
	- Enable the clock for the GPIO ports (Will use PA11 for the button and PA12 for the light)
	- Set the mode for the gpio pins (00 input and 01 GPIO out)
	- Store an old input value in a variable
	- Read from the IDR at the bit of button
	- Compare value (if new == low and old == high)
	- Toggle LED


*/


//placeholder comment
int main(){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN_Msk; //enable the clock for port A
	GPIOA->MODER &= ~(0b11 << (2 * 11)); //Lower PA11 bits for input
	
	GPIOA->MODER &= ~(0b1 << (2 * 12 + 1)); //disable upper bit of PA12
	GPIOA->MODER |= (0b1 << (2 * 12)); //enable lower bit of PA 12
	uint16_t old_val = 0; //placeholder for the old value
	while (1){
		uint16_t new_val = (GPIOA->IDR & (0b1 << 11)) >> 11; //get new reading to compare to old

		if (new_val == 0b1U && old_val == 0b0U){ //button is high and previously wasnt
			GPIOA->ODR ^= (0b1 << 12); //toggle the value at PA12
		}
		old_val = new_val; //needed to prevent multiple presses (if always low anytime PA11 is high itll toggle LED)
	}

	
}
