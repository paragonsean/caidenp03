#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("Jacobi.txt");
    file.open("Jacobi.txt");
    double Size;
    file >> Size;
     // from class work
     double**A;
     double**C;
     double *Dinv;
     double *b;
     double *bpred; ///b vector predicted
     double *xold;
     double *xnew;
     double * temp;
     double Twonorm = 100;
     int count=1;
     ///C = L + U (no diagonals)
     C = new double*[2];
     A = new double*[2];
     Dinv = new double[2];
     b = new double[2];
     xold = new double[2];
     xnew = new double[2];
     temp = new double[2];

     for(int i=0; i<2; i++){C[i]=new double[2];
                            A[i]=new double[2];}
     C[0][0]=0.0;
     C[0][1]=2.0;
     C[1][0]=-1.0;
     C[1][1]=0.0;

     A[0][0]=3.0;
     A[0][1]=2.0;
     A[1][0]=-1.0;
     A[1][1]=4.0;

      Dinv[0]=.3333;
      Dinv[1]=.25;

      b[0]=5;
      b[1]=-25;

      xold[0]=0.0;
      xold[1]=0.0;

      temp[0]=0;
      temp[1]=0;

while(Twonorm>.001)
 {
    ///temp = C*xold
    temp[0] = C[0][1]*xold[1];
    temp[1] = C[1][0]*xold[0];
    ///temp = b - temp;
    temp[0] = b[0]-temp[0];
    temp[1] = b[1]-temp[1];
    ///xnew = Dinv * temp
    xnew[0] = Dinv[0]*temp[0];
    xnew[1] = Dinv[1]*temp[1];

    cout<<"xnew[0] = "<<xnew[0]<<", xnew[1] = "<<xnew[1]<<endl;
    xold[0]=xnew[0];
    xold[1]=xnew[1];
    ///compute the 2norm of the error
     bpred[0] = (A[0][0]*xnew[0])+(A[0][1]*xnew[1]);
     bpred[1] = (A[1][0]*xnew[0])+(A[1][1]*xnew[1]);

     temp[0] = abs(b[0]-bpred[0]);
     temp[1] = abs(b[1]-bpred[1]);
     Twonorm = sqrt(pow(temp[0],2)+pow(temp[1],2))/2;
     cout<<"2norm of the error = "<<Twonorm<<endl;
     cout<<"iteration #  k = "<<count<<endl;
     count++;}

    file.close();
    return 0;
}
