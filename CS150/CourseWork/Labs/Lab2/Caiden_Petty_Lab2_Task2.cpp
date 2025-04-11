#include <iostream>

using namespace std;

int main()
{
    double testScore1, testScore2, testScore3, testScore4, averageScore;

    cout << "Enter the score for test 1" << endl;

    cin >>testScore1;

        cout << "Enter the score for test 2" << endl;

    cin >>testScore2;

        cout << "Enter the score for test 3" << endl;

    cin >>testScore3;

        cout << "Enter the score for test 4" << endl;

    cin >>testScore4;

    averageScore = (testScore1 + testScore2 + testScore3 + testScore4)/4;

    cout << "Your average is "<<averageScore <<endl;
}
