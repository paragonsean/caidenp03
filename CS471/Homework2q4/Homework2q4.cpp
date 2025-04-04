#include <iostream>
#include <cmath>

using namespace std;

    class Process {
        public:
        int arrivalTime = 0;
        int burstTime = 0;
        int priority = 0;
        int remainingTime = 0;
        int completionTime = 0;
    };

int main() {

   
    Process p1;
    Process p2;
    Process p3;
    Process p4;

    p1.arrivalTime = 10;
    p1.burstTime = 20;
    p1.priority = 1;
    p1.remainingTime = p1.burstTime;
    p1.completionTime = p1.burstTime;

    p2.arrivalTime = 35;
    p2.burstTime = 5;
    p2.priority = 2;
    p2.remainingTime = p2.burstTime;
    p2.completionTime = p2.burstTime;

    p3.arrivalTime = 45;
    p3.burstTime = 10;
    p3.priority = 3;
    p3.remainingTime = p3.burstTime;
    p3.completionTime = p3.burstTime;

    p4.arrivalTime = 50;
    p4.burstTime = 50;
    p4.priority = 4;
    p4.remainingTime = p4.burstTime;
    p4.completionTime = p4.burstTime;

    int time = 0;
    time = p1.arrivalTime;
    time = time + p1.burstTime;
    p1.completionTime = time;
    if (time < p2.arrivalTime) {
        time = p2.arrivalTime;
        time += p2.burstTime;
    }
    else {
        time += p2.burstTime;
    }
    p2.completionTime = time;
    if (time < p3.arrivalTime) {
        time = p3.arrivalTime;
        time += p3.burstTime;
    }
    else {
        time += p3.burstTime;
    }
    p3.completionTime = time;
    if (time < p4.arrivalTime) {
        time = p4.arrivalTime;
        time += p4.burstTime;
    }
    else {
        time += p4.burstTime;
    }
    p4.completionTime = time;

    cout << "Process 1 completion time: " << p1.completionTime << endl;
    cout << "Process 2 completion time: " << p2.completionTime << endl;
    cout << "Process 3 completion time: " << p3.completionTime << endl;
    cout << "Process 4 completion time: " << p4.completionTime << endl;

    return 0;
}