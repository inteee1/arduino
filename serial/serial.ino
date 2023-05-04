// my_lib
#include "my_arduino_lib.h"
// std_lib
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define P_pin 8
#define N_pin 9
#define EN_pin 10

#define FAN1_pin 11
#define FAN2_pin 12

unsigned int cnt;
char d_buf[60];
char run_flag = 0;
//unsigned char rx_buf;

volatile unsigned char rx_buf[20];
volatile char rx_end_flag = 0;
volatile char rx_cnt = 0;
//실습4
void m_cw()
{
  d_out(EN_pin, ON);
 bit_set(PORTB, 1); // d_out(P_pin,ON);
 d_out(N_pin, 0); //bit_clr(PORTB, OFF);
 d_out(LED3, ON);
 d_out(LED5, OFF);
}

void m_ccw()
{
  d_out(EN_pin, ON);
  d_out(P_pin, OFF); //0
  d_out(N_pin, ON); //1
  d_out(LED3, OFF);
 d_out(LED5, ON);
}
void m_stop()
{
  bit_clr(PORTB, P_pin);
  bit_clr(PORTB, N_pin);
  d_out(EN_pin, OFF);
}
void m_pause()
{
  if(run_flag == 0) d_out(EN_pin, OFF);
  else if(run_flag == 1) d_out(EN_pin, ON);
}

void fan_m_cw()
{
  d_out(FAN1_pin, 1);
  d_out(FAN2_pin, 0);
  d_out(LED4, ON);
 d_out(LED6, OFF);

}

void fan_m_ccw()
{
 d_out(FAN1_pin, 0);
 d_out(FAN2_pin, 1);
 d_out(LED4, OFF);
 d_out(LED6, ON);
}

void fan_m_stop()
{
 d_out(FAN1_pin, OFF);
 d_out(FAN2_pin, OFF);

}
void com_chk(){
  rx_end_flag = 0;
  sprintf(d_buf, "%s", rx_buf);
  Serial.println(d_buf);
  switch(d_buf[0])
  {
    case '0': m_ccw(); Serial.println('w'); break;
    
    case '1': m_stop();Serial.println('h'); break;
    default: Serial.println('r'); break;
  }
  memset(rx_buf, 0, sizeof(char)*20);
}

void setup() {
 
//DDRD = 0xff;
//d_out(LED3,1);
DDRD = 0xfe;
pinMode(P_pin, OUTPUT);
pinMode(N_pin, OUTPUT);
pinMode(EN_pin, OUTPUT);
pinMode(FAN1_pin, OUTPUT);
pinMode(FAN2_pin, OUTPUT);

Serial.begin(9600); // 115200

m_stop();
fan_m_stop();
}
// 시리얼 수신 ISR
void serialEvent(){
  //실습 6
  //Serial.println(Serial.readString());

  //실습 7
 unsigned char buf;
  if(Serial.available()){
    buf = Serial.read();

    if(buf == 0x0D)
    {
      rx_cnt = 0;
      rx_end_flag = 1;
 Serial.println("벌레이상없음");
    }
    else {
      rx_buf[rx_cnt] = buf;
      rx_cnt++;

    }
    }
  }





void loop() {
      
// 실습 1
/*int cnt;
for( cnt = 0; cnt <= 9999 ; ++cnt)
{Serial.println(cnt);
if( cnt >= 10) { break;}

delay(100);
}
 cnt = 0;*/
//========================================
// 실습2
 /*for( int cnt = 0; cnt <= 9999 ; ++cnt)
 {
   Serial.write(cnt/1000 + 0x30);
   Serial.write(cnt%1000/100 + '0');
   Serial.write(cnt%100/10 + 0x30);
   Serial.write(cnt%10 + '0');
   Serial.write("\n");
   Serial.write('\007');
   delay(200);
 }*/ //==================================
// 실습3
/*for( cnt = 0; cnt <= 9999 ; ++cnt)
{sprintf(d_buf, "Counter = %4d\n",cnt);
Serial.write(d_buf);
delay(200);
}*/ //=====================================
// 실습4
/*m_cw();
delay(1000);
m_ccw();
delay(1000);
fan_m_cw();
delay(100000);
fan_m_ccw();
delay(100000);*/
//==============================================
// 실습 5 폴링방식 수신처리
/*if(Serial.available()){
  //rx_buf = Serial.read();
  Serial.println(Serial.readString());}
 */ //==============================================
 // 실습 6 interrupt 방식
// 실습 7
if(rx_end_flag == 1){
com_chk();

}
bit_tg(PORTD, LED8);

}
