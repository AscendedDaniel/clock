//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Jason Cerundolo                                   //
//  Date    : 15 Oct, 2014                                      //
//  Version : 0.1                                               //
//  Notes   : Code to test full digit of clock                  //
//****************************************************************

int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int enablePin = 9;
int j = 0;

// From wikipedia, A is bit 0, G is bit 6, DP is bit 7
char font[32] = { 0x3F, 0x06, 0x5B, 0x4F, \
                  0x66, 0x6D, 0x7D, 0x07, \
                  0x7F, 0x6F, 0x77, 0x7C, \
                  0x39, 0x5E, 0x79, 0x71, \
                  0xBF, 0x86, 0xDB, 0xCF, \
                  0xE6, 0xED, 0xFD, 0x87, \
                  0xFF, 0xEF, 0xF7, 0xFC, \
                  0xB9, 0xDE, 0xF9, 0xF1 };

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
}

void loop() {
  if (j > 31) {
    j = 0;
  }
  
  digitalWrite(latchPin, LOW);
  //shiftOut(dataPin, clockPin, LSBFIRST, font[j]);
  shiftOut(dataPin, clockPin, MSBFIRST, font[j]);
  digitalWrite(latchPin, HIGH);
  delay(1000);
  j++;
}

