/*******JY901做步进电机的自平衡*********/

#include <Arduino.h>
#include "Timer5.h"
#include "JY.h"
#include "pid.h"
#include "stepper.h"

/****在此更改PID参数***/
#define Kp 100  
#define Ki 0 
#define Kd 0

/****在此设置目标角度*****/
const float myTarget = 00;

JY jy; //创立JY901对象
PID myPID(Kp,Ki,Kd); //创立PID对象
volatile float currentSpeed = 0; //速度
volatile float error = 0;
void setup() {
  Serial.begin(115200);
  Serial3.begin(9600);
  Steppers_init();
  myPID.PID_init(); // 通过Kp,Ki,Kd来计算A0,A1,A2
  startTimer5(20000L);//开启timer5 定时器，周期5000us = 5ms, 频率200HZ，暂定一秒做200次PID。
}

void loop() {
 jy.readPosture();//不断轮询刷新
 //Steppers_setSpeed(100);
}

/****时钟中断，用于PID任务****/
ISR(timer5Event) {
  error = jy.postureAngle[1]-myTarget;//计算误差角度
  if(abs(error)<1)  //设置死区，到达死区后停止
    currentSpeed = 0;
  else
    currentSpeed = myPID.PID_run(-error); //PID运算出速度
  Serial.println(currentSpeed);
  Steppers_setSpeed(currentSpeed); // 设置步进电机速度
  resetTimer5();
}


 

