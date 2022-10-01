#define F_CPU 16000000UL

#include <avr/io.h>
#include <stdbool.h>
#include "serial/serial.h"

int main(){

    serialSetBaudrate(9600);
    serialInit();

    while(true){

        char readBuffer[20];
        int bufferLength = 0;

        while(serialAvailable()){
            readBuffer[bufferLength] = serialRead();
             
            if(readBuffer[bufferLength] == '\n') {
                bufferLength++;
                break;
            }
            bufferLength++;
        }

        if(bufferLength != 0){
            serialSendArray(readBuffer, bufferLength);
        }

        
    }

}