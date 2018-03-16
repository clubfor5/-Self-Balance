#ifndef STEPPER_H
#define STEPPER_H
/*********************步进电机接线方式*********************************/
/*****步进驱动器   GND  DIR(驱动器方向) EN（驱动器使能线）  PWM信号线     VCC（5V）**********/
/*****Arduino 2560 GND  pin9            pin10               pin11         5V       **********/

#include <Arduino.h>

/*******定义管脚*********/
#define en1  10
#define dir1 9

/****定义步进电机方向*****/
#define positive HIGH
#define negtive  LOW

/****初始化步进电机，注意调整步进电机的细分，****/
void Steppers_init()
{
 TCCR1A=0b01000000;
 TCCR1B=0b00001011;  //设置时钟寄存器
 pinMode(dir1,OUTPUT);
 pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
 digitalWrite(en1,HIGH);

}

/****步进电机调速函数，speed代表一秒钟给的脉冲数，具体转速以步进电机的细分为准****/
void Steppers_setSpeed(float speed1)
  { /************ start all motors*****************/
    digitalWrite(en1,LOW); //使能端拉低制动电机
    if( (speed1>-100) && (speed1<100) )   //如果速度为0，使能端拉高，避免堵转
    digitalWrite(en1,HIGH);
   /******check motor 1 positive/negtive*********/
    if(speed1>0)  
    {
     digitalWrite(dir1,positive);
     speed1= speed1>2.5?speed1:2.5;
    }
    else   // 如果速度小于0，方向反转
    {  
        speed1=-speed1;
        speed1= speed1>2.5?speed1:2.5;
        digitalWrite(dir1,negtive);
    }   
    /***********give the speed**************/
    OCR1A=125000/speed1-1;   //这里控制PWM的频率用于调速，详情需查看寄存器
  }

/****步进电机停止转动****/
  void Steppers_stop() {
    digitalWrite(en1,HIGH);
  }

/****步进电机开始使能转动****/
   void Steppers_start() {
    digitalWrite(en1,LOW);
  }
  
 
  #endif
