#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <atomic>

using namespace std;

std::atomic<int> flag[2] = {{0}, {1}};
std::atomic<int> turn;

void process(int id) {
        time_t currentTime = time(0); // Get current time
        char* timeString = std::ctime(&currentTime); // Convert to string
    do{
        flag[id] = 1;
        //cout << "process " << id << "is waiting" << endl;
        turn = 1 - id;
        while (flag[1 - id]&&turn.load() == 1 - id);
        cout << "critical section entered for process " << id << timeString << endl;
        flag[id] = 0;
        cout << "critical section completed for process " << id << timeString << endl;
        this_thread::sleep_for(chrono::seconds(10));

    }while(true);
}

int main() {
    time_t currentTime = time(0); // Get current time


    // Using ctime
    char* timeString = std::ctime(&currentTime); // Convert to string
    cout << "Current time (using ctime): " << timeString;

    // Using localtime and strftime for custom formatting
    tm* localTime = localtime(&currentTime);
    char formattedTime[50];
    strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d %H:%M:%S", localTime);
    cout << "Current time (formatted): " << formattedTime << endl;

    thread p0(process, 0);
    thread p1(process, 1);
    //for(int i=0; i<3; i++)

    p0.join();
    p1.join();


    return 0;
}
