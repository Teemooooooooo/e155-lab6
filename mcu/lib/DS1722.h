// DS1722.h
// Ellen Yu
// ellyu@g.hmc.edu
// Oct. 8 2026
// TODO: <SHORT DESCRIPTION OF WHAT THIS FILE DOES>


#ifndef DS1722_H
#define DS1722_H

#include <stdint.h>
#include "STM32L432KC_GPIO.h"
#include "STM32L432KC_SPI.h"
#include <stm32l432xx.h>


void initTemp();

void changeRes(char res);

float readTemp();

#endif
