//	Reihe.cpp
//
//			Sum 1/k^2  = Pi^2 / 6  [Euler, 1736]
//			limited accuracy
//			Is s1 or s2 closer to right result ?

#include <cmath>                       // M_PI
#include <iostream>
#include <limits>                      // numeric_limits<float>::epsilon()
using namespace std;

int main()
{
 cout << endl << "Demo for precision of float" << endl;

//		Print the index where cancelation has to be expected for float
 cout << "The first sum will be rather precise until  n = "
      << ceil(sqrt(1.f/numeric_limits<float>::epsilon() )) << endl;

 cout << endl << " n =  ";             // Input highest index
 int n ;
 cin >> n;                             // Try  n = 65000;

//		Calculate in incrementing order
 float s1 = 0.0f;
 for (int i=1; i<=n; ++i)
   {
     s1 += 1.0f/i/i;
   }

 cout << endl << "s1 = " << s1 << endl << endl;

//		Calculate in decrementing order
 float s2 = 0.0f;
 for (int i=n; i>=1; --i)
   {
     s2 += 1.0f/i/i;
//     s2 += 1.0f/(i*i);	     // results in inf
//				since i*i may be longer than int supports
   }

 cout << endl << "s2 = " << s2 << endl << endl;

//				Compare both sums
 cout << endl << "Diff " << s2-s1 << endl << endl;

//				Compare sums with exact result
 cout << endl << "Pi*Pi/6 - s1 : " << M_PI*M_PI/6-static_cast<double>(s1) << endl;
 cout << endl << "Pi*Pi/6 - s2 : " << M_PI*M_PI/6-static_cast<double>(s2) << endl << endl;

 return 0;
}









