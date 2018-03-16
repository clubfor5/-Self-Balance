

#ifndef JY_H
#define JY_H

#include <Arduino.h>
#include "Config.h"
#include <Wire.h>
#include <avr/pgmspace.h>

struct STime
{
	unsigned char ucYear;
	unsigned char ucMonth;
	unsigned char ucDay;
	unsigned char ucHour;
	unsigned char ucMinute;
	unsigned char ucSecond;
	unsigned short usMiliSecond;
};
struct SAngle
{
	short Angle[3];
	short T;
};

class JY  {
private: 
  struct STime  stcTime;
  struct SAngle  stcAngle;
  float  targetAngle[3];
  unsigned char cache[12];
  
public:
  JY();
  volatile float postureAngle[3];
  void writePosture();
  void writeTargetPosture();
  void readPosture();
  void targetPosture(uint8_t *cache);
  void returnPosture(uint8_t *cache_t);
  void returnTarget(uint8_t *cache_t);
  void CopeSerialData(unsigned char ucData);
};

#endif 
