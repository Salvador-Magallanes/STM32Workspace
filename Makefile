
CC=arm-none-eabi-gcc

#used for later binary conversion
OBJCOPY=arm-none-eabi-objcopy

#flashing linker

FLASH=STM32F401RETX_FLASH.ld

#directory housing the stm32f4 trash
STM_COMMON=/home/salvador/Documents/The_Silly/embedded/tools/stm32cubef4-v1-28-0/STM32Cube_FW_F4_V1.28.0

#Compiler flags
CFLAGS = -O2 -Wall -T $(FLASH) -nostartfiles -nostdlib
CFLAGS += -mthumb -mcpu=cortex-m4

CFLAGS += -I$(STM_COMMON)/Drivers/CMSIS/Include
CFLAGS += -I$(STM_COMMON)/Drivers/CMSIS/Device/ST/STM32F4xx/Include

all: main.elf main.bin

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
