## RGB LED blinking red, green and blue separately using only bit-shifting.

`7 << 2` means that we want to place our three "1" bits of PB2, PB3, PB4. 7 is equal to binary `0b00000111` (you can check that in calculator on Windows) and move bits two places to the left `0b00011100`.

### Blinking each color
1. Set the third bit (PB2) by shifting 1 by two places `0b00000001` -> `0b00000100`.
2. Move that single bit to next color. `<<=` means `PORTB = PORTB << 1;`
3. Do the same thing for third color.
4. Clear the register by setting it to 0 (and all bits inside).


