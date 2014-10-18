//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Jason Cerundolo                                   //
//  Date    : 17 Oct, 2014                                      //
//  Version : 0.1                                               //
//  Notes   : Code to test two full digits of clock.            //
//            Counts down from 10 seconds by 0.1 s.             //
//****************************************************************

// Refer to schematic to find correct pin on segment board
int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int enablePin = 9;
int j = 0;

// From wikipedia, A is bit 0, G is bit 6, DP is bit 7
char font[16] = { 0x3F, 0x06, 0x5B, 0x4F, \
                  0x66, 0x6D, 0x7D, 0x07, \
                  0x7F, 0x6F, 0x77, 0x7C, \
                  0x39, 0x5E, 0x79, 0x71 };

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  if (j > 99) {
    j = 0;
  }
  
  digitalWrite(latchPin, LOW);
  // Arduino is connected to right most digit
  shiftOut(dataPin, clockPin, MSBFIRST, font[(99-j)/10]|(1<<7));
  shiftOut(dataPin, clockPin, MSBFIRST, font[(99-j)%10]);
  digitalWrite(latchPin, HIGH);
  delay(100);
  j++;
}

