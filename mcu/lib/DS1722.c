// DS1722.c
// Ellen Yu
// ellyu@g.hmc.edu
// Oct. 8 2026
// initialize temp sensor, write to sensor, read from sensor

#include "DS1722.h"

void initTemp(void){
    spiSendReceive(0x80); // place to write to
    spiSendReceive(0xF0); // configuration
}

void changeRes(char res){
    spiSendReceive(0x80); // place to write to
    spiSendReceive(res); // resolution configuration

}


// for read, read each of them individually then add together 
float readTemp(void){
    spiSendReceive(0x01); // place to read from
    int lsb = spiSendReceive(0xAA); // send trash in to read stuff out

    spiSendReceive(0x02); // place to read from
    int msb = spiSendReceive(0xAA); // send trash in to read stuff out
    float temp = (msb+lsb/256.0);
    // handling negative temp
    if (temp > 128){
        temp = -(temp - 128);
    }

    return temp;
}


