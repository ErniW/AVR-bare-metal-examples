# AVR bare metal examples
A series of basic bare metal AVR development examples written in C. Sometimes I show some of them to my students when they ask me how microcontrollers are programmed without Arduino. Examples should be read in proposed order.

## Prerequisities
### Hardware:
- Arduino UNO, examples are prepared for ATMega328p.
- Programmer, for example Pololu AVR Programmer V2.
- RGB LED.
- Button.
- 2x potentiometers or photoresistors.
- Servo, (sg-90 is enough).
- MPU6050 accel/gyro.
- Simple 2x16 LCD display for SPI.

### Software:
- Visual Studio Code or Microchip Studio (or any other depending on your choice).
- If you want to use command line interface with AVR toolchain you need AVR-GCC, AVR-DUDE and GNU MAKE.

*Software requirements are explained in example 2. I'm using AVR toolchain and Visual Studio Code, you can copy and paste code if you decide to use other solutions.*

### Skills:
- Arduino programming. Everything else is described in readme of each example.

### Documentation of ATMega328p:
https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
