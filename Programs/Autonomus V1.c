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
//*!!Code automatically generated by 'ROBOTC' configuration wizard

void Left(int S)
{	motor(LR)=S;
	motor(LF)=S;}

void Right(int S)
{	motor(RR)=S;
	motor(RF)=S;}


task main()
{
Left(20);
Right(20);
servo[S2]=80;
wait1Msec(500);

Left(10);
Right(10);
wait1Msec(1500);

Left(0);
Right(0);
wait10Msec(50);

Left(-30);
Right(30);
wait10Msec(20);

Left(0);
Right(0);
wait10Msec(50);

Left(20);
Right(20);
wait1Msec(2500);

Left(0);
Right(0);
wait10Msec(50);

Right(20);
wait1Msec(500);



}
