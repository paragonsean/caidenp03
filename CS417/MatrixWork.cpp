// Practice matrix

#include <iostream>
#include <string>
#include <cmath>
#include <random>

using namespace std;

int main()
{
  std::string name;
  
  
 //normal random distribution
  std::default_random_engine generator(time(NULL));
  std::normal_distribution<double> ndist(0.0, 25);
  //std::uniform_int_distribution<int> distribution(1,5);
  
  double **A;
  double *b;
  double r;
  int n;
  double *x;
  
  std::cout << "size of matrix?";
  std::cin >> n;

  //n = distribution(generator);
  x = new double [n];
  b = new double [n];
  A = new double * [n];
  for(int i=0; i<n; i++)
  {
      A[i] = new double[n];
  }
  
 for(int i=0; i<n; i++)
 {
     x[i] = i+1;
 }
 
 for(int row=0; row<n; row++)
 {
     for(int col=0; col<n; col++)
     {
         r = ndist(generator);
         A[row][col] = r;
         std::cout << "A[" << r << "][" << col << "] = " << r << std::endl;
     }
 }
 
 
 std::cout << "solution vector x:" << std::endl;
  for(int i=0; i<n; i++)
 {
     std::cout << x[i] << std::endl;
 }
 
  delete b;
  delete x;
   for(int i=0; i<n; i++)
 {
     delete A[i];
 }
 
  return 0;
}