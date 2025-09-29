#include "Process.h"

Process::Process(string id_, int bt, int at, int q, int p)
    : id(id_), burstTime(bt), arrivalTime(at), priority(p), queue(q) {
    remainingTime = bt;
    completionTime = waitingTime = turnaroundTime = responseTime = -1;
}
