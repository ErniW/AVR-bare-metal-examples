## On receive interrupt
1. Enable the `RXCIE0` interrupt in `UCSR0B` register and include appropriate interrupt handler `USART_RX_vect`. Remember to enable interrupts in `SREG` register.
2. Now you can see that sending the char changes the LED immediately.