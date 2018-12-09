#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <iostream>
#include <cmath> 
#include "WiimoteBtns.h"
#include "WiimoteAccel.h"
#include "RoboticArm.h"
using namespace std;
int main()
{ 
	int i;
    	WiimoteBtns btns = WiimoteBtns();
	WiimoteAccel Accel; 
    	RoboticArm Robotic_arm;
	 
	while (true)
	{
		btns.Listen();

	       	if (btns.code == 103 && btns.value == 1 )
		{
		 for(i=0;i<140;i++){
 
        			Robotic_arm.MoveServo(4,i++, 45);
				cout << "top pressed" << endl;
				cout <<"angle is: " << i << endl;
				}			
    		}
		
		if (btns.code == 108 && btns.value == 1 )
		{
        			Robotic_arm.MoveServo(4, i--, 45);
				cout << "bot pressed" << endl;
				cout << "angle is: " << i << endl; 
    	        }
		Accel.Listen();
		
		if(Accel.code == 5 && Accel.acceleration<180 && Accel.acceleration >0)
		{
				Robotic_arm.MoveServo(3,Accel.acceleration,30);
				cout << "accel is: " << Accel.acceleration << endl;
		}
		if(Accel.code == 3 && Accel.acceleration < 180 && Accel.acceleration>0)
		{
				Robotic_arm.MoveServo(0,Accel.acceleration,30);
				cout << "accel for x is: " << Accel.acceleration << endl;
		}

	}
}


