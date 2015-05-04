//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Jason Cerundolo                                   //
//  Date    : 15 Oct, 2014                                      //
//  Version : 0.1                                               //
//  Notes   : Code to test full digit of clock                  //
//****************************************************************

#include <SPI.h>

// From wikipedia, A is bit 0, G is bit 6, DP is bit 7
const char font[16] = { 0x3F, 0x06, 0x5B, 0x4F, \
                  0x66, 0x6D, 0x7D, 0x07, \
                  0x7F, 0x6F, 0x77, 0x7C, \
                  0x39, 0x5E, 0x79, 0x71 };

const char font_inverted[16] = { 0x3F, 0x30, 0x5B, 0x79, \
                           0x74, 0x6D, 0x6F, 0x38, \
                           0x7F, 0x7D, 0x7E, 0x67, \
                           0x0F, 0x73, 0x4F, 0x4E };

int latchPin = 8;
int clockPin = 13;
int dataPin = 11;
int enablePin = 9;
long j = 0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  digitalWrite(latchPin, LOW);
  
  SPI.begin();
  SPI.setClockDivider(128);
  SPI.setBitOrder(MSBFIRST);
//  SPI.setDataMode(SPI_MODE0);
}

void loop() {
  if (j > 10000000) {
    j = 0;
  }
  
  SPI.transfer((font[j%10]));
  SPI.transfer((font_inverted[j/10%10])|(1<<7));
  SPI.transfer((font[j/100%10])|(1<<7));
  SPI.transfer((font_inverted[j/1000%10])|(1<<7));
  SPI.transfer((font[j/10000%10])|(1<<7));
  SPI.transfer((font_inverted[j/100000%10])|(1<<7));
  SPI.transfer((font[j/1000000%10])|(1<<7));
  delayMicroseconds(10);
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(latchPin, LOW);
  delay(250);
  j++;
}

