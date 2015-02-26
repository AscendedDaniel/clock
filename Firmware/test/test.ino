//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Jason Cerundolo                                   //
//  Date    : 15 Oct, 2014                                      //
//  Version : 0.1                                               //
//  Notes   : Code to test full digit of clock                  //
//****************************************************************

#include <SPI.h>

int latchPin = 8;
int clockPin = 13;
int dataPin = 11;
int enablePin = 9;
int j = 0;

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
  if (j > 8) {
    j = 0;
    shiftByteAllTheWay(0xFF);
    delay(1000);
    shiftByteAllTheWay(0x00);
    delay(1000);
    shiftByteAllTheWay(0xFF);
    delay(1000);
  }
  
  shiftByteAllTheWay(1<<j);
  delay(125);
  j++;
}

void shiftByteAllTheWay(byte data) {
  //digitalWrite(latchPin, LOW);
  for (int i; i<100; i++)
  {
//    shiftOut(dataPin, clockPin, MSBFIRST, data);
    SPI.transfer(data);
    delayMicroseconds(1000);
  }
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(latchPin, LOW);
}
