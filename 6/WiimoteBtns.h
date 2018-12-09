#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

//create class WiimoteBtns 
class WiimoteBtns{
	private:
		int fd;
	//	int code;
	//	int value;
	public:
		int code; 
		int value;
		//open wiimote event file
		WiimoteBtns();
		//close wiimote event file 
		~WiimoteBtns();
		//function that extract the value for code and value for the buttons from wiimote control 
		void Listen();
		//print out value for code and value 
		void ButtonEvent(int code, int value);
};

#endif
