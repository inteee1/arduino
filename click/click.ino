#define jx A0
#define jy A1
#define j_sw 8
#define ry 9
#define sen A2


int ad_buf;
int ad_buf1, ad_buf2; 

//초음파 
const int trigPin = 4; // = #define trigpin 4
const int echoPin = 2;

void setup() {
 //실습1
 pinMode(j_sw, INPUT_PULLUP); //릴레이 실습
 pinMode(ry, OUTPUT);
 //DDRB = 0xff;
 //pinMode(cds, INPUT);
 //Serial.begin(9600);
 //실습2
 pinMode(A0, INPUT);
 pinMode(A1, INPUT);

 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 // pimode
 Serial.begin(9600);
//실습 3 터치센서
 pinMode(A2, INPUT);
 pinMode(2, INPUT);

// 실습4 초음파
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, OUTPUT);

}

void loop() {
  // 실습 5 초음파
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 //echo를 통해 반사된 초음파 측정
 long distance = pulseIn(echoPin, HIGH) / 58;
 Serial.print(distance, DEC);
 Serial.println("CM");
 //실습4 터치센서
// Serial.println(analogRead(A2));
// Serial.println(digitalRead(2));
// delay(500);
// 실습 3 조이스틱
//  ad_buf1 = analogRead(jx);
//  ad_buf2 = analogRead(jy);
//  Serial.print("x = ");
//  Serial.println(ad_buf1, DEC);

//  Serial.print("y = ");
//  Serial.println(ad_buf2, DEC);
//  delay(1000);

//  PORTD = 0x00;


// //x축
//  if(ad_buf2 <= 10) digitalWrite(4, 1);
//  else if(ad_buf2 > 1000)  digitalWrite(5, 1);
 
//   //else PORTD = 0x00;
// //y축
//  if(ad_buf1 <= 10) digitalWrite(6, 1);
//  else if(ad_buf1 > 990) digitalWrite(7, 1);

//  //else PORTD = 0x00;

//실습2 딸깍
//  if(digitalRead(j_sw) == 0) digitalWrite(ry, 1);
//   else digitalWrite(ry, 0);
 
 
 
 //실습 1
 //ad_buf = analogRead(cds);
 //Serial.println(ad_buf, DEC);
 // delay(500);
}
