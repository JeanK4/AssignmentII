#include <iostream>
#include "Simulator.h"
#include "FCFSScheduler.h"
#include "SJFScheduler.h"
#include "RRScheduler.h"
#include "STCFScheduler.h"
using namespace std;

int main() {
    Simulator sim;

    // ================== FCFS ==================
    {
        vector<Process> processes = sim.loadProcesses("entrada1.txt");
        FCFSScheduler scheduler;
        scheduler.schedule(processes);
        sim.saveResults(processes, "salida_fcfs.txt");
        cout << "Resultados FCFS guardados en salida_fcfs.txt" << endl;
    }

    // ================== SJF ==================
    {
        vector<Process> processes = sim.loadProcesses("entrada1.txt");
        SJFScheduler scheduler;
        scheduler.schedule(processes);
        sim.saveResults(processes, "salida_sjf.txt");
        cout << "Resultados SJF guardados en salida_sjf.txt" << endl;
    }

    // ================== Round Robin ==================
    {
        vector<Process> processes = sim.loadProcesses("entrada1.txt");
        RRScheduler scheduler;
        scheduler.schedule(processes, 3); // Quantum = 3
        sim.saveResults(processes, "salida_rr.txt");
        cout << "Resultados RR guardados en salida_rr.txt" << endl;
    }

    // ================== STCF (preemptive SJF) ==================
    {
        vector<Process> processes = sim.loadProcesses("entrada1.txt");
        STCFScheduler scheduler;
        scheduler.schedule(processes);
        sim.saveResults(processes, "salida_stcf.txt");
        cout << "Resultados STCF guardados en salida_stcf.txt" << endl;
    }

    return 0;
}
