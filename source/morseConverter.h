// morceConverter.h: header file for morseConverter

#ifndef _MORSECONVERTER_H_
#define _MORSECONVERTER_H_

#include <stdint.h>

//void delayShort();
//void delayLong();

void readString(char *buffer, uint32_t length);
void runSimulation(void);

void charToMorse(char character);

extern void number1();
extern void number2();
extern void number3();
extern void number4();
extern void number5();
extern void number6();
extern void number7();
extern void number8();
extern void number9();
extern void number0();

extern void delayShort();
extern void delayLong();

extern void dot();
extern void dash();

#endif
