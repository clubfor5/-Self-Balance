#ifndef PID_H
#define PID_H
/******增量式PID库，改编自Arm_4 DSP，适用于步进电机控制*****/
class PID
{
 private:
    float A0,A1,A2,state[3],Kp,Ki,Kd; // 
    bool resetStateFlag;
 public: 
      PID();
      PID(float kp,float ki,float kd);
     void PID_init();
     void PID_reset(); 
     float PID_run(float error);
     void PID_setParameter(float kp,float ki,float kd);    
};
#endif
