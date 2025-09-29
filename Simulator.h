#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <string>
#include "Process.h"
using namespace std;

class Simulator {
public:
    vector<Process> loadProcesses(const string& filename);
    void printResults(vector<Process>& processes);

    void saveResults(vector<Process>& processes, const string& filename);
};

#endif
