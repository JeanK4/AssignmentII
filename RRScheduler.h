#ifndef RRSCHEDULER_H
#define RRSCHEDULER_H

#include "Scheduler.h"

class RRScheduler : public Scheduler {
public:
    void schedule(vector<Process>& processes, int quantum = 2) override;
};

#endif
