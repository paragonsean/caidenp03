#include <iostream>

using namespace std;

int main()
{
    ///declare the variables
    int i, sum =0;

    cout << "the numbers divisible by 7 between 1 and 100 :" << endl;
    cout << "----------------------------------------------" << endl;

    /// usea loop structure that runs for 100 iterations
    for(i=1;i<=100;i++)
    {
        if(i%7==0)/// check f the number is divisible by 7
        {
            cout << i <<endl; ///print it
        sum=sum+i; ///update the sum
        }
    }
///output the sum to the screen
    cout << "The sum of all the numbers divisible by 7 between 1 and 100 ="
        << sum << endl<<endl;
    return 0;
}
