#pragma once

#include <avr/io.h>

void i2c_init();
void i2c_start(void);
void i2c_stop(void);
void i2c_write_byte(uint8_t data);
void i2c_write(char address, char reg, char value);
void i2c_read_from_register(char address, char reg, uint8_t* data, int len);
uint8_t i2c_read(bool ack);