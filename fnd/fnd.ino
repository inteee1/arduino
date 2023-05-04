#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int8_t tg_flag = 0; //char와 같음
#include "my_arduino_lib.h"
#include "my_fnd_lib.h"
#include "my_key_lib.h"
long cnt = 100000; // unsigned char와 같음
long abd = 100;
int t_loop = 0;

struct ck{

  int time_loop;
  char hour;
  int8_t min;
  char sec;
}time = {0,14,38,40};

struct chk{
  char key_flag;
  char redy_flag;
  int bit_flag;
  char byte_flag;
  unsigned int kb_flag;
  char key_d[10];
  float dk_flag;
  
} flag = {0, 0, 0, 0, 0};
unsigned char key_buf;

char key_bit_in() // bit방식읽기 = 아두이노 mode
{
  /*char buf = 0;
  if((PINC & 0x3f) != 0x3f)
  {
     d_out(X100000, _OFF);
    flag.key_flag = 1;
  }*/
char buf = 0;
Serial.println(digitalRead(DN_key));
if(digitalRead(UP_key) == 1 ){
  Serial.println("Up Key Input");
  flag.key_flag = 1;

}

  return buf;
}
char key_byte_in() // byte 방식읽기 = mcu mode
{
  char buf = 0;
  return buf;

}


void key_chk() // 키 판단
{
 flag.key_flag = 0;
 switch(key_buf)
 {
   case 0x01: //upkey
        cnt++;
        break;

 }

}
/*time.sec++;
time.sec = 35;
time.min = time.sec;*/

void setup() {
  DDRD = 0xff;  //fnd data out
  DDRB = 0xff;  //scan pulse out
  // mcu
 // DDRC = 0x00; //scan pulse out (입력저항 활성화)
 // PORTD = 0xff; //풀업저항 활성화

  // 아두이노 방식
 /*pinMode(14, INPUT_PULLUP);
 pinMode(15, INPUT_PULLUP);
 pinMode(16, INPUT_PULLUP);
 pinMode(17, INPUT_PULLUP);
 pinMode(18, INPUT_PULLUP);
 pinMode(19, INPUT_PULLUP);*/ 
Serial.begin(9600);
}

void loop() {
  //실습2========================
  //delay(1);
  //time.time_loop++
  //if(time.time_loop >= 1000){}
  // time. time_loop = 0;
  //time.sec++;
  //(tg_flag == 0) ? tg_flag = 1 : tg_flag = 0;
  //(tg_flag2 == 0) ? tg_flag2 = 1 tg_flag2 = 1;
  /*delay(1);
  t_loop++;
  if(t_loop > 100)
  {
    t_loop = 0;
    time.sec++;
    if( time.sec > 59){
      time.sec = 0;
      time.min++;
      }
    if(time.min > 59)
      {
        time.min = 0;
      time.hour++;
      }
    if(time.hour > 23){
        time.hour = 0;

    }
     if(tg_flag == 0)
     tg_flag = 1;
     else tg_flag = 0;}
  
  //(tg_flag == 0 ) ? tg_flag = 1 : tg_flag = 0;
  fnd_time(time.hour, time.min, time.sec);
  delay(1);*/

//==============================================================
//실습2
/*fnd_abc(cnt);
  delay(1);*/
  //================================================================
 key_buf = key_bit_in();
 if(flag.key_flag == 1) key_chk();
  fnd_dis(abd);
}

