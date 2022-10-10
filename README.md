# AVR bare metal examples
A series of introductory bare metal AVR development examples written in C for someone who want to move outside of Arduino development. I show some of them to my students to briefly explain how microcontrollers are programmed without Arduino. 

I've included guides for each example. They should be read in proposed order.

### Things covered:
- Understanding registers and configure them with bit-wise operations.
- Configuring registers for AVR internals and peripherals.
- Using the programmer and makefiles independently via command line interface (CLI) from any IDE.

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
