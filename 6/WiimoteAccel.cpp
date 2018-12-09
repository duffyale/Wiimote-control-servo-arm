#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include "WiimoteAccel.h"

using namespace std;

	WiimoteAccel::WiimoteAccel(){
	fd = open("/dev/input/event0", O_RDONLY);
        if (fd == -1)
        {
        std::cerr << "Error: Could not open event file - forgot sudo?\n";
        exit(1);
        }
	}

	WiimoteAccel::~WiimoteAccel(){
	close(fd);
	}
	
	void WiimoteAccel::AccelerationEvent(int code, short acceleration){
        // Print them
        std::cout << "Code = " << code << ", acceleration = " << acceleration << '\n';
        }
	

	void WiimoteAccel::Listen(){
	char buffer[16];
	
        // Read a packet of 16 bytes from Wiimote
        read(fd, buffer, 16);
        // Extract code (byte 10) and value (byte 12) from packet
	WiimoteAccel::code = buffer[10];
        WiimoteAccel::acceleration = * (short *) (buffer + 12);
	//AccelerationEvent(code, acceleration);
	
	}
	
