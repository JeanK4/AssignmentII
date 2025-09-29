#ifndef PROCESS_H
#define PROCESS_H

#include <string>
using namespace std;

class Process {
public:
    string id;
    int burstTime, arrivalTime, priority, queue;
    int remainingTime;
    int completionTime, waitingTime, turnaroundTime, responseTime;

    Process(string id_, int bt, int at, int q, int p);
};

#endif
