/****配置文件****/
#define I_AM_POSTURE
#ifdef I_AM_POSTURE
#define MyAdd POSTURE_BOARD

#define StepMotor1 11 //OC1A
#define StepMotor2 5   //OC3A
#define StepMotor3 6   //OC4A

#define Direction1 46
#define Direction2 45
#define Direction3 44

#define PhotoRes1 A0
#define PhotoRes2 A1

#define LED_MCU 30
#define LED_JY 31
#define LED_MPU 32
#define LED_PITCH 33
#define LED_ROLL 34
#define LED_YAW 35
#define LED_IIC 36
//#define LED_PITCH 34
//#define LED_ROLL 35
//#define LED_YAW 36
//#define LED_IIC 33
#define LED_FRONT1 29
#define LED_FRONT2 28
#define LED_LEFT1 27
#define LED_LEFT2 26
#define LED_RIGHT1 23
#define LED_RIGHT2 22
#define LED_BACK1 25
#define LED_BACK2 24

#define ROLL 0x01
#define PITCH 0x00
#define YAW 0x02

#ifdef JY901
#endif

#ifdef MPU9250

#endif

#endif


