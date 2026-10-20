// DS1722.c
// Ellen Yu
// ellyu@g.hmc.edu
// Oct. 8 2026
// initialize temp sensor, write to sensor, read from sensor

#include "DS1722.h"

void initTemp(void){
digitalWrite(OUTPUT_PIN, PIO_HIGH);
    spiSendReceive(0x80); // place to write to
    spiSendReceive(0xE2); // configuration
    digitalWrite(OUTPUT_PIN, PIO_LOW);
}

void changeRes(char res){
digitalWrite(OUTPUT_PIN, PIO_HIGH);
    spiSendReceive(0x80); // place to write to
    spiSendReceive(res); // resolution configuration
digitalWrite(OUTPUT_PIN, PIO_LOW);
}


// for read, read each of them individually then add together 
float readTemp(void){
digitalWrite(OUTPUT_PIN, PIO_HIGH);
    spiSendReceive(0x01); // place to read from
    int lsb = spiSendReceive(0x00); // send trash in to read stuff out
digitalWrite(OUTPUT_PIN, PIO_LOW);
digitalWrite(OUTPUT_PIN, PIO_HIGH);
    spiSendReceive(0x02); // place to read from
    int msb = spiSendReceive(0x00); // send trash in to read stuff out
    digitalWrite(OUTPUT_PIN, PIO_LOW);
    float temp = (msb+(lsb/256.0f));

     //handling negative temp
    if (temp > 128){
        temp = -(temp - 128);
    }

    return temp;
}


