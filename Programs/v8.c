#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S3,     SMUX,           sensorI2CCustom)
#pragma config(Sensor, S4,     ultraLift,      sensorSONAR)
#pragma config(Motor,  motorA,          A,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          B,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          C,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     rearRight,     tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C1_2,     rearLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     frontRight,    tmotorTetrix, PIDControl)
#pragma config(Motor,  mtr_S1_C2_2,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     grabberRotor,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     grabberSlider, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     liftUp,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     liftDown,      tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#include "voids_v1.h"


task main(){
	while(true){
		getJoystickSettings(joystick);
		tankDrive();
		liftButton(100, 16, 32);
		setGrabber(100, 2, 4);
		setGrabberSlider(50, 1, 8);
	}

}
