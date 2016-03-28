#include "RandQueuing.h"

using namespace std;

RandQueuing::RandQueuing(string fname){
	int i, j;
	
	currentTime = 0;
	
	ifstream fin (fname);
	
	fin >> N_unit;
	
	adj = new list<int>[N_unit];
	units = new Unit[N_unit];
	
	if (fin.good()){
		string str;
		for(i = 0 ; i < N_unit ; i++){
			int d;
			fin >> units[i].no >> units[i].procTime;;
			getline(fin, str);
			istringstream ss(str);
			while(ss >> d){
				units[i].edges++;
				adj[i].push_back(d);
			}
		}
	}
	
	fin >> N_job;
	jobs = new Job[N_job];
	
	for(i = 0 ; i < N_job ; i++){
		double enter_time;
		fin >> enter_time;
		jobs[i].initialize(i, enter_time);
		order.push_back(jobs[i]);
	}
	
	make_heap(order.begin(), order.end(), greater1());

}

RandQueuing::~RandQueuing(){
	delete[] adj;
	delete[] jobs;
	delete[] units;
}

void RandQueuing::simulate(){
	Job current;
	
	while(!order.empty()){
		pop_heap(order.begin(),order.end(),greater1());
		current = order.back();
		order.pop_back();
		
		currentTime = current.timeToGo;
		
		if(current.cond == -1){
			work(current, 0);
		}
		else{
			int toGo = whereToGoRand(current);
			if(!units[current.cond].jobQ.empty()){
				units[current.cond].Jcounter++;
				Job temp = units[current.cond].jobQ.front();
				units[current.cond].jobQ.pop();
				
				temp.timeToGo = currentTime + units[current.cond].procTime;
				jobs[temp.no] = temp;
				
				order.push_back(temp);
				push_heap (order.begin(),order.end(),greater1());
			}
			else
				units[current.cond].isWorking = false;
			
			if(toGo != -1)
				work(current, toGo);
		}
	}
}

bool RandQueuing::work(Job& myJob, int k){
	myJob.cond = k;
	if(!units[k].isWorking){
		units[k].Jcounter++;
		units[k].isWorking = true;
		myJob.timeToGo += units[k].procTime;
		
		order.push_back(myJob);
		push_heap (order.begin(),order.end(),greater1());
	}
	else{
		units[k].jobQ.push(myJob);
		if(units[k].jobQ.size() > units[k].maxQ){
			units[k].maxQ = units[k].jobQ.size();
		}
	}
	jobs[myJob.no] = myJob;
}

int RandQueuing::whereToGoRand(Job& myJob){
	if(units[myJob.cond].edges > 0){
		int rnd = rand() % units[myJob.cond].edges;
		list<int>::iterator it = adj[myJob.cond].begin();
		for(int i = 0 ; i < rnd ; i++, it++);
		return *it;
	}
	else
		return -1;
}

void RandQueuing::print(string fname){
	ofstream fout (fname);
	
	int i;
	
	fout << fixed;
	fout.precision(4);
	fout << currentTime <<endl;
	
	fout.precision(2);
	for(i = 0 ; i < N_unit ; i++)
		fout << i << " " << units[i].Jcounter * units[i].procTime / currentTime << " " << units[i].maxQ <<endl;
	
	fout.precision(4);
	for(i = 0 ; i < N_job ; i++)
		fout << i << " " << jobs[i].timeToGo - jobs[i].enterTime <<endl;
}


