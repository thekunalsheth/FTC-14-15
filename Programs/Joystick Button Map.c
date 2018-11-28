#include"JoystickDriver.c"

task main()
{
// Joystick button defines for use with joy1Btn() and joy2Btn()
#define ROBOTC_JOYBTN_1 1
#define ROBOTC_JOYBTN_2 2
#define ROBOTC_JOYBTN_3 3
#define ROBOTC_JOYBTN_4 4
//runJoystickButtonTest()
{
while(true)
{ // get joystick settings getJoystickSettings(joystick); // must read joystick before calling joy1Btn() // show the button value
nxtDisplayTextLine(2, "Button = %d", joystick.joy1_Buttons);
wait1Msec(250); // put a wait in so we can see current button pressed
 }
 }
}
