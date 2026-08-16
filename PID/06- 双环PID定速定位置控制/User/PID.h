#ifndef __PID_H__
#define __PID_H__

typedef struct 
{
	float Target;
	float Actual;
	float Out;
	
	float Kp;
	float Ki;
	float Kd;
	
	float Error0;
	float Error1;
	float ErrorInt;
	
	float OutMax;
	float OutMin;
	
	float Dandband;
}PID_t;

void PID_Update(PID_t*p);

#endif