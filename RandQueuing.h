#ifndef RANDQUEUING_H_
#define RANDQUEUING_H_

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

#include "Unit.h"
#include "Job.h"
#include "greater1.h"

using namespace std;

// Nearly same with the MinQueuing class
// Only differs at next unit choosing method. ( whereToGoRand(Job& ) )
class RandQueuing{
	public:
		int N_job;
		int N_unit;
		double currentTime;
		list <int> *adj;
		Job *jobs;
		Unit *units;
		vector <Job> order;

		bool work(Job& myJob, int k);
		// Chooses next unit randomly.
		int whereToGoRand(Job& myJob);
		void simulate();
		void print(string fname);

		RandQueuing(string fname);
		~RandQueuing();
		
};


#endif
