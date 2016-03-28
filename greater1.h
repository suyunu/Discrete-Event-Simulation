#ifndef GREATER1_H_
#define GREATER1_H_

#include <iostream>

#include "Job.h"

using namespace std;

// Ordering rule for the heap
struct greater1{
	bool operator()(const Job & a, Job & b) const{
		return a.timeToGo > b.timeToGo;
	}
};



#endif
