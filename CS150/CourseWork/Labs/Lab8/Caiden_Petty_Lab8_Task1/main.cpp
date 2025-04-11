#include <iostream>
#include <iomanip>

using namespace std;

void initialize(double list[], int size);
void print(double list[], int size);

int main()
{
    ///array of 50 components
    double alpha[50];

    ///call the function to initialize
    initialize(alpha, 50);

    ///call the function to print the output
    print(alpha, 50);
    return 0;
}

void initialize(double list[], int size)
{
    int count; ///loop control variable

    ///the first 25 components are equal to the square of the index
    for(count = 0; count<25; count++)
        list[count] = count * count;

    /// the last 25 components are equal to three times the index
    for (count = 25; count < size; count++)
        list[count] = 3 * count;
}

///print the array
void print(double list[], int size)
{
    int count;

    for(count=0; count < size; count++)
    {
        cout << setw(4) << list[count] << " ";
        if ((count + 1) % 10 == 0)
            cout << endl;
    }
    cout << endl;
}
