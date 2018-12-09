#include <stdlib.h> // C standard general Utilities library 
#include <fcntl.h> //function control 
#include <unistd.h>
#include <iostream>
#include "WiimoteBtns.h"

	//constructor(open Wiimote event file)
	WiimoteBtns::WiimoteBtns(){
	fd = open("/dev/input/event2", O_RDONLY | O_NONBLOCK);
	if (fd == -1)
	{
  	std::cerr << "Error: Could not open event file - forgot sudo?\n";
  	exit(1);
   	}
	}

	//destructor
	WiimoteBtns::~WiimoteBtns(){
	close(fd);// Close Wiimote event file 
	}

    void WiimoteBtns::Listen(){
	char buffer[32]; // Read a packet of 32 bytes from Wiimote
	
	read(fd, buffer, 32);
        // Extract code (byte 10) and value (byte 12) from packet
        WiimoteBtns::code = buffer[10];
        WiimoteBtns::value = buffer[12];
		ButtonEvent(code, value);
	
	}

	//print out value for code and value t
	void WiimoteBtns::ButtonEvent(int code, int value){
        std::cout << "Code = " << code << ", value = " << value << '\n';
        }

	    
