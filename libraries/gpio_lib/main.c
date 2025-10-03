#include "gpio_lib.h"
#include "stm32f401xe.h"
// test code for gpio library

int main(){
    enable_gpio_port(PORTA);
    set_gpio_pin_mode(PORTA,5,OUTPUT);
    

    while (1){
        
        set_output_pin_state(PORTA, 5, 1);
        for (volatile int i = 0; i < 8000000; i++); //VERY IMPORTANT THAT THESE ARE VOLATILE OMG

        set_output_pin_state(PORTA, 5, 0);
        for (volatile int i = 0; i < 8000000; i++); //next time im using timers i stg
    }
    
    


}
