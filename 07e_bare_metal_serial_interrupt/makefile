project_name = serial_interrupt
mcu = atmega328p
baudrate = 115200
port = COM6
programmer = stk500
fuses = -Ulock:w:0x3F:m -Uefuse:w:0x05:m -Uhfuse:w:0xDE:m -Ulfuse:w:0xFF:m

files = main.c 

create:
	avr-gcc -mmcu=$(mcu) -Wall -Os $(files) -o ./build/$(project_name).elf
	avr-objcopy -j .text -j .data -O ihex ./build/$(project_name).elf ./build/$(project_name).hex

upload:
	avrdude -p $(mcu) -P $(port) -b $(baudrate) -c $(programmer) -e -U flash:w:./build/$(project_name).hex $(fuses)