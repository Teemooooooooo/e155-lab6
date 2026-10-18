// DS1722.c
// Ellen Yu
// ellyu@g.hmc.edu
// Oct. 8 2026
// initialize temp sensor, write to sensor, read from sensor

#include "DS1722.h"

void initTemp(){
    digitalWrite(OUTPUT_PIN, 1);
    spiSendReceive(0x80); // place to write to
    spiSendReceive(0xF0); // configuration
    digitalWrite(OUTPUT_PIN, 0);
}

void changeRes(char res){
    digitalWrite(OUTPUT_PIN, 1);
    spiSendReceive(0x80); // place to write to
    spiSendReceive(res); // resolution configuration
    digitalWrite(OUTPUT_PIN, 0);

}


// for read, read each of them individually then add together 
float readTemp(){
    digitalWrite(OUTPUT_PIN, 1);
    spiSendReceive(0x01); // place to read from
    int lsb = spiSendReceive(0xFF); // send trash in to read stuff out
    digitalWrite(OUTPUT_PIN, 0);

    digitalWrite(OUTPUT_PIN, 1);
    spiSendReceive(0x02); // place to read from
    int msb = spiSendReceive(0xFF); // send trash in to read stuff out
    digitalWrite(OUTPUT_PIN, 0);
    float temp = (msb+lsb/256.0);
    // handling negative temp
    if (temp > 256){
        temp = -(temp - 256);
    }

    return temp
}


