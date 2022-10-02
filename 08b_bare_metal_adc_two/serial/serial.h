#pragma once

void serialSetBaudrate(unsigned long baudrate);
void serialInit();
bool serialAvailable();
void serialSendArray(char* buffer, int length);
void serialSend(unsigned char data);
unsigned char serialRead();