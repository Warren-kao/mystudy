#include "stm32f10x.h"                  // Device header

#include "MPU6050_Reg.h"

#define MPU6050_ADDRESS	0xD0

struct {
	int16_t Accx;
	int16_t Accy;
	int16_t Accz;
	int16_t Temp;
	int16_t Gyrox;
	int16_t Gyroy;
	int16_t Gyroz;
}MPU6050_Data;

void MPU6050_WriteReg(uint8_t Address,uint8_t Data)
{
//	MyI2C_Start();
//	MyI2C_SendByte(MPU6050_ADDRESS);
//	MyI2C_ReadAck();
//	MyI2C_SendByte(Address);
//	MyI2C_ReadAck();
//	MyI2C_SendByte(Data);
//	MyI2C_ReadAck();	
//	MyI2C_Stop();
}
uint8_t MPU6050_ReadReg(uint8_t Address,uint8_t Ack)
{
	uint8_t Data = 0;
	if(Ack == 1)
	{
//		MyI2C_Start();
//		MyI2C_SendByte(MPU6050_ADDRESS);
//		MyI2C_ReadAck();
//		MyI2C_SendByte(Address);
//		MyI2C_ReadAck();
//		
//		MyI2C_Start();
//		MyI2C_SendByte(MPU6050_ADDRESS | 0x01);
//		MyI2C_ReadAck();
//		Data = MyI2C_ReadByte(Data);
//		MyI2C_SendAck(1);	
//		MyI2C_Stop();
//	}else if(Ack == 0)
//	{
//		MyI2C_Start();
//		MyI2C_SendByte(MPU6050_ADDRESS);
//		MyI2C_ReadAck();
//		MyI2C_SendByte(Address);
//		MyI2C_ReadAck();
//		
//		MyI2C_Start();
//		MyI2C_SendByte(MPU6050_ADDRESS | 0x01);
//		MyI2C_ReadAck();
//		Data = MyI2C_ReadByte(Data);
//		MyI2C_SendAck(0);
//	}else if(Ack == 2)
//	{
//		Data = MyI2C_ReadByte(Data);
//		MyI2C_SendAck(0);
//	}else if(Ack == 3)
//	{
//		Data = MyI2C_ReadByte(Data);
//		MyI2C_SendAck(1);
//		MyI2C_Stop();
//	}

//	
	return Data;
}

void MPU6050_Init()
{
//	MyI2C_Init();
//	MPU6050_WriteReg(MPU6050_PWR_MGMT_1,0x01);//解除睡眠,选择陀螺仪时钟
//	MPU6050_WriteReg(MPU6050_PWR_MGMT_2,0x00);//6轴不待机
//	MPU6050_WriteReg(MPU6050_SMPLRT_DIV,0x09);//采样10分频
//	MPU6050_WriteReg(MPU6050_CONFIG,0x06);//滤波最高
//	MPU6050_WriteReg(MPU6050_GYRO_CONFIG,0x18);//陀螺仪最大量程
//	MPU6050_WriteReg(MPU6050_ACCEL_CONFIG,0x18);//加速度计最大量程
}

void MPU6050_GetData()
{
//	uint8_t DataH,DataL;
//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,0);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	MPU6050_Data.Accx = (DataH<<8) | DataL;
//	
//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	MPU6050_Data.Accy = (DataH<<8) | DataL;

//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	MPU6050_Data.Accz = (DataH<<8) | DataL;

//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	MPU6050_Data.Temp = (DataH<<8) | DataL;

//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	MPU6050_Data.Gyrox = (DataH<<8) | DataL;

//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	MPU6050_Data.Gyroy = (DataH<<8) | DataL;

//	DataH = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,2);
//	DataL = MPU6050_ReadReg(MPU6050_ACCEL_XOUT_H,3);
//	MPU6050_Data.Gyroz = (DataH<<8) | DataL;
}

uint8_t MPU6050_GetID()
{
//	return MPU6050_ReadReg(0x75,1);
}

