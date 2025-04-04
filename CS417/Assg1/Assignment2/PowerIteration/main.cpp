#include <iostream>
 #include <iomanip>
 #include <cmath>
 #include <random>
 #include <ctime>
 #include <cstdlib>
 #include <fstream>

 using namespace std;

  int main()
  {  double**A;
     double *b;
     double * abk;
     double * btemp;
     double mu;
     double mu1;
     double mu2;
     double norm;

     A = new double*[2];
     b = new double[2];
     abk = new double[2];
     btemp = new double[2];


     for(int i=0; i<2; i++){ A[i]=new double[2];}


     A[0][0]=5.0;
     A[0][1]=1.0;
     A[1][0]=-1.0;
     A[1][1]=3.0;

      b[0]=1;
      b[1]=1;
      btemp[0]=b[0];
      btemp[1]=b[1];

      cout<<"initial btemp = ["<<btemp[0]<<", "<<btemp[1]<<"]"<<endl;
      for(int i=0; i<60; i++)
      {
          //A*bk
          abk[0]=(A[0][0]*btemp[0])+(A[0][1]*btemp[1]);
          abk[1]=(A[1][0]*btemp[0])+(A[1][1]*btemp[1]);
          ///for(i=0;i<n; i++)
          ///{ for(int j=0; j<n; j++)
          ///   {sum = sum + A[i][j]*btemp[j];}
          ///abk[i]=sum;
          ///sum =0.0;
          ///}
          cout<<"Abk = ["<<abk[0]<<", "<<abk[1]<<"]"<<endl; ///correct
          ///b* times Abk
          mu1 = (btemp[0]*abk[0])+(btemp[1]*abk[1]);
          mu2 = (btemp[0]*btemp[0])+(btemp[1]*btemp[1]);
          cout<<"mu1 = "<<mu1<<", mu2 = "<<mu2<<endl;
          ///mu = mu1/mu2
          mu = mu1/mu2;
          cout<<"mu = "<<mu<<endl;
          ///compute new b

         btemp[0]  = (A[0][0]*abk[0])+(A[0][1]*abk[1]);
         btemp[1]  = (A[1][0]*abk[0])+(A[1][1]*abk[1]);
         norm=sqrt(pow(abk[0],2) + pow(abk[1],2));
         btemp[0]=btemp[0]/norm;
         btemp[1]=btemp[1]/norm;
         cout<<"btemp = ["<<btemp[0]<<", "<<btemp[1]<<"]"<<endl<<endl;


 }
 return 0;
  }
