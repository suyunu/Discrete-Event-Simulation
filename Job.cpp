#include "Job.h"

using namespace std;

Job::Job(){
	no = enterTime = timeToGo = 0;
	cond = -1;
}

Job::~Job(){}

void Job::initialize(int No, double enter_time){
	no = No;
	enterTime = enter_time;
	timeToGo = enter_time;
	cond = -1;
}
