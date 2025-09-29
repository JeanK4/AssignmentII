#include "SJFScheduler.h"
#include <algorithm>

void SJFScheduler::schedule(vector<Process>& processes, int quantum) {
    vector<Process*> ready;
    int time = 0, completed = 0, n = processes.size();

    while (completed < n) {
        for (auto &p : processes)
            if (p.arrivalTime <= time && p.remainingTime > 0 &&
                find(ready.begin(), ready.end(), &p) == ready.end())
                ready.push_back(&p);

        if (ready.empty()) { time++; continue; }

        auto shortest = *min_element(ready.begin(), ready.end(),
                            [](Process* a, Process* b){ return a->burstTime < b->burstTime; });

        ready.erase(remove(ready.begin(), ready.end(), shortest), ready.end());

        shortest->responseTime = time - shortest->arrivalTime;
        time += shortest->burstTime;
        shortest->completionTime = time;
        shortest->turnaroundTime = shortest->completionTime - shortest->arrivalTime;
        shortest->waitingTime = shortest->turnaroundTime - shortest->burstTime;
        shortest->remainingTime = 0;
        completed++;
    }
}
