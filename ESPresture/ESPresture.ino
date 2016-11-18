#include "LedControlMS.h"

/*
  pin 13 is connected to the DataIn / MOSI
  pin 14 is connected to the CLK / SCK
  pin 15 is connected to LOAD / CS
*/
#define SOIL A0
#define NBR_MTX 1  // only one max7219

LedControl lc = LedControl(13, 14, 15, NBR_MTX);

String digits = "1234567890";
unsigned long delaytime = 300;
int soilValue;

/*** Sub Function ***/
void scrollLeft(char);
void scrollRight(char);

void setup() {

  lc.shutdown(0, false);
  lc.setIntensity(0, 1);
  lc.clearDisplay(0);
  Serial.begin (115200);

  //  while(1)  {
  //  byte a[6] = {0x00, 0x00, 0x00, 0x70, 0x88, 0x88};
  //  lc.setRow(0, 0, a[0]);
  //  lc.setRow(0, 1, a[1]);
  //  lc.setRow(0, 2, a[2]);
  //  lc.setRow(0, 3, a[3]);
  //  lc.setRow(0, 4, a[4]);
  //  lc.setRow(0, 5, a[5]);
  //  lc.setRow(0, 6, a[6]);
  //  lc.setRow(0, 7, a[7]);
  //  delay(1000);
  //  lc.clearAll();

  //    lc.displayChar(0, lc.getCharArrayPosition('c'));
  //  while (true);
  //  }
  //  byte b[9]={B11111111,B00000000,B00000000,B00000000,B00000000, B00000000, B00000000, B11111111};
  //  lc.setColumn (0,0,b[0]);
  //  lc.setColumn (0,1,b[1]);
  //  lc.setColumn (0,2,b[2]);
  //  lc.setColumn (0,3,b[3]);
  //  lc.setColumn (0,4,b[4]);
  //  lc.setColumn (0,5,b[5]);
  //  lc.setColumn (0,6,b[6]);
  //  lc.setColumn (0,7,b[7]);
  //  delay(1000);
  //  lc.clearAll();
  //}

  //  lc.writeString(0, "Hello");
  //  delay(1000);
  //  lc.clearAll();

  //  while (1)  {
  //    scrollRight('c');
  //    lc.clearAll();
  //    scrollLeft('M');
  //    lc.clearAll();
  //  }

  //  scrollLeft('M');
  //  delay(100);
  //  scrollLeft('A');
  //  delay(100);
  //  scrollLeft('N');
  //  delay(100);
  //  scrollRight('C');
  //  delay(1000);
  //  scrollRight('M');
  //  delay(1000);
  //  scrollRight('M');
  //  delay(1000);
  //  scrollRight('C');
  //  delay(1000);
  //  lc.clearAll();

}

void loop() {
  soilValue = analogRead(SOIL);

  int soilVal = map(analogRead(SOIL), 0, 500, 0, 9);
  
  Serial.print(soilValue);
  Serial.print(" ");
  Serial.println(soilVal);
  delay(200);
  
  char ch = digits[soilVal];
//  char ch = 1;
  lc.displayChar(0, lc.getCharArrayPosition(ch));



  //  char ch = digits[digitCounter];
  //
  //  digitCounter++;
  //
  //  if (digitCounter > 9) digitCounter = 0;
  //  lc.displayChar(0, lc.getCharArrayPosition(ch));
  //  delay(1000);
  //
  //  lc.clearAll();
  //  delay(200);

}

void scrollLeft(char ch) {
  int pos = lc.getCharArrayPosition(ch);
  for (int scroll = 8; scroll > 0; scroll--) {
    for (int i = 0; i < 6; i++) {
      lc.setRow(0, scroll - i, alphabetBitmap[pos][i]);
    }
    delay(300);
    lc.clearDisplay(0);
  }
}

void scrollRight(char ch) {
  int pos = lc.getCharArrayPosition(ch);
  for (int scroll = 0; scroll < 8; scroll++) {
    for (int i = 0; i < 6; i++) {
      //      if (scroll + i < 8)
      lc.setRow(0, scroll + i, alphabetBitmap[pos][i]);
    }
    delay(300);
    lc.clearDisplay(0);
  }
}
