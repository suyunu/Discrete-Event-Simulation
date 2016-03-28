#ifndef JOB_H_
#define JOB_H_

#include <iostream>

using namespace std;

class Job{
	public:
		// No of this job according to the order of appearance
		int no;
		// Enter time to the factory
		double enterTime;
		// Holds the check-out time from the last unit.
		double timeToGo;
		// No of the unit which this job has been lastly processed.
		// (if cond == -1, then this job has just entered to the factory).
		int cond;

		// Initialization of the variables in this class
		void initialize(int No, double enter_time);
		// Constructor
		Job();
		// Destructor
		~Job();
};



#endif
