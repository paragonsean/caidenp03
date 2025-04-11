///*********************************************************************
///File name PaintRoom
///

///Description: This program is given the length and width of a region to
///be painted, and the price of a gallon of paint as input. The square
///footage of the region is calculated, and the number of gallons of paint
///needed to cover the region, and the cost is determined. One gallon of
///paint will cover 200 square feet of the region.
///*********************************************************************

#include <iostream>
#include <iomanip>
using namespace std ;


/// function prototypes
int GetLength();
int GetWidth();
double GetGallonCost();
int ComputeArea( int, int );
int FindGallons( int );
double ComputeCost( double, int );
void PrintResults( int, int, double );
void programmer_info();


/// global constants
const int COVERAGE = 200;       /// 1 gallon of paint will cover 200 sq. ft.


int main()
  {
    /// local variable declarations for main
    int   length;      /// length of the region to be covered
    int   width;       /// width of the region to be covered
    int   area;        /// area of the region to be covered; long int
                       /// would be required to store large areas
    int   gallons;     /// number of gallons needed to cover the region
    double gallon_cost; /// price of a gallon of paint
    double paint_cost;  /// the cost of the paint needed

    programmer_info();

    /// input data
    length      = GetLength();

    width       = GetWidth();

    gallon_cost = GetGallonCost();


    /// process data
    area       = ComputeArea( length, width );

    gallons    = FindGallons( area );                /// find number of gallons to
                                                     /// cover area



    paint_cost = ComputeCost( gallon_cost, gallons );  /// compute cost of paint



    /// print results
    PrintResults( gallons, area, paint_cost );



    return(0);
  }

void programmer_info()
{


}

///**********************************************************************
///Function Name: GetLength
/// Prompts the user to input the length of a rectangular room
/// Returns the int value input by the user
///**********************************************************************
int GetLength()
  {
      int length;
      cout << "Enter the length of the room (in feet; an integer) : ";
      cin >> length;
    return length;
  }


///*********************************************************************
///Function Name: GetWidth
/// Prompts the user to input the width of a rectangular room
/// Returns the int value input by the user
///**********************************************************************
int GetWidth()
  {
      int width;
      cout << "Enter the width of the room (in feet; an integer) : ";
      cin >> width;
      return width;
  }


///**********************************************************************
///Function Name: GetGallonCost
///Prompts the user to input the cost of a gallon of paint
///Returns the value input by the user

///**********************************************************************
double GetGallonCost()
  {
      double cost;
      cout << "Enter the cost of a gallon of paint: ";
      cin >> cost;
   return cost;
  }


///**********************************************************************
///Function Name: ComputeArea
/// Formal parameters are the length and width of a rectangle
/// Calculates and returns the rectangle area

///**********************************************************************
int ComputeArea( int length, int width )
{

    return length*width;
}


///**********************************************************************
///Function Name: FindGallons

///Calculates and returns he number of gallons of paint needed
/// Formal parameter is the area to be painted
/// Global constant COVERAGE tells the number of square feet
/// covered by one gallon
/// Calculates and returns the number of gallons
/// Paint must be purchased by the gallon so if (Area / COVERAGE)
/// yields a remainder, round up to the highest integer

///**********************************************************************
int FindGallons( int paint_area )
{
    if (paint_area % COVERAGE == 0) {
        return paint_area/COVERAGE;
    }
    else{
        return paint_area/COVERAGE + 1;
    }
}


///**********************************************************************
///Function Name: ComputeCost
///Computes how much it would cost to buy all the paint necessary
///to cover the region.
/// Formal parameters are the cost per gallon and the number of gallons
/// of paint needed


///**********************************************************************
double ComputeCost( double gallon_price, int num_gallons )
{
    cout << fixed << setprecision(2);
    return gallon_price * num_gallons;
}


///**********************************************************************
///Function Name: PrintResults
/// A void function
/// Formal parameters are the number of gallons, the area to be painted,
/// and the total cost of the paint required.
/// Prints a message to the screen stating the number of gallons,
/// the area, and the post of the paint.

///**********************************************************************
void PrintResults( int gallons, int area, double paint_cost )
  {
    cout << "\n\nThe area of your room is " << area << " square feet\n";
    cout << "One gallon of paint covers 200 square feet\n";
    cout << "You will need "<< gallons << " gallons of paint.\n";
    cout << "The total cost for paint is $"<< paint_cost << ".\n\n\n";
  }


/// end of function declarations
