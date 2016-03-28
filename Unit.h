#ifndef UNIT_H_
#define UNIT_H_

#include <iostream>
#include <queue>

#include "Job.h"

using namespace std;

class Unit{
	public:
		// No of this unit according to the order of appearance.
		int no;
		// Processing time of this unit.
		double procTime;
		// Job queue of this unit
		queue <Job> jobQ;
		// Maximum number of elements reached in the queue during simulation.
		int maxQ;
		// Number of jobs processed by this unit.
		int Jcounter;
		// Number of adjacent unit.
		int edges;
		// Condition of this unit. True if this unit has a job in process.
		bool isWorking;

		// Constructor
		Unit();
		// Destructor
		~Unit();
};

#endif
