## Button and digital input pin
Similarly to Arduino's `pinMode` you can easily set the pin to input (with, or without internal pullup resistor). **You can read how to set them in table 13-1 in I/O ports chapter**

The button is connected to Arduino pin 2 which equals to port `PD2` in ATmega328p. Input is pin default state (when its direction in DDRD is set to 0).

Because I don't want to connect additional resistor, I'm setting its value in `PORTD` to 1 to enable pullup resistor.

Notice the `&` operator in `isPressed` boolean to check if PD2 bit is set to 0 or 1.
