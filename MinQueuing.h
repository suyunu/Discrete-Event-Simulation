#ifndef MINQUEUING_H_
#define MINQUEUING_H_

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "Unit.h"
#include "Job.h"
#include "greater1.h"

using namespace std;

class MinQueuing{
	public:
		// Number of jobs.
		int N_job;
		// Number of units.
		int N_unit;
		// Instant time of the factory. At the end it will be the total running time of the factory.
		// This increases when a unit finishes its job or a job enters the factory.
		double currentTime;
		// Adjacency list of the units.
		list <int> *adj;
		// Array of jobs.
		Job *jobs;
		// Array of units.
		Unit *units;
		// A heap that holds jobs with respect to ascending order of their "double timeToGo" variable.
		vector <Job> order;
		// Sends 'myJob' to the unit with no 'k'.
		// If the unit is working (isWorking == true), then puts 'myJob' into the job queue of that unit.
		// else that unit starts to process the job.
		bool work(Job& myJob, int k);
		// Chooses next unit ,which myJob can go, with 'minimum job queue'.
		int whereToGoMin(Job& myJob);
		// Simulates the factory (Explained in the .cpp)
		void simulate();
		// Prints out:
		// The total running time of the factory,
		// Utilization of units and max queue lengths.
		// Turnaround time of jobs
		void print(string fname);
	
		// Constructor
		MinQueuing(string fname);
		// Destructor
		~MinQueuing();
};

#endif
