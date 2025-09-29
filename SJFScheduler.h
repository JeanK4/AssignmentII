#ifndef SJFSCHEDULER_H
#define SJFSCHEDULER_H

#include "Scheduler.h"

class SJFScheduler : public Scheduler {
public:
    void schedule(vector<Process>& processes, int quantum = 1) override;
};

#endif
