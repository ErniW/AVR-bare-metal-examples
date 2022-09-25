## Blinking an LED
### We need 3 things:
- Find the port of Arduino LED pin 13.
- Set that pin to output.
- Toggle that pin to blink the LED.

### Reading the documentation:
- Understanding how to read things is more important than remembering. It’s a basic overview so I will cover only necessary things.
- Each register has its name and address in which bits are stored.  To simplify coding their names can be used directly in code.
- The first, lowest bit, is the rightmost.

### What we need to blink the LED:
1. **The Arduino UNO pin 13 corresponds to pin PB5 of ATMega328p.** It’s not in documentation but the pinout can be easily found. 
2. In chapter 13.4 we can find I/O registers. **PB5 means that the pin is located in port B and 5th bit starting from right.**
3. **Set the pin mode to output in The Port B Data Direction Register** (13.4.3 DDRB).
4. **The pin state is stored in The Port B Data Register** (13.4.2 PORTB).

## Many ways of handling bits in registers:
**The not recommended way is to set the register bits by hard-coding them.** Using the so called “magic numbers” is unreadable also in basic examples. The `32` is a decimal value of binary `00100000` in 8 bit system eventually setting the 5th pin to output. 

     DDRB = 32;
     DDRB = 0b00100000;

We could set it using **bit shift operator** `1 << n` which will **move all bits to left** by **n** positions. The 1 means we shift `00000001` 5 places to left.

     DDRB = (1 << 5);
     DDRB = (1 << PB5);
     
**Hard-coding affects all the bits in a register, usually we want to change only the desired bit. To do so, we need to use bit-wise operations using bit masking.**

### Bit-wise operations to remember by heart:
- **To set the bit** `|=`
- **To clear the bit** (set to 0) `&=~`
- **To toggle the bit** `^=`

### Finally, to set the bit 5 you should choose one of the following:

     DDRB |= (1 << PB5);
     DDRB |= PB5;
     DDRB |= _BV(PB5); //set the Bit Value, available through avr library
     
Using pre-defined macros such as DDRB and PB5 is preferred, otherwise you should create your own or you’ll end up with code like this:
     `*((volatile byte*)0x24) |= (1 << 5);`
     
If you aren’t familiar with pointers (* sign) and what volatile do, now it’s a good moment to read about them. Pointer is a variable storing an address where a value is held instead of the value itself, in this case it’s the address of register.

For now instead of Arduino’s `delay(500);` we shall use `_delay_ms(500);`

*Important: unlike Arduino functions which are portable, the registers are specified for particular microcontroller – the code for ATMega328p won’t work on other architectures.*
