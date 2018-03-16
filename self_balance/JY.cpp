

#include "JY.h"

JY::JY() {
  pinMode(LED_JY, OUTPUT);
  postureAngle[0] = 0;
  postureAngle[1] = 0;
  postureAngle[2] = 0;
  targetAngle[0] = 0;
  targetAngle[1] = 0;
  targetAngle[2] = 0;
}

void JY::writePosture() {
   memcpy(cache, postureAngle, 12); 
   Wire.write(cache,12);
}

void JY::writeTargetPosture() {
   memcpy(cache, targetAngle, 12); 
   Wire.write(cache,12);
}

void JY::returnPosture(uint8_t *cache_t) {
  memcpy(cache_t, postureAngle, 12);
}

void JY::returnTarget(uint8_t *cache_t) {
  memcpy(cache_t, targetAngle, 12);
}

void JY::targetPosture(uint8_t *cache) {
  digitalWrite(LED_JY, HIGH);
  
  for (uint8_t temp = 0; temp<12; temp++) {
      cache[temp] = Wire.read();
  }
  memcpy(targetAngle, cache, 12);
  digitalWrite(LED_JY, LOW);
}

void JY::readPosture() {
  digitalWrite(LED_JY, HIGH);
  while (Serial3.available()) {
    CopeSerialData(Serial3.read());
  }
  
  postureAngle[1] = -(float)stcAngle.Angle[0]/32768*180;
  postureAngle[0] = (float)stcAngle.Angle[1]/32768*180;
  postureAngle[2] = (float)stcAngle.Angle[2]/32768*180;
  /*Serial.print("Yaw: ");
  Serial.println(postureAngle[2]);
  Serial.print("Pitch: ");
  Serial.println(postureAngle[0]);
  Serial.print("Roll: ");
  Serial.println(postureAngle[1]);
  Serial.println();*/
  digitalWrite(LED_JY, LOW);
}

void JY::CopeSerialData(unsigned char ucData) {
  static unsigned char ucRxBuffer[250];
  static unsigned char ucRxCnt = 0;	
  
  ucRxBuffer[ucRxCnt++]=ucData;
  if (ucRxBuffer[0]!=0x55) {
    ucRxCnt=0;
    return;
  }
  if (ucRxCnt<11) {
    return;
  }
  else {
    switch(ucRxBuffer[1]) {
	case 0x50:	
          memcpy(&stcTime,&ucRxBuffer[2],8);
          break;
	case 0x53:	
          memcpy(&stcAngle,&ucRxBuffer[2],8);
          break;
        default:
          break;
    }
  ucRxCnt=0;
  }
}
