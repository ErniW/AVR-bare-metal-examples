#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "i2c.h"

void i2c_init(){
	//set SCL to 400kHz
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable TWI
	TWCR = (1<<TWEN);
}

void i2c_write(char address, char reg, char value){
	
	i2c_start();
	
	i2c_write_byte(address);
	i2c_write_byte(reg);
	i2c_write_byte(value);
	
	i2c_stop();
}

void i2c_read_from_register(char address, char reg, uint8_t* data, int len){
	
	i2c_start();
	
	i2c_write_byte(address);
	i2c_write_byte(reg);
	i2c_start();
	i2c_write_byte(address | 1);
	
	for(int i = 0; i<len-1; i++){
		data[i] = i2c_read(true);
	}	
    data[len-1] = i2c_read(false);
   	// TWCR = (1<< TWINT) | (1<<TWEN);
	// while ( !(TWCR & (1 <<TWINT)));
	i2c_stop();
} 

void i2c_start(void){
	TWCR = _BV(TWINT) | _BV(TWEN) | _BV(TWSTA);
	loop_until_bit_is_set(TWCR, TWINT);
}

void i2c_stop(void){
	TWCR = _BV(TWINT)| _BV(TWEN)| _BV(TWSTO);
	loop_until_bit_is_clear(TWCR, TWSTO);
}

void i2c_write_byte(uint8_t data){
	TWDR = data;
	TWCR = _BV(TWINT) | _BV(TWEN);
	loop_until_bit_is_set(TWCR, TWINT);
}

uint8_t i2c_read(bool ack){
	TWCR = ((1<< TWINT) | (1<<TWEN) | (ack<<TWEA));
	while ( !(TWCR & (1 <<TWINT)));
	return TWDR;
}