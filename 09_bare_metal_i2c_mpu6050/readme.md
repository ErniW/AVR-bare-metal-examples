## I2C with MPU6050
The ATMega i2c protocol is described in **chapter 21. 2-wire Serial Interface** commonly called TWI.

We'll use the documentation provided by manufacturer:
https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf

*I'm intentionally not going deep into i2c specification - you can google it.*

*Please notice that i2c messages are described in hexadecimal format - for example `0x68` is equal to `104` in decimal.*

### Settings:
There are various settings similarly to things we did before. The only thing I do is enabling the i2c and setting it's frequency to 400kHz.

### The address:
**MPU6050 has 7-bit address 0x68.** It's important to shift it by one bit to fill an 8-bit byte. We do that to make place for read/write direction flag which puts the i2c sensor into writing mode so we can listen for data. *Some sensors can use 10-bit address so always check that in documentation*.

### Writing via i2c bus:
**Generally, the protocol consists of three steps:**
1. Send the address byte to choose a sensor.
2. Send the register address to choose which register we are setting.
3. Write the values to that register or start listening until all bytes are received.

**It's simple but remember that in between there are:**
- Start and stop bits of transmission.
- ACK and NACK. The data is transfered synchronously upon request so we need to acknowledge when a bit is received and wait before we proceed forward.

### Reading values from MPU6050:
In documentation chapters 4.17 **Accelerometer Measurements** and 4.19 **Gyroscope Measurements** we can see that **each axis is composed of high and low bytes (8-bit) producing a 16-bit value** by concatenating them into single `int16_t`. By calling the first register of data the sensor will automatically queue other readings until we send stop message. We have to store them in a buffer.

To concatenate high and low bytes we do it with bit-shift operator, you'll use that method every time such coversion is required:

    int16_t ax = (highByte << 8 | lowByte);

You need to store the X, Y, Z values according to their order.

Before the main loop I've included the `0x6B`, `0x1B`, `0x1C` register settings. The first one makes sure that the device is restarted on startup - sometimes it's necessary to turn on the sensor. Others set the Accel/Gyro sensitivity to default. There are many more settings so spend a few minutes to read what Arduino library hides behind its functions.

*It's a common practice to create #define for them, otherwise its difficult to understand what's going on.*

In i2c functions I'm using `loop_until_bit_is_set(TWCR, TWINT);`. It's the same as `while ( !(TWCR & (1 <<TWINT)));`.