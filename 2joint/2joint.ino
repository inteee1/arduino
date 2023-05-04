#include <SoftwareSerial.h>
SoftwareSerial my_Serial(12,13);
void setup() {
  //hw 오리지널 uart
  Serial.begin(9600);
  // sw orignal uart
  my_Serial.begin(9600);  

}

void loop() {
  //소프트웨어 시리얼 포트 전
            Serial.println("song");
 if(my_Serial.available()) {
   char rxd = my_Serial.read();
   Serial.println(rxd); }
}
delay(500);