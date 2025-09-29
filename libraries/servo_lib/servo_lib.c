#include "servo_lib.h"
#include "gpio_lib/gpio_lib.h"
/*
    This library is meant to make easier interfacing with servo motors (50 Hz with a range of 1-2 ms (5-10%) duty cycle)

*/



typedef enum {
    HSE,
    HSI,
} clock_source;


void servo_setup(gpio_ports port, int pin, int alt_func){
    enable_gpio_port(port);
    set_gpio_pin_mode(port, pin, ALTERNATE_FUNCTION);



}


