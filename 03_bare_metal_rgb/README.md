## RGB LED
Now let's connect an RGB LED. Connect each of its colors to Arduino pin 10, 11, 12 which corresponds to PB2, PB3, PB4. I've intentionally selected pins of the same port to simplify code.

Bitwise operations can be concatenated. To store multiple bits in a single variable `RGB_LED` and toggle colors all at once, we can use `char` variable as a single byte, or `uint8_t` (8-bit unsigned int). 

	uint8_t RGB_LED = (1<<PB4) | (1<<PB3) | (1<<PB2);

*We could set it to `0b00011100` or `28`.*

To blink white color, we can use our RGB_LED variable. Try to write code to blink the colors separately. In next example I'll show how to do that using only bit shifting.
