#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#define LCD_IF_8_Bit 1
#define LCD_PD       1
#include "my_arduino_lib.h"
#include "my_lcd_Arduino_lib_v2_3.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cnt = 0;
char d_buf[20];














void setup() {
  // put your setup code here, to run once:
  //  DDRD = 0xff;
  //  DDRD = 0xff;
  //  lcd_init();
  
  // //  lcd test
  //  lcd_gotoxy(5, 1);
  //  lcd_str("my name");
  //  lcd_gotoxy(12,2);
  //  lcd_send('K');
  lcd.begin(16,2);
  // lcd.setCursor(0, 0);
  // lcd.print("UP Cnt : ");
  // lcd.setCursor(0, 1);
  // lcd.print("DN Cnt : ");
 
 
  
  //delay(3000);
  //lcd.clear(); 
  /*for(int i = 0; i<=7; i++)
  {
    lcd.scrollDisplayRight();
    delay(500);

  }
for(int i = 0; i<=7; i++)
  {
    lcd.scrollDisplayLeft();
    delay(500);

  }
*/
}

void loop() {
  sprintf(d_buf,"UP Cnt : %4d", cnt);
  lcd.setCursor(0, 0);
  lcd.print(d_buf);

  sprintf(d_buf,"DN Cnt : %4d", (9999-cnt));
  lcd.setCursor(0, 1);
  lcd.print(d_buf);
  
  cnt++;
  if(cnt > 9999)
  cnt = 0;
  delay(20);


//  lcd.cursor();
//  delay(500);
//  lcd.noCursor();
//  delay(500);
// lcd.noDisplay();
// delay(500);
// lcd.display();
// delay(500);
/*
for(cnt; cnt<=9999; cnt++)
{lcd.setCursor(10,0);
lcd.write(cnt/1000 + 0x30);
lcd.write(cnt%1000/100 +'0');
lcd.write(cnt%100/10 + 0x30);
lcd.write(cnt%10 + 0x30);
delay(5);



lcd.setCursor(10,1);
lcd.write((9999-cnt)/1000 + 0x30);
lcd.write((9999-cnt)%1000/100 +'0');
lcd.write((9999-cnt)%100/10 + 0x30);
lcd.write((9999-cnt)%10 + 0x30);
delay(4);
}
if( cnt = 9999)
cnt = 0;
// cnt++;
//if(cnt>9999) cnt = 0;
*/
}
