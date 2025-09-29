#include "STCFScheduler.h"
#include <algorithm>

void STCFScheduler::schedule(vector<Process>& processes, int quantum) {
    int time = 0, completed = 0, n = processes.size();

    while (completed < n) {
        // elegir proceso con menor tiempo restante disponible en este instante
        Process* current = nullptr;
        for (auto &p : processes) {
            if (p.arrivalTime <= time && p.remainingTime > 0) {
                if (current == nullptr || p.remainingTime < current->remainingTime) {
                    current = &p;
                }
            }
        }

        if (current == nullptr) {
            time++; // si no hay procesos listos, avanza el reloj
            continue;
        }

        // si es la primera vez que se ejecuta, calcula RT
        if (current->responseTime == -1) {
            current->responseTime = time - current->arrivalTime;
        }

        // ejecutar 1 unidad de tiempo
        current->remainingTime--;
        time++;

        // si terminó
        if (current->remainingTime == 0) {
            current->completionTime = time;
            current->turnaroundTime = current->completionTime - current->arrivalTime;
            current->waitingTime = current->turnaroundTime - current->burstTime;
            completed++;
        }
    }
}
