#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdlib.h>
#include <util/delay.h>

#include "serial/serial.h"
#include "i2c/i2c.h"

#define MPU6050 0x68 << 1

void sendValue(uint16_t val){
    char data[7] = {0};
    itoa(val, data, 10);
    serialSendArray(data, 7);
    serialSend(',');
}

int main(){

    serialSetBaudrate(9600);
    serialInit();

    i2c_init();

    sei();

    _delay_ms(100);
    
    i2c_write(MPU6050, 0x6B, 0x00);
    i2c_write(MPU6050, 0x1B, 0x00);
    i2c_write(MPU6050, 0x1C, 0x00);

    uint8_t buffer[6];

    while(true){

        i2c_read_from_register(MPU6050, 0x3B, buffer, 6);

        int16_t ax = (buffer[0]<<8 | buffer[1]);
        int16_t ay = (buffer[2]<<8 | buffer[3]);
        int16_t az = (buffer[4]<<8 | buffer[5]);

        i2c_read_from_register(MPU6050, 0x43, buffer, 6);

        int16_t gx = (buffer[0]<<8 | buffer[1]);
        int16_t gy = (buffer[2]<<8 | buffer[3]);
        int16_t gz = (buffer[4]<<8 | buffer[5]);

        sendValue(ax);
        sendValue(ay);
        sendValue(az);
        sendValue(gx);
        sendValue(gy);
        sendValue(gz);
        serialSend('\n');
    };
}



