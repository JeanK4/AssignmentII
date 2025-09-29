#ifndef STCFSCHEDULER_H
#define STCFSCHEDULER_H

#include "Scheduler.h"

class STCFScheduler : public Scheduler {
public:
    void schedule(vector<Process>& processes, int quantum = 1) override;
};

#endif
