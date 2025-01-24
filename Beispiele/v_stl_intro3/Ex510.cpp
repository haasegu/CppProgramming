//	Ex510.cpp
//	Sec. 5.1 of lecture
//	Array

#include <iostream>
using namespace std;

int main()
{
 const int N=5;             // constant dimension for array
 double x[N]= {9,7,6,5,7};

 x[0] = 1.0;                // index starts with 0
 x[1] = -2;
 x[2] = -x[1];
 x[3] = x[1]+x[2];
 x[4] = x[1]*x[2];

 cout << endl << " Array x : " << endl;;
 for (int i = 0; i < N; ++i)
  {
    cout << "x[" << i << "] = " << x[i] << endl;
  }

// Access to  x[5]  is not permitted: out of range !!
 cout << endl << "Not permitted: x[5] = " << x[5] << endl;

//  Demonstration
 const int NN=5, MM=1;
 float y[NN-MM+1];

 int M=5;			// not correct !!
 float z[M];	    // not correct regarding the standard!!  M has to be constant


 return 0;
}









