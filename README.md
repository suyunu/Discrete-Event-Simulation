# Discrete Event Simulation

Assume that we want to simulate a hypothetical factory that processes some jobs. The factory is composed of units, where each unit has a job queue and a worker. The worker is the main part which processes a job, and the job queue is the place where the next jobs are waiting to be processed. Once a unit processes a job, it pushes the job to one of the next possible units according to the factory layout. Each job may follow a different path in the factory and once a job is processed in an output unit, it's gone out of the system.

## Factory Layout

Figure 1 shows a sample factory with 5 units. In each factory, Unit 0 is the single unit that act as the input unit. It accepts jobs and starts their processing. The units with incoming and outgoing connections are the intermediate units, such as Unit 1 and Unit 2 in this example. There may be many output units, which does not have an outgoing connection to another unit. In this example Unit 3 and Unit 4 are the output units. The layout of each factory is going to be represented with graph structure.

![Figure 1](http://i1027.photobucket.com/albums/y338/suyunu/Capture_zpshlymutrl.jpg)

## How factory works?

The factory start working by waiting for the jobs which arrive sequentially but not at the same time. The units may be either idle, waiting for jobs, or busy processing them. We assume that each unit has a constant processing time for each job. After the processing is complete, the job is passed to one of the next units in the factory by two different ways:

1. Randomly: Next unit is selected uniformly randomly. That's if a unit has n outgoing connections, the job will be assigned each of the next units with probability 1/n.

2. Unit with shortest queue first: The unit with the shortest queue length will be get the job. If the queue lengths are equal, assign the job to the unit that's first mentioned in the adjacency list.

## Input and Output Details

`./DiscEventSim [input_file] [output_file_1] [output_file_2]`

where input file contains the factory layout and job arrival times, and output file 1 contains the
output of the factory with random unit choice, and output file 2 contains the output of the factory
with shortest queue unit choice.

### The input file format:
1. First line is the number of units in the system, let's say N.
2. The next N lines are the factory layout represented as an adjacency list. Each line has the following format:
UnitNumber ProcessingTime [List of preceeding units] ...
3. The next line is the number of jobs, let's say J.
4. The next J lines are the arrival times of jobs. They are positive values in double precision.

### The output file format:
1. First line is the total running time of the factory.
2. The next N lines are the utilization of units and max queue lengths.
3. The next J lines are the turnaround time of jobs.
