#ifndef WIIMOTEACCEL_H
#define WIIMOTEACCEL_H

class WiimoteAccel{
	private:
	int fd;
	//int code;
	//short acceleration;
	public:
	int code; 
	short acceleration;
	WiimoteAccel();
	~WiimoteAccel();
	void Listen();
        void AccelerationEvent(int code, short acceleration);
};

#endif
