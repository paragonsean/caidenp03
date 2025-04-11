#include <iostream>
#include <iomanip>

using namespace std;

///constant for the array size
const int DAYS = 7;

void selectionSort(double list[], int Days_Week[], int length);

int main()
{
    ///Array variable to hold the sales for the day
    double sales[DAYS];
    int week[7]={1,2,3,4,5,6,7};

    ///variable to store the running total
    double total=0;

    ///get the sales for each day of the week
    for(int day =0; day<DAYS; day++)
    {
        ///get the sales for the current day
        cout << "Enter the sales for the day " << day + 1 << ": $";
        cin >> sales[day];

        ///validate the input
        while (sales[day] < 0)
        {
           cout << "\nSales must be zero or greater.\n";
           cout << "Enter the sales for the day " << day + 1 << ": $";
           cin >> sales[day];
        }

        ///keep a running total of the sales
        total += sales[day];
    }

    ///call the function to sort the array
    selectionSort(sales, week, DAYS);

    ///display the result
    cout << "\nTotal Sales: $" << total << endl;

    cout << endl;
    cout << setw(10) << left << "Day" << setw(10) << "Sales"<< endl;

    for(int i = 0; i < DAYS; i++)
    {
        cout << setw (10)<< week[i] << setw (10) << sales[i] << endl;
    }
    return 0;
}

void selectionSort(double list[], int Days_Week[], int length)
{
    int index;
    int smallestIndex;
    int location;
    int temp, temp_day;

    for (index=0; index<length-1; index++)
    {
        smallestIndex=index;

        ///find the index of the smallest element in sales array

        for(location=index+1; location < length; location++)
            if (list[location] < list[smallestIndex])
            smallestIndex = location;

        ///swap the smallest element in sales array with the first element

        temp = list[smallestIndex];
        list[smallestIndex] = list[index];
        list[index] = temp;

        ///swap the days in days array the same way you swap the sales

        temp_day = Days_Week[smallestIndex];
        Days_Week[smallestIndex] = Days_Week[index];
        Days_Week[index] = temp_day;
    }
}
