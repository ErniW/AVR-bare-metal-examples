## UART communication
Basic example of receiving and sending back a single char. If you send `x` the Arduino LED on pin 13 will turn on.

For this example you should send chars without line ending. Otherwise the led will turn off because of `\n` char sent after.

You can use the Arduino IDE serial monitor if you don't want install additional software.

*There are various settings of serial communciation I will not cover everything.*

*The documentation includes some code examples.*

### Setup:
**To setup both receiving and transmitting data we need to:**
- Set serial baudrate.
- Enable RX and TX.

To set the baudrate to 9600 in `UBRR0` register use the formula: `(F_CPU/(baudrate*16))-1`. Or set it directly with values provided in table 19.11 **Examples of Baud Rate Setting**.

The `UCSR0B` register bits `RXEN0` and `TXEN0` enables the UART transmission. And the `UCSR0C` can set stop bits and parity bits depending on what you need and how do you want to handle corrupted packets.

### Sending and receiving chars:
Because **RX and TX uses same buffer register** we need to check its availability with the `RXC0` flag for receive event or `UDRE0` when buffer is empty.

- To read a received char we need to check if anything is available in our port and then read it from `UDR0` register.

- Sending functionwaits for empty buffer and fills the `UDR0` register.

*Receiving single chars is easy but things get more complicated with buffer arrays.*