//	Ex442.cpp

//	Sec. 4.4 of lecture
//	FOR-loop
//			Example: double sum

#include <iostream>
using namespace std;

int main()
{
 int    n;                  // last index

 cout << endl;
 cout << "  Input n : ";
 cin  >> n;

 double sum_k = 0.0;        // declare + initialize outer sum

 for ( int k = 1; k <= n; ++k)
  {
    double sum_i = 0.0;                 // declare + initialize inner sum
    for ( int i = 1; i <= k; ++i)		// last index depends on k !!
     {
        sum_i = sum_i + 1.0/i/i;
     }
    cout << "  Sum (" << k << ") = " << sum_i << endl;
    sum_k = sum_k + sum_i;              // sum_k grows unbounded
//    sum_k = sum_k + sum_i/n;		    // sum_k is bounded
  }

 cout << endl;
 cout << "  Double-Sum (" << n << ") = " << sum_k << endl;
 cout << endl;
 return 0;
}









