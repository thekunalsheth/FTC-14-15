#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorB,          NXTB,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          NXTC,          tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     L,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     R,             tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     P,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     B,             tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    S,                    tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"


task main()
{
	while(true)
	{
		getJoystickSettings(joystick);

		if(abs(joystick.joy1_y1)>10 && abs(joystick.joy1_y2)<10) {
					motor(L)=(joystick.joy1_y1*-0.5);
					motor(R)=0;}

		else if(abs(joystick.joy1_y1)<10 && abs(joystick.joy1_y2)>10)	{
					motor(R)=(joystick.joy1_y2*-0.5);
					motor(L)=0;}

		else if(abs(joystick.joy1_y1)>10 && abs(joystick.joy1_y2)>10)	{
					motor(L)=(joystick.joy1_y1*-0.5);
					motor(R)=(joystick.joy1_y2*-0.5);}

		else if(joystick.joy1_TopHat==6)	{
					motor(L)=20;
					motor(R)=-20;
					wait1Msec(100);
					motor(L)=-20;
					motor(R)=20;
					wait1Msec(100);}

		else if(joy1Btn(6)==1)	{
					motor(L)=-30;
					motor(R)=-30;}
		else {
					motor(L)=0;
					motor(R)=0;}

		if(joy1Btn(4)==1) {
					motor(P)=80;}

		else if(joy1Btn(1)==1) {
					motor(P)=-80;}

		else {
					motor(P)=0;}

		if(joystick.joy1_TopHat==1)	{
					motor(B)=80;}

		else if(joystick.joy1_TopHat==4) {
					motor(B)=-80;}

		else	{
					motor(B)=0;}

		if(joy1Btn(5)==1)	{
					motor(NXTB)=100;
					motor(NXTC)=100;}

		else	{
					motor(NXTB)=0;
					motor(NXTC)=0;}

		if(joy1Btn(2)==1)	{
					servo[S]=128;}

		else if(joy1Btn(3)==1)	{
					servo[S]=255;}

		else	{}
	}
}