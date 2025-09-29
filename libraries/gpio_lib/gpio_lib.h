#ifndef GPIO_LIB
#define GPIO_LIB
#endif

typedef enum {
    PORTA, 
    PORTB,
    PORTC,
    PORTD
}gpio_ports;

typedef enum {
    INPUT = 0b00, 
    OUTPUT = 0b01,
    ALTERNATE_FUNCTION = 0b10,
    ANALOG = 0b11
}gpio_modes;


void enable_gpio_port(gpio_ports);

void set_gpio_pin_mode(gpio_ports port, int pin, gpio_modes mode);

void set_output_pin_state(gpio_ports port, int pin, int state);