#include "stm32f4xx.h"
#include "stm32f401xe.h"
#include "stdint.h"

/*
PLAN

Produce a PWM output signal that can control the operation of a servo motor

Servo frequency is 50Hz with 0 degrees at 5% duty cycle (1ms) and 180 degrees at 10% duty cycle (2ms)

The angle of the servo and the duty cycle are linear

NOTES

Frequency set by the value of the TIMX_ARR register and duty cycle from TIMx_CCRx

PWM mode is chosen by writing 110 or 111 to OCxM bits of TIMx_CCMRx register

User needs to enable preload register by settings OCxPE bit in TIM_CCMRx, then ARPE in TIMx_CR1

Before starting counter, all registers must be initialized by setting UG bit in TIMx_EGR

Upcounting mode set by having DIR in TIMx_CR1 low


PWM mode 1 has high before count is reached (can be done by mode 2 with polarity swap but nah no thanks)

Will use TIM2 Channel 1 (alternate function 1 of PA1)


PWM frequency = CLK_in / ((ARR + 1)(PSC + 1))

*/
uint16_t PRESCALER_VAL = 3199; //used to prescale the clock from 16 MHz to 250 Hz

int main(){
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable the clock for port A
    RCC->APB1ENR |= 0b1; //enable TIM2

    RCC->CFGR |= 0b10 << 10;
    GPIOA->MODER |= (0b10 << 2); //set PA1 to alternate function mode
    GPIOA->AFR[0] |= (0b1 << 4); //set PA1 to alt function 1 (TIM2 CH2)


    TIM2->PSC = PRESCALER_VAL;
    TIM2->ARR = 99;
    
    TIM2->CCR2 |= 5; //duty cycle

    TIM2->CCMR1 |= 0b110 << 12; //pwm mode 1
    TIM2->CCMR1 |= 0b1 << 11; //enable preload (OCxPE)
    TIM2->CCER |= 1 << 4;
    TIM2->CR1 |= 1 << 7; //arpe
    TIM2->EGR |= 1; //update changes
    TIM2->CR1 |= 1; //counter enable

    
}
