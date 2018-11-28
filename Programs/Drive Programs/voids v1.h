//		<<		Defining Constants	>>
#define VERYSLOW 10
#define SLOW 25
#define MED 50
#define FAST 75
#define VERYFAST 100
#define NORMALMULTI -0.2
#define FULLMULTI -0.8
#define JOYSTICKDEADZONE 15


//		<<		Defining Functions	>>
void left(int S){ motor[frontLeft]=S; motor[rearLeft]=S; return; }
void right(int S){ motor[frontRight]=S; motor[rearRight]=S; return; }
void forward(int S){ left(-S); right(-S); }
void backward(int S){ left(S); right(S); return; }
void leftPoint(int S){ left(-S); right(S); return; }
void rightPoint(int S){ left(S); right(-S); return; }
void leftSwing(int S){ left(0); right(S); return; }
void rightSwing(int S){ left(S); right(0); return; }
void wait(int T){ wait1Msec(T); return; }
void stopDrive(){ forward(0); return; }
int logarithmicScaling(int S){ S=(((S^2)/(127^2))*100) ; return S; }
void leftAnalogue(){ if(abs(joystick.joy1_y1)>JOYSTICKDEADZONE){ left(joystick.joy1_y1*NORMALMULTI); } else{ left(0); return; } }
void rightAnalogue(){ if(abs(joystick.joy1_y2)>JOYSTICKDEADZONE){ right(joystick.joy1_y2*NORMALMULTI); } else{ right(0); return; } }
void leftAnalogueBoost(){ if(abs(joystick.joy1_y1)>JOYSTICKDEADZONE){ left(joystick.joy1_y1*FULLMULTI); } else{ left(0); return; } }
void rightAnalogueBoost(){ if(abs(joystick.joy1_y2)>JOYSTICKDEADZONE){ right(joystick.joy1_y2*FULLMULTI); } else{ right(0); return; } }
void leftAnalogueL(){ if(abs(joystick.joy1_y1)>JOYSTICKDEADZONE){ left(logarithmicScaling(joystick.joy1_y1)); } else{ left(0); return; } }
void rightAnalogueL(){ if(abs(joystick.joy1_y2)>JOYSTICKDEADZONE){ right(logarithmicScaling(joystick.joy1_y2)); } else{ right(0); return; } }
