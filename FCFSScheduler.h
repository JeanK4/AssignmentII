#ifndef FCFSSCHEDULER_H
#define FCFSSCHEDULER_H

#include "Scheduler.h"

class FCFSScheduler : public Scheduler {
public:
    void schedule(vector<Process>& processes, int quantum = 1) override;
};

#endif
