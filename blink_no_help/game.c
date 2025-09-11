#include "stm32f4xx.h"
#include "stm32f401xe.h"

#define AHB1ENR_OFFSET 0x30UL
#define ENABLE (*(volatile unsigned int*) (RCC_BASE + AHB1ENR_OFFSET))



#define MODER (*(unsigned volatile int*) GPIOA_BASE)


#define ODR (*(unsigned volatile int*) (GPIOA_BASE + 0x14UL))
//Plan
//Enable GPIOA port through AHB1 Enable Register
//Set PA5 to gpio mode through the GPIOA Moder register
//In a while loop set the output (ODR Register) to toggle every half second

int main(void){
	ENABLE |= RCC_AHB1ENR_GPIOAEN; //enable clock for GPIOA port
	MODER &= ~(3UL<<10);
	MODER |= 1UL << 10; //set PA5 to general GPIO mode
	while(1){
		for (int i = 0; i < 8000000; i++);
		ODR ^= GPIO_ODR_OD5;
	}

}
