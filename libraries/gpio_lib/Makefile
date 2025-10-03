CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

MAIN_DIRECTORY = ../../tools/STM32Cube_FW_F4_V1.28.0
LINKER = -T ../../STM32F401RETX_FLASH.ld -nostdlib -nostartfiles

CFLAGS = -O2 -Wall $(LINKER) -mthumb -mcpu=cortex-m4 

INCLUDES = -I $(MAIN_DIRECTORY)/Drivers/CMSIS/Include
INCLUDES += -I $(MAIN_DIRECTORY)/Drivers/CMSIS/Device/ST/STM32F4xx/Include
all: main.bin main.elf
main.elf: main.o startup_stm32f401xe.o system_stm32f4xx.o gpio_lib.o
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

system_stm32f4xx.o: ../../system_stm32f4xx.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
 
startup_stm32f401xe.o: ../../startup_stm32f401xe.s
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
main.bin: main.elf
	$(OBJCOPY) -O binary $< $@

gpio_lib.o: gpio_lib.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
	
clean:
	rm -f *.o
