#include <iostream>

using namespace std;

int main()

{
    int i;
    int value = 3;

    while (i < 5){///switched from for to while i is less than 5
        value = value * (i + 1) + i;/// kept the same value statement so the loop progresses
        i++;///moved the i increment to the end of the while loop so it executes last
    }   ///close loop
cout << "value = " << value << endl;///read the output to the user at the end of the program

return 0;
}
