#include "Simulator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

vector<Process> Simulator::loadProcesses(const string& filename) {
    vector<Process> processes;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: no se pudo abrir el archivo " << filename << endl;
        return processes;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        string id, token;
        int bt, at, q, p;
        stringstream ss(line);

        getline(ss, id, ';');
        getline(ss, token, ';'); bt = stoi(token);
        getline(ss, token, ';'); at = stoi(token);
        getline(ss, token, ';'); q  = stoi(token);
        getline(ss, token, ';'); p  = stoi(token);

        // eliminar espacios en id
        id.erase(remove_if(id.begin(), id.end(), ::isspace), id.end());

        processes.emplace_back(id, bt, at, q, p);
    }
    return processes;
}

void Simulator::printResults(vector<Process>& processes) {
    cout << "ID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &p : processes) {
        cout << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
             << p.completionTime << "\t" << p.turnaroundTime << "\t"
             << p.waitingTime << "\t" << p.responseTime << "\n";
    }
}

void Simulator::saveResults(vector<Process>& processes, const string& filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Error: no se pudo crear el archivo " << filename << endl;
        return;
    }

    out << "ID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &p : processes) {
        out << p.id << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
            << p.completionTime << "\t" << p.turnaroundTime << "\t"
            << p.waitingTime << "\t" << p.responseTime << "\n";
    }
    out.close();
}
