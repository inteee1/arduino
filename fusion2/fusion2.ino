#include "my_arduino_lib.h"
#include <SoftwareSerial.h>
#include <MsTimer2.h>

unsigned char cnt = 0;
unsigned char dp = 0b00000001; //   0x01;
char flag = 0;
unsigned char S_distance = 0;
unsigned char back_distance = 0;

int ad_buf1, ad_buf2;

const int BUZZER = 10;

const int melody[8] = {262, 294, 330, 349, 393, 440, 494, 523};

SoftwareSerial STX(18, 19);

void setup(){
Serial.begin(9600);
DDRD = 0xff;
DDRB = 0xff;

pinMode(18, INPUT);
STX.begin(9600);

}
void loop(){
  
 S_distance = STX.read();

 if(S_distance != 255){
   back_distance = S_distance;
   Serial.println(S_distance, DEC);
    
  if(S_distance <= 10) {
    d_out(LED1, ON); 
    d_out(LED2, ON);
    d_out(LED3, ON);
    d_out(LED4, ON);
    d_out(LED5, ON);
    d_out(LED6, ON);
    d_out(LED7, ON);
    d_out(LED8, ON);
    tone(BUZZER, melody[7]); delay(500); noTone(BUZZER); delay(5);
  }
  else if(S_distance > 10 && S_distance <= 20){
    d_out(LED1, ON);
    d_out(LED2, ON);
    d_out(LED3, ON);
    d_out(LED4, ON);
    d_out(LED5, ON);
    d_out(LED6, ON);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    tone(BUZZER, melody[7]); delay(100); noTone(BUZZER); delay(50);
  }
  else if(S_distance > 20 && S_distance <= 30){
    d_out(LED1, ON);
    d_out(LED2, ON);
    d_out(LED3, ON);
    d_out(LED4, ON);
    d_out(LED5, OFF);
    d_out(LED6, OFF);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    tone(BUZZER, melody[7]); delay(180); noTone(BUZZER); delay(180);
  }
  else if(S_distance > 30 && S_distance <= 40){
    d_out(LED1, ON);
    d_out(LED2, ON);
    d_out(LED3, OFF);
    d_out(LED4, OFF);
    d_out(LED5, OFF);
    d_out(LED6, OFF);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    tone(BUZZER, melody[7]); delay(50); noTone(BUZZER); delay(500);
  }
  else if(S_distance > 40){
    d_out(LED1, OFF);
    d_out(LED2, OFF);
    d_out(LED3, OFF);
    d_out(LED4, OFF);
    d_out(LED5, OFF);
    d_out(LED6, OFF);
    d_out(LED7, OFF);
    d_out(LED8, OFF);
    noTone(BUZZER);
  }
 }
}