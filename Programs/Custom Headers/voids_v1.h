//		<<		Defining Constants	>>																																																									*
#define VERYSLOW 10
#define SLOW 25
#define MED 50
#define FAST 75
#define VERYFAST 100
#define NORMALMULTI -0.2
#define FULLMULTI -0.8
#define JOYSTICKDEADZONE 15

//		<<		Defining Variables	>>
int logarithmicScaling(int S){ S=(((S^2)/(127^2))*100) ; return S; }
int grab=0;
//int turnType=0;

//		<<		Defining Functions	>>
void left(int S){ motor[frontLeft]=S; motor[rearLeft]=S; return; }
void right(int S){ motor[frontRight]=S; motor[rearRight]=S; return; }
void forward(int S){ left(-S); right(-S); return; }
void backward(int S){ left(S); right(S); return; }
void leftPoint(int S){ left(-S); right(S); return; }
void rightPoint(int S){ left(S); right(-S); return; }
void leftSwing(int S){ left(0); right(S); return; }
void rightSwing(int S){ left(S); right(0); return; }
//void turnDegrees(int Power, int Degree, string Type){ if(Type=="swing"){ turnType=1; } else if(Type=="point"){ turnType=0; } else{ turnType=0; } }
void wait(int T){ wait1Msec(T); return; }
void stopDrive(){ forward(0); return; }
void liftMotors(int S){ motor[liftUp]=S; motor[liftDown]=S; return; }
void leftAnalogue(){ if(abs(joy1_y1)>JOYSTICKDEADZONE){ left(joy1_y1*NORMALMULTI); } else{ left(0); return; } }
void rightAnalogue(){ if(abs(joy1_y2)>JOYSTICKDEADZONE){ right(joy1_y2*NORMALMULTI); } else{ right(0); return; } }
void leftAnalogueBoost(){ if(abs(joy1_y1)>JOYSTICKDEADZONE){ left(joy1_y1*FULLMULTI); } else{ left(0); return; } }
void rightAnalogueBoost(){ if(abs(joy1_y2)>JOYSTICKDEADZONE){ right(joy1_y2*FULLMULTI); } else{ right(0); return; } }
void leftAnalogueL(){ if(abs(joy1_y1)>JOYSTICKDEADZONE){ left(logarithmicScaling(joy1_y1)); } else{ left(0); return; } }
void rightAnalogueL(){ if(abs(joy1_y2)>JOYSTICKDEADZONE){ right(logarithmicScaling(joy1_y2)); } else{ right(0); return; } }
void tankDrive(){ if(joy1_Buttons==1024){ leftAnalogueBoost(); } else{ leftAnalogue(); return; }
						if(joy1_Buttons==2048){ rightAnalogueBoost(); } else{rightAnalogue(); return; } }
void liftButton(int Power, int startButton, int stopButton){ if(joy1_Buttons==startButton){ liftMotors(Power); } else if(joy1_Buttons==stopButton){ liftMotors(-Power); } else{ liftMotors(0); } }
//void liftDrive(){ if(abs(joy2_Y2)>JOYSTICKDEADZONE){ liftMotors(joy2_Y1*NORMALMULTI); } else{ liftMotors(0); return;	} }
/*void lift(int Power, int Height){ while(SensorValue(ultraLift) < Height+5){liftMotors(Power); }
												liftMotors(Power); wait(200);
												while(SensorValue(ultraLift) > (Height+2)){liftMotors(-Power); } liftMotors(0); return; }*/
void grabberSlide(int Power){ motor[grabberSlider]=Power; }
void setGrabberSlider(int Power, int in, int out){ if(joy1_Buttons==in){ grabberSlide(Power); } else if(joy1_Buttons==out){ grabberSlide(-Power); } else{ grabberSlide(0); } }
void grabberRun(int Power){ motor[grabberRotor]=Power; }
void grabberAuto(int Power){ if(grab==1){ grabberRun(Power); } else{ grabberRun(0); } }
void setGrabber(int Power, int startButton, int stopButton){ if(joy1_Buttons==startButton){ grab=1; } else if(joy1_Buttons==stopButton) { grab=0; return; } grabberAuto(Power); }
