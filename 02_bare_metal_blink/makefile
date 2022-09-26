mcu = atmega328p
baudrate = 115200
port = COM6
programmer = stk500
fuses = -Ulock:w:0x3F:m -Uefuse:w:0x05:m -Uhfuse:w:0xDE:m -Ulfuse:w:0xFF:m

build:
	avr-gcc -mmcu=$(mcu) -Wall -Os -o blink.elf main.c
	avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex

upload:
	avrdude -p $(mcu) -P $(port) -b $(baudrate) -c $(programmer) -e -U flash:w:blink.hex $(fuses)