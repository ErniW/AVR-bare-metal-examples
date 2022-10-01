## 115200 baudrate
To set the baudrate to 115200 you need to change the equation to 
`((F_CPU / 8 + baudrate / 2) / baudrate - 1)` 

and set `U2X0` in  `UCSR0A` register, otherwise it won't work.
