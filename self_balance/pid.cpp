/*** PID源文件cpp***/
#include "pid.h"
PID::PID() 
{
  Kp = 0;
  Ki = 0;
  Kp = 0;
  resetStateFlag = true;
}
PID::PID(float kp, float ki, float kd)
{
  Kp = kp;
  Ki = ki;
  Kd = kd;
}
void PID::PID_init() 
{
  A0 = Kp + Ki + Kd;
  A1 = -Kp - 2.0 * Kd;
  A2 = Kd;
  if (resetStateFlag)
  {
    for (int i = 0; i < 3; i++)
      state[i] = 0;
      resetStateFlag = false;
  }
}
void PID::PID_reset() 
{
  resetStateFlag = true;
  for (int i = 0; i < 3; i++)
    state[i] = 0;
}
void PID::PID_setParameter(float kp, float ki, float kd)
{
  Kp = kp;
  Ki = ki;
  Kd = kd;
}
float PID::PID_run(float in)
{
  float out;
  out = A0 * in + A1 * state[0] + A2 * state[1] + state[2];
  state[1] = state[0];
  state[0] = in;
  state[2] = out;
  return out;

}

