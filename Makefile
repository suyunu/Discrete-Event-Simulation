all: Main.o Job.o Unit.o RandQueuing.o MinQueuing.o
	g++ Main.o Job.o Unit.o RandQueuing.o MinQueuing.o -o DiscEventSim

Job.o: Job.cpp
	g++ -c -std=c++11 Job.cpp

Unit.o: Unit.cpp
	g++ -c -std=c++11 Unit.cpp

RandQueuing.o: RandQueuing.cpp
	g++ -c -std=c++11 RandQueuing.cpp

MinQueuing.o: MinQueuing.cpp
	g++ -c -std=c++11 MinQueuing.cpp

Main.o: Main.cc
	g++ -c -std=c++11 Main.cc

clean:
	rm -rf *o  DiscEventSim
