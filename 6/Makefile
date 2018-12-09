#RoboticArm throwing 

run: main.o RoboticArm.o WiimoteBtns.o WiimoteAccel.o
	g++ main.o RoboticArm.o WiimoteBtns.o WiimoteAccel.o -o run 

main.o: main.cpp RoboticArm.h WiimoteBtns.h WiimoteAccel.h
	g++ -g -Wall -c main.cpp

RoboticArm.o: RoboticArm.cpp RoboticArm.h
	g++ -g -Wall -c RoboticArm.cpp

WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
	g++ -g -Wall -c WiimoteBtns.cpp

WiimoteAccel.o: WiimoteAccel.cpp WiimoteAccel.h
	g++ -g -Wall -c WiimoteAccel.cpp

clean:
	rm *.o run
