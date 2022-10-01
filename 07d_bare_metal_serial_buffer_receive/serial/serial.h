#pragma once

void serialSetBaudrate(unsigned long baudrate);
void serialInit();
bool serialAvailable();
void serialSend(unsigned char data);
unsigned char serialRead();