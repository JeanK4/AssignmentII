#include "RRScheduler.h"
#include <queue>

void RRScheduler::schedule(vector<Process>& processes, int quantum) {
    queue<Process*> q;
    int time = 0, completed = 0, n = processes.size();
    vector<bool> inQueue(n, false);

    while (completed < n) {
        for (int i = 0; i < n; i++)
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0 && !inQueue[i]) {
                q.push(&processes[i]);
                inQueue[i] = true;
            }

        if (q.empty()) { time++; continue; }

        Process* p = q.front(); q.pop();
        inQueue[p - &processes[0]] = false;

        if (p->responseTime == -1) p->responseTime = time - p->arrivalTime;

        int execTime = min(quantum, p->remainingTime);
        p->remainingTime -= execTime;
        time += execTime;

        for (int i = 0; i < n; i++)
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0 && !inQueue[i]) {
                q.push(&processes[i]);
                inQueue[i] = true;
            }

        if (p->remainingTime > 0) {
            q.push(p);
            inQueue[p - &processes[0]] = true;
        } else {
            p->completionTime = time;
            p->turnaroundTime = p->completionTime - p->arrivalTime;
            p->waitingTime = p->turnaroundTime - p->burstTime;
            completed++;
        }
    }
}
