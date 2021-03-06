#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     Rightbottom,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     Leftbottom,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     Firstrack,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Secondrack,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Grabber,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     useless,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     Righttop,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C4_2,     Lefttop,       tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    Rackservo,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    Goalservo,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void Left(int S)
{	motor(Leftbottom)=S;
	motor(Lefttop)=S;}

void Right(int S)
{	motor(Rightbottom)=S;
	motor(Righttop)=S;}


task main()
{
	Left(20);
Right(20);
servo[Goalservo]=255;
servo(Rackservo)=255;
wait1Msec(500);

Left(10);
Right(10);
wait1Msec(1500);

Left(0);
Right(0);
wait10Msec(50);

Left(-30);
Right(30);
wait10Msec(12.5);
//point turn

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
wait1Msec(600);

Left(10);
Right(10);
wait1Msec(750);

Left(0);
Right(0);
wait10Msec(50);


motor(SecondRack)=-80;
wait1Msec(4000);

servo[Rackservo]=128;
wait1Msec(500);

servo(Goalservo)=130;
wait1Msec(500);

Left(40);
right(40);
wait10Msec(10);

Left(-40);
right(-40);
wait10Msec(10);

Right(-20);
Left(-20);
servo(Goalservo)=130;
wait1Msec(6000);

Left(-20);
Right(20);
servo(Goalservo)=128;
wait1Msec(1000);

Left(-20);
Right(-20);
servo(Goalservo)=126;
motor(Secondrack)=80;
wait1Msec(1000);

Left(-20);
Right(20);
servo(Goalservo)=126;
wait1Msec(750);

Left(0);
Right(0);
wait10Msec(50);

motor(Secondrack)=80;
Right(20);
wait1Msec(1000);

Left(0);
Right(0);
wait10Msec(50);

motor(Secondrack)=80;
wait1Msec(1500);

}
