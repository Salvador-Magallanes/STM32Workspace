#compiler
CC = arm-none-eabi-gcc
#converts a file to another format
OBJCOPY=arm-none-eabi-objcopy
#variable "starting point" to make traversal easier
DIRECTORY = ../tools/STM32Cube_FW_F4_V1.28.0
#linker file
LINKER = -T ../STM32F401RETX_FLASH.ld -nostdlib -nostartfiles 
CFLAGS = -O2 -Wall $(LINKER) -mthumb -mcpu=cortex-m4

#core_cm4.h
CFLAGS += -I $(DIRECTORY)/Drivers/CMSIS/Include 

#stm32f401xe.h and stm32f4xx.h
CFLAGS += -I $(DIRECTORY)/Drivers/CMSIS/Device/ST/STM32F4xx/Include
#I guess default target to ensure we build both main.elf and main.bin
all: main.bin main.elf

# example "rule" in a makefile
#target : dependencies
#	recipe (what to do)

#make will look for a rule to create each of the dependencies
main.elf: startup_stm32f401xe.o system_stm32f4xx.o main.o
	$(CC) $(CFLAGS) $^ -o $@

#%.o: %.c means that we will make an object file if the .c version of the file exists
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@
main.bin: main.elf
	$(OBJCOPY) -O binary $< $@
clean:
	rm -f *.o *.bin
