## Receive a char array.
The code in main loop will listen for any incoming data and read it until the endline character is sent.

*Things start to get tricky here, especially if you try using delays or do a lot of computations in between. The buffer can lose the data or get an overflow error. In the next example I'll show interrupts but it's not as easy to avoid these issues.*