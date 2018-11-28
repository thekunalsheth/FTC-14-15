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

/*CONTROLS
<<<<< - JOYSTICK 1 - >>>>>
	Analogue 1 - Left Motors
	Analogue 2 - Right Motors
	Buttons
		1 - Grabber On
		2 - Grabber Off
		3 - Rack 1 Down
		4 - Rack 1 Up
		5 - Grabber Outside
		6 - Grabber Inside
		7 - Lock Open
		8 - Lock Close
		9 - Left Boost
		10 - Right Boost
	TopHat
		0 - Slow Forward
		1 -
		2 - Slow Right
		3 -
		4 - Slow Backward
		5 -
		6 - Slow Left
		7 -
<<<<< - JOYSTICK 2 - >>>>>
	Analogue 1 - Rack 1
	Analogue 2 - Rack 2
	Buttons
		1 - Grabber Inside
		2 - Grabber Outside
		3 - Grabber On
		4 - Grabber Off
		5 - Flap Close
		6 - Flap Open
		7 -
		8 -
		9 -
		10 -
	TopHat
		0 -
		1 -
		2 -
		3 -
		4 -
		5 -
		6 - shake
		7 -
*/
#define MED 50
#define SLOW 20
#define FAST 100
#define MMULTI -0.5
#define SMULTI -0.3
#define FMULTI -1
#include "JoystickDriver.c"
int grabberlogic=0;
int multiplier=MMULTI;
int leftMultiplier=MMULTI;
int rightMultiplier=MMULTI;
void left(int S){motor[LR]=S;motor[LF]=S;}//moves left motors
void right(int S){motor[RF]=S;motor[RR]=S;}//moves right motors
void forward(int S){left(S);right(S);}//moves all motors forward
void backward(int S){left(-S);right(-S);}//moves all motors backward
void grabber(int S){motor[G]=S;}//moves grabber
void rackOne(int S){motor[Rack1]=S;}//moves the front rack
void rackTwo(int S){motor[Rack2]=S;}//moves the rear rack
void flapOpen(){servo[S1]=255;}//opens flap on rear rack
void flapClose(){servo[S1]=128;}//closes flap on rear rack
void lockOpen(){servo[S2]=160;}//opens rolling goal lock
void lockClose(){servo[S2]=50;}//closes rolling goal lock
void shake(){forward(SLOW);wait1Msec(100);backward(SLOW);wait1Msec(100);forward(0);backward(0);}//shakes the bot
/*void analogueMove(){if(abs(joystick.joy1_y1)>10){left(joystick.joy1_y1*leftMultiplier);}
										else{left(0);}
										if(abs(joystick.joy1_y2)>10){right(joystick.joy1_y2*rightMultiplier);}
										else{right(0);}}//moves the bot with joystick1
void analogueRack(){if(abs(joystick.joy2_y1)>10){rackOne(joystick.joy2_y1*multiplier);}
										else{rackOne(0);}
										if(abs(joystick.joy2_y2)>10){rackTwo(joystick.joy2_y2*multiplier);}
										else{rackTwo(0);}}//moves the rack with joystick2*/
void grabberRun(){if(grabberlogic==1){grabber(70);}
									else{grabber(0);}}//runs the grabber inside continously
/*void setMulti(){if(joy1Btn(9)==1){leftMultiplier=FMULTI;}
								else{leftMultiplier=SMULTI;}
								if(joy1Btn(10)==1){rightMultiplier=FMULTI;}
								else{rightMultiplier=SMULTI;}}//boosts the drive motors*/
task main(){
	while(true){
		getJoystickSettings(joystick);
		/*switch(joystick.joy1_TopHat){
			case 0:
			forward(-SLOW);
			break;
			case 2:
			left(-SLOW);//left motors forward, hence right swing turn
			break;
			case 4:
			backward(-SLOW);
			break;
			case 6:
			right(-SLOW);//right motors forward, hence left swing turn
			break;
			default:*/
			//Joystick - 1
			if(joy1Btn(1)==1){grabberlogic=1;}//joy1(1)
			else if(joy1Btn(2)==1){grabberlogic=0;}//joy1(2)
			else if(joy1Btn(3)==1){rackOne(FAST);}//joy1(3)
			else if(joy1Btn(4)==1){rackOne(-FAST);}//joy1(4)
			else if(joy1Btn(5)==1){grabber(-MED);}//joy1(5)
			else if(joy1Btn(6)==1){grabber(MED);}//joy1(6)
			else if(joy1Btn(7)==1){lockClose();}//joy1(7)
			else if(joy1Btn(8)==1){lockOpen();}//joy1(8)
			//Joystick - 2
			else if(joy2Btn(1)==1){grabber(-MED);}//joy2(1)
			else if(joy2Btn(2)==1){grabber(MED);}//joy2(2)
			else if(joy2Btn(3)==1){grabberlogic=1;}//joy2(3)
			else if(joy2Btn(4)==1){grabberlogic=0;}//joy2(4)
			else if(joy2Btn(5)==1){flapOpen();}//joy2(5)
			else if(joy2Btn(6)==1){flapClose();}//joy2(6)
			else if(joy2Btn(7)==1){lockClose();}//joy2(7)
			else if(joy2Btn(8)==1){lockOpen();}//joy2(8)
			else if(joystick.joy2_TopHat==6){shake();}
			//Mixed parallels
			else{grabberRun();}
			/*if(abs(joystick.joy2_y1)>10){rackOne(joystick.joy2_y1*multiplier);}
			else{rackOne(0);}
			if(abs(joystick.joy2_y2)>10){rackTwo(joystick.joy2_y2*multiplier);}
			else{rackTwo(0);}
			if(abs(joystick.joy1_y1)>10){left(joystick.joy1_y1*multiplier);}
			else{left(0);}
			if(abs(joystick.joy1_y2)>10){right(joystick.joy1_y2*multiplier);}
			else{right(0);}
						/*setMulti();analogueMove();analogueRack();grabberRun();}}*/
			/*break;}*/
			if(abs(joystick.joy1_y1)>10){left(joystick.joy1_y1*multiplier);}
			else if(joystick.joy1_TopHat==1){forward(-SLOW);}
			else if(joystick.joy1_TopHat==2){left(-SLOW);}
			else if(joystick.joy1_TopHat==4){backward(-SLOW);}
			else{left(0);}
			if(abs(joystick.joy1_y2)>10){right(joystick.joy1_y2*multiplier);}
			else if(joystick.joy1_TopHat==1){forward(-SLOW);}
			else if(joystick.joy1_TopHat==4){backward(-SLOW);}
			else if(joystick.joy1_TopHat==6){right(-SLOW);}
			else{right(0);}
			if(abs(joystick.joy2_y1)>10){rackOne(joystick.joy2_y1*multiplier);}
			else if(joy1Btn(3)==1||joy2Btn(1)==1){rackOne(FAST);}//joy1(3)joy2(1)
			else if(joy1Btn(4)==1||joy2Btn(2)==1){rackOne(-FAST);}//joy1(4)joy2(2)
			else{rackOne(0);}
			if(abs(joystick.joy2_y2)>10){rackTwo(joystick.joy2_y2*multiplier);}
			else if(joy2Btn(3)==1){rackTwo(FAST);}//joy2(3)-
			else if(joy2Btn(4)==1){rackTwo(-FAST);}//joy2(4)
			else{rackTwo(0);}
	}
}