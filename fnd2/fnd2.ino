
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

 

int8_t tg_flag = 0; // char 와 같음

 

#include "my_arduino_lib.h"

#include "my_fnd_lib.h"

#include "my_key_lib.h"




long cnt = 123456; 
int t_loop = 0;
char tg_flag2 = 0;
int cnt_2 = 345;
 

struct ck

{

  int time_loop;

  char hour;

  int8_t min;

  char sec;

}time = {0, 16, 0, 0};

 

struct chk{

  char key_flag;
  char run_flag;
  int bit_flag;
  char byte_flag;
  unsigned int kb_flag;
  char key_d[10];
  float dk_flag;

}flag = {0,0,0,0,0};

 

unsigned char key_buf;
unsigned char mode_cnt = 1;
char d_buf[20];

char key_bit_in()
#define byte_key 1 //bit_key

{

  char buf = '0';

  // bit 방식일기 = arduino Mode
 // (d_in(UP_key) == 1) ? buf = '1' : (d_in(DN_key) == 1) ? buf = '2' : (d_in(RUN_key) == 1) ? buf = '3' : (d_in(STOP_key) == 1) ? buf = '4' : (d_in(MODE_key) == 1) ? buf = '5' : buf = '0';
  // 위와 같음
  if(d_in(UP_key) == 1) buf = '1';
  else if(d_in(DN_key) == 1 ) buf = '2';
  else if(d_in(RUN_key) == 1) buf = '3';
  else if(d_in(STOP_key) == 1) buf = '4';
  else if(d_in(MODE_key) == 1) buf = '5';
  else buf = '0';

  while(PINC != 0x00) {fnd_dis(cnt);}

  Serial.println(buf);
  if (buf != '0') 

  flag.key_flag = 1;
  
  return buf;
 //테스트
  /*Serial.println(digitalRead(UP_key));

 

  if(digitalRead(UP_key) == 1)

   {

     Serial.println("Up Key Input");

     flag.key_flag = 1;

   }

  return buf;

}*/
}
 

char key_byte_in()

{

  // byte 방식읽기 = MCU Mode

  char buf = 0;
  if(PINC != 0) 
  {
  buf = (PINC & 0x3f);
  //sprintf(d_buf, "%d\n", buf);
  Serial.print(buf);
  }
  return buf;

}

 

void key_chk()

{

  // 키 판단

  flag.key_flag = 0;


  switch(key_buf)

  {

    case '1': // up Key
    case 0x01:
          cnt_2++;
         
          Serial.println(cnt_2);
          break;
    case '2': // dn Key
    case 0x02:
          cnt_2--;
          Serial.println(cnt_2);
          break;
    case '3': // run Key
    case 0x04:
          flag.run_flag = 1;

          break;
    case '4': // stop Key
    case 0x08:
          flag.run_flag = 0;

          break; 

    // if((key_buf == '5') || (key_buf == 0))  아래것과 같음      
    case '5': // mode Key
    case 0x10:
          mode_cnt++;
          if(mode_cnt >= 5) mode_cnt = 1;

          break;            
  }


#ifdef byte_key
  
#endif
}

char key_rd()
{
  
 #ifndef bit_key
  char buf = '0';
   buf = key_bit_in();
 #endif;

 #ifndef byte_key
 char buf = 0;
    buf = key_byte_in();
 #endif;

return buf;

}

void up_cnt(){
for(; cnt_2<=9999; ) {
  cnt_2 += 5;
  sprintf(d_buf, "Count = %4d", cnt_2);
  Serial.println(d_buf);
  delay(300);
   key_buf = key_bit_in();
  if(flag.key_flag == 1)
   {
    key_chk();
    break;
    }
  }
} 

void dn_cnt(){

 cnt_2 -= 5;
  sprintf(d_buf, "Count = %4d", cnt_2);
  Serial.println(d_buf);
  delay(300);


}


void setup() {

  // put your setup code here, to run once:

  DDRD = 0xf0;  // fnd data out

  DDRB = 0xff;  // scan pulse out

 

  // mcu 방식

  DDRC = 0x00; // 입력포트 설정

  PORTC = 0xff; // 풀업저항 활성화

 

/*

  // Arduino 방식

  pinMode(14, INPUT_PULLUP);

   pinMode(15, INPUT_PULLUP);

    pinMode(16, INPUT_PULLUP);

     pinMode(17, INPUT_PULLUP);

      pinMode(18, INPUT_PULLUP);

       pinMode(19, INPUT_PULLUP);

*/

 

Serial.begin(9600);

attachInterrupt(0, key_irq, CHANGE);//RISING);
attachInterrupt(1, key_irq_1, FALLING);

}


void key_irq()
{
  Serial.println("RISING");

}

void key_irq_1()
{

  Serial.println("FALLING");
}


 

void loop() {

// #ifdef bit_key

// key_buf = key_bit_in(); // key_bit_in()
// #endif
// #ifdef key_byte
// key_buf = key_byte_in();
// #endif // 아래꺼가 더 좋음
  key_buf = key_rd();
  if(flag.key_flag == 1) key_chk();

   //fnd_dis(cnt);
  if(flag.run_flag == 1)
  {
    
    switch(mode_cnt)
    {
      case 1 : up_cnt(); break;
      case 2 : dn_cnt(); break;
      // case 3 : env_cnt(); break;
      // case 4 : odd_cnt(); break;
      // case 5 : mul(); break;

    }
  }


   delay(100);

/*

  // 실습2

  delay(1);

  time.time_loop++;

  if(time.time_loop >= 1000) //1sec

  {

    time.time_loop = 0;

    time.sec++;

   

    (tg_flag == 0) ? tg_flag = 1 : tg_flag = 0; // sec

    (tg_flag2 ==0) ? tg_flag2 = 1 : tg_flag2 = 1; // hour, min

 

    if(time.sec > 59) // 1min

    {

       time.sec = 0;

       time.min++;

       if(time.min > 59) // 1hour chk sum

        {

          time.min = 0;

          time.hour++;

          if(time.hour > 23) time.hour = 0;

        }

    }

  }  

  fnd_time(time.hour, time.min, time.sec);

*/

 

  /*

   // 실습1

  delay(1);

  t_loop++;

  if(t_loop > 300)

  {

    t_loop = 0;

    cnt++;

    //tg_flag = ~tg_flag;

    //if(tg_flag == 0) tg_flag = 1;

    //else tg_flag = 0;

    (tg_flag == 0) ? tg_flag = 1 : tg_flag = 0;

  }

   fnd_dis(cnt);

  */

 

  

}

 