#include "FCFSScheduler.h"
#include <algorithm>

void FCFSScheduler::schedule(vector<Process>& processes, int quantum) {
    sort(processes.begin(), processes.end(),
         [](Process &a, Process &b){ return a.arrivalTime < b.arrivalTime; });

    int time = 0;
    for (auto &p : processes) {
        if (time < p.arrivalTime) time = p.arrivalTime;
        p.responseTime = time - p.arrivalTime;
        time += p.burstTime;
        p.completionTime = time;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
    }
}
