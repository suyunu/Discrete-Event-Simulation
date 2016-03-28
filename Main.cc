#include <iostream>

#include "MinQueuing.h"
#include "RandQueuing.h"

using namespace std;

	
int main(int argc, char *argv[]){
	srand(time(0));
	
	RandQueuing rndQue(argv[1]);
	MinQueuing minQue(argv[1]);
	
	rndQue.simulate();
	minQue.simulate();
	
	rndQue.print(argv[2]);
	minQue.print(argv[3]);
	
	return (0-0);
}
