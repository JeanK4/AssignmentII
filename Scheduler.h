#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"
using namespace std;

class Scheduler {
public:
    virtual void schedule(vector<Process>& processes, int quantum = 1) = 0;
    virtual ~Scheduler() {}
};

#endif
