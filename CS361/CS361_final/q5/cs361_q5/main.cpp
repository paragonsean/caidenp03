#include <random>
#include <ctime>
#include <algorithm>
#include <list>
#include <set>
#include <iostream>
#include <cstdlib>
#include <deque>

using namespace std;

//there is a large cut off randomly in the
//top portion of the carts being sorted,
//scrolling up slowly seems to solve this issue
//the carts being added may also cause this
//as I noticed using less carts helps fix this bug.

void print(deque<int> train)
{
    deque<int>::iterator it;
    for (it = train.begin(); it != train.end(); ++it)
    {
        cout << '\t' << *it;
    }
    cout << '\n';
}

int main()
{
    cout << "Welcome to the train station!" << endl;
    //make a deque of 40 ints and sort them one by one

    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> cartgen(1,100);
    deque<int> train;
    int temp = 0;

    //trains are generated
    for(int i=1; i<40; i++)
    {
        train.size() == i;
        cout << "iteration " << i << ": " << endl;
        temp = cartgen(gen);
        train.push_back(temp);
        print(train);

        cout << "\nTrains are sorting at siding... \n" << endl;

        set<int> s;
        copy(train.begin(),train.end(),inserter(s,s.begin()));

        for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
        {
            cout << *it << endl;
        }

    //trains need to be sorted
    /*if ( train.size()!=1)
    {
        for(int j = 0; j < train.size(); j++)
        {
            if (train[j] < train[j+1])
            {

            }
        }

        //trains are output
        print(train);
    }*/
    }
    cout << "\nTrains have been sorted! Proceed to drop off." << endl;
    return 0;
}
