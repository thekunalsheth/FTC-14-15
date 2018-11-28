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

#include "JoystickDriver.c"


task main()
{	while(true)
	{
			getJoystickSettings(joystick);

			if(abs(joystick.joy1_y1)>10)
				{	motor (Lefttop)=joystick.joy1_y1*-0.3;
					motor (Leftbottom)=joystick.joy1_y1*-0.3;
				}


			else{
				motor (Lefttop)=0;
				motor (Leftbottom)=0;
				}



		  if(abs(joystick.joy1_y2)>10)
			{ motor (Righttop)=joystick.joy1_y2*-0.3;
				motor (Rightbottom)=joystick.joy1_y2*-0.3;
			}

			else{
					motor (Righttop)=0;
					motor (Rightbottom)=0;
					}

			if(joystick.joy2_TopHat==6)
			{ motor(Leftbottom)=(20);
				motor(Lefttop)=(20);
				motor(Rightbottom)=(20);
				motor(Righttop)=(20);
				wait1Msec(100);
				motor(Leftbottom)=(-20);
				motor(Lefttop)=(-20);
				motor(Rightbottom)=(-20);
				motor(Righttop)=(-20);
				wait1Msec(100);
			}

			else{}


			if(abs(joystick.joy2_y1)>10)
				{	motor(Firstrack)=joystick.joy2_y1*-0.5;
				}

			else{
				motor(Firstrack)=0;
			}

			if(abs(joystick.joy2_y2)>10)
				{ motor(Secondrack)=joystick.joy2_y2*-0.5;
				}

			else{
				motor(Secondrack)=0;
			}

			if(joy1Btn(5)==1 || joystick.joy2_TopHat==1)
			{ motor(Grabber)=60;
			}
			else if (joy1Btn(6)==1 || joystick.joy2_TopHat==4)
			{ motor(Grabber)=-60;
		  }
			else{
				motor(Grabber)=0;
				}

			if(joy2Btn(5)==1)
			{servo(Rackservo)= 128;
			}
			else if(joy2Btn(6)==1)













			{servo(Rackservo)= 255;
			}
			else{}

			if(joy2Btn(1)==1)
		  {servo(Goalservo)=180;
		  }
		  else if (joy2Btn(4)==1)
		  {servo(Goalservo)=70;
		  }
		  else{}


	}

}