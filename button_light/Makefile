CC = arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
DIRECTORY = /home/salvador/Documents/The_Silly/embedded/tools/STM32Cube_FW_F4_V1.28.0
LINKER = -T ../STM32F401RETX_FLASH.ld -nostdlib -nostartfiles
CFLAGS = -O2 -Wall $(LINKER) -mthumb -mcpu=cortex-m4
CFLAGS += -I $(DIRECTORY)/Drivers/CMSIS/Include
CFLAGS += -I $(DIRECTORY)/Drivers/CMSIS/Device/ST/STM32F4xx/Include
all: main.bin main.elf

main.elf: startup_stm32f401xe.o system_stm32f4xx.o main.o
	$(CC) $(CFLAGS) $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@
main.bin: main.elf
	$(OBJCOPY) -O binary $< $@
clean:
	rm -f *.o *.elf *.bin
