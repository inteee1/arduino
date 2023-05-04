#include "my_arduino_lib.h"
/*#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7

#define ON 1  //소스
#define OFF 0

#define _ON 0 //싱크
#define _Off 1 

#define bit_set(ADDRESS, BIT) (ADDRESS |= ( 1<< BIT)) // bit hi
#define bit_clr(ADDRESS, BIT) (ADDRESS &= ~(1<<BIT)) // bit low
#define bit_chk(ADDRESS, BIT) (ADDRESS & (1<<BIT)) // bit chak
#define bit_tg(PORT, BIT) (PORT ^= (1<<BIT)) //bit 토글
#define d_out(pin, value) digitalWrite(pin, value) //비트제어1*/
/*
d_out(LED1, ON); 사용법 
bit_set(portd, 4): 4번째 켜짐
bit_clr(portd, 3): 3번쨰 꺼짐
if(bit_chk(pind,3)==0){}: 3번째가 0인지 1인지 확인
tg(portd,0);
delay(400);
*/

void byte_out(unsigned char data);



unsigned char flag = 0b00000001;
unsigned char cnt = 0;
unsigned char dp = 0b00000001; //0x01;
unsigned int d1[] = { 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
unsigned char d2[6] = {0x81, 0x42, 0x24, 0x18};

void setup() {
 // 실험1
DDRD = 0xff;
//PORTD = 0x00;
//bit_set(PORTD, LED5);

//실험2
/*pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);*/
/*pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);
pinMode(LED5, OUTPUT);
pinMode(LED6, OUTPUT);
pinMode(LED7, OUTPUT);
pinMode(LED8, OUTPUT);

digitalWrite(LED1, on);*/

//실험 3

}








void loop() {
  //실험2
 /* digitalWrite(LED1, off);
  delay(100);
  digitalWrite(LED1, 1);
  delay(15);
  digitalWrite(LED2, off);
  delay(90);
  digitalWrite(LED2, 1);
  delay(15);
  digitalWrite(LED3, off);
  delay(80);
  digitalWrite(LED3, 1);
  delay(15);
   digitalWrite(LED4, off);
  delay(70);
  digitalWrite(LED4, 1);
  delay(15);
   digitalWrite(LED5, off);
  delay(70);
  digitalWrite(LED5, 1);
  delay(15);
   digitalWrite(LED6, off);
  delay(80);
  digitalWrite(LED6, 1);
  delay(15);
   digitalWrite(LED7, off);
  delay(90);
  digitalWrite(LED7, 1);
  delay(15);
  digitalWrite(LED8, off);
  delay(10);
  digitalWrite(LED8, 1);
  delay(15);*/
   // 실험1
  /*for(unsigned int cnt = 0; cnt <= 255; cnt++)
  { 
    PORTD = cnt;
    digitalWrite(LED8, 1);
    delay(100);
    digitalWrite(LED8, 0);
    delay(99999);
  }*/
  //실험3
 /* d_out(LED1, ON);
  delay(200);
  d_out(LED1, OFF);
  delay(1000000);*/
  //실험4
 /*bit_tg(PORTD, LED1);
  delay(100);*
  bit_set(PORTD, LED1);
  delay(1000);
  bit_clr(PORTD, LED1);
  bit_set(PORTD, LED2);
  delay(1000);
  bit_clr(PORTD, LED2);
  bit_set(PORTD, LED3);
  delay(1000);
  bit_clr(PORTD, LED3);
  bit_set(PORTD, LED4);
  delay(1000);
  bit_clr(PORTD, LED4);
  bit_set(PORTD, LED5);
  delay(1000);
  bit_clr(PORTD, LED5);
  bit_set(PORTD, LED6);
  delay(1000);
  bit_clr(PORTD, LED6);
  bit_set(PORTD, LED7);
  delay(1000);
  bit_clr(PORTD, LED7);
  bit_set(PORTD, LED8);
  delay(1000);
  bit_clr(PORTD, LED8);*/
 //실험 5
 /*for(cnt = 0; cnt <= 255; cnt++)
  { 
    byte_out(cnt);
    digitalWrite(LED8, 1);
    delay(10);
    digitalWrite(LED8, 0);
    delay(10);
  }*/

 
  //PORTD = dp;
    //실험 6 shift1 
  // if(flag == 0) { dp  <<= 1;}
  // else dp >>= 1;
  // delay(50);
  // if((flag == 0) && (dp == 0)) {
  //   dp = 0x80;
  //   flag = 1;
  // }
  // else if ((flag == 1) && (dp == 0)) {
  //   dp = 0x01;
  //   flag = 0;
  // }
  //실험7 왔다갔다
  /*for (char i = 0; i <=8 ; i++)
   { PORTD = d1[i];
    delay(50);
   }
   for (char i =7; i >=0; i--)
   {
     PORTD = d1[i];
     delay(50);
   }*/
// 실험8 오므렸다 폈다
for (char i = 0; i <=3 ; i++)
   { PORTD = d2[i];
    delay(50);
   }
   for (char i =3; i >=0; i--)
   {
     PORTD = d2[i];
     delay(50);
   }


}
  


/*void byte_out(unsigned char data)
{
  d_out(LED1, data%2); //bit 0 = lsb
  d_out(LED2, data/2%2); //bit 1
  d_out(LED3, data/4%2); //bit 2
  d_out(LED4, data/8%2); //bit 3
  d_out(LED5, data/16%2); //bit 4
  d_out(LED6, data/32%2); //bit 5
  d_out(LED7, data/64%2); //bit 6
  d_out(LED8, data/128%2); //bit 7 = msb

}*/

