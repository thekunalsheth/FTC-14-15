#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     rearLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rearRight,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     frontRight,    tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//		<<		Files to include before compiling	>>
#include "JoystickDriver.c" //Including the Joystick Drivers
#include "voids v1.h" //Including a header file which has all the defined functions

//		<<		Main Task to perform		>>
task main(){
	forward(-15.5);
	wait(1500);
	stopDrive();
	rightPoint(15);
	wait(1800);
}
