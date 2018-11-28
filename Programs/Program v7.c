#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          A,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          B,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          C,             tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     RR,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     LR,            tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Rack1,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Rack2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     G,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     empty,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     RF,            tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_2,     LF,            tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    S1,                   tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    S2,                   tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"
#define MULTI -0.5
#define SMULTI -0.3
#define FMULTI -0.8
#define VERYSLOW 20
#define SLOW 35
#define MED 50
#define FAST 75
#define VERYFAST 100

int LMulti;
int RMulti;
bool grab;

void left(int S){motor[LR]=S;motor[LF]=S;}//moves left motors
void right(int S){motor[RF]=S;motor[RR]=S;}//moves right motors
void forward(int S){left(S);right(S);}//moves all motors forward
void backward(int S){left(-S);right(-S);}//moves all motors backward

void grabber(int S){motor[G]=S;}//moves grabber
void rackOne(int S){motor[Rack1]=S;}//moves the front rack
void rackTwo(int S){motor[Rack2]=S;}//moves the rear rack

void flapOpen(){servo[S1]=255;}//opens flap on rear rack
void flapClose(){servo[S1]=128;}//closes flap on rear rack
void lockOpen(){servo[S2]=255;}//opens rolling goal lock
void lockClose(){servo[S2]=70;}//closes rolling goal lock

void shake(){forward(20);wait1Msec(100);backward(20);wait1Msec(100);backward(0);}//shakes the bot
void grabberRun(){if(grab==true){grabber(MED);}
	else{grabber(0);}}
void setMultiplier(){if(joy1Btn(9)==1){LMulti=FMULTI;}
	else{LMulti=SMULTI;}
	if(joy1Btn(10)==1){RMulti=FMULTI;}
	else{RMulti=SMULTI;}}//boosts the drive motors

task main(){
	while(true){
		getJoystickSettings(joystick);

		//Drive Motors
		if(joystick.joy1_TopHat==0){forward(-VERYSLOW);}
		else if(joystick.joy1_TopHat==4){backward(-VERYSLOW);}
		else if(joy2Btn(4)==1&&joy2Btn(6)==1){shake();}
		else{if(abs(joystick.joy1_y1)>10){left(joystick.joy1_y1*MULTI);}
			else if(joystick.joy1_TopHat==6){left(-VERYSLOW);}
			else{left(0);}
			if(abs(joystick.joy1_y2)>10){right(joystick.joy1_y2*MULTI);}
			else if(joystick.joy1_TopHat==2){right(-VERYSLOW);}
			else{right(0);}
		}
		//Rack Motors
		if(abs(joystick.joy2_y1)>10){rackOne(joystick.joy2_y1*MULTI);}
		else if(joy1Btn(3)==1||joystick.joy2_TopHat==5){rackOne(FAST);}
		else if(joy1Btn(4)==1||joystick.joy2_TopHat==7){rackOne(-FAST);}
		else{rackOne(0);}
		if(abs(joystick.joy2_y2)>10){rackTwo(joystick.joy2_y2*MULTI);}
		else if(joystick.joy2_TopHat==3){rackTwo(FAST);}
		else if(joystick.joy2_TopHat==1){rackTwo(-FAST);}
		else{rackTwo(0);}

		//Remaining Joystick Buttons - if(joy1Btn()==1){} - else if(joy1Btn()==1){}
		if(joy1Btn(1)==1||joy2Btn(3)==1){grab=true;}
		else if(joy1Btn(2)==1||joy2Btn(4)==1){grab=false;}
		else if(joy1Btn(5)==1||joy2Btn(2)==1){grabber(-MED);}
		else if(joy1Btn(6)==1||joy2Btn(1)==1){grabber(MED);}
		else if(joy1Btn(7)==1||joy2Btn(7)==1){lockOpen();}
		else if(joy1Btn(8)==1||joy2Btn(8)==1){lockClose();}
		else if(joy2Btn(5)==1){flapClose();}
		else if(joy2Btn(6)==1){flapOpen();}
		else{setMultiplier();grabberRun();}

	}//while
}//task main
