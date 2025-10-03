#include "stm32f4xx.h"
#include "stm32f401xe.h"
#include "stdint.h"
#include "gpio_lib.h"


/*
This library is meant to make interfacing with a GPIO pin simpler

Functionality of this library
- Enable clock to GPIO ports
- Set the GPIO Mode for a specific pin
- Set the output type for a specific pin
- Set the output speed for a specific pin


*/



void enable_gpio_port(gpio_ports port){
    RCC->AHB1ENR |= 1 << port;

    switch (port){
        case PORTA:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; 
            break;
        case PORTB:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
        case PORTC:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
        case PORTD:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
        case PORTE:
            RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
    }

}

void set_gpio_pin_mode(gpio_ports port, int pin, gpio_modes mode){
    uint16_t pin_mode = 0b00; //used to clear the mode bits of a pin (clean slate type beat)
    pin_mode += mode;

    switch (port){
        case PORTA:
            GPIOA->MODER |= pin_mode << (pin * 2);
        case PORTB:
            GPIOB->MODER |= pin_mode << (pin * 2);
        case PORTC:
            GPIOC->MODER |= pin_mode << (pin * 2);
        case PORTD:
            GPIOD->MODER |= pin_mode << (pin * 2);
        case PORTE:
            GPIOE->MODER |= pin_mode << (pin * 2);
    }

}

void set_output_pin_state(gpio_ports port, int pin, int state){
   
    switch (port){
        case PORTA:
            GPIOA->BSRR = (1U << (pin + 16)); //clear the pin before setting the state
            GPIOA->BSRR = (state << pin);
            break;
        case PORTB:
            GPIOB->BSRR = (1U << (pin + 16)); //clear the pin before setting the state
            GPIOB->BSRR = (state << pin);
            break;
        case PORTC:
            GPIOC->BSRR = (1U << (pin + 16)); //clear the pin before setting the state
            GPIOC->BSRR = (state << pin);
            break;
        case PORTD:
            GPIOD->BSRR = (1U << (pin + 16)); //clear the pin before setting the state
            GPIOD->BSRR = (state << pin);
            break;
        case PORTE:
            GPIOE->BSRR = (1U << (pin + 16)); //clear the pin before setting the state
            GPIOE->BSRR = (state << pin);
            break;
        
    }

}