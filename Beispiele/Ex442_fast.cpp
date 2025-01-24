//	Ex442_fast.cpp  (veraltete Version?= [aktuell:  Ex442fast.cpp  ??]

//	Sec. 4.4 of lecture
//	FOR-loop
//			Example: double sum and (very, very) fast version
//			try  n = 5000
//			The fast version requires at least n=100000 to measure a time != 0
//		n = 100000:	old:  381    sec
//				new:    0.01 sec

#include <ctime>          // contains clock()
#include <iostream>
using namespace std;

int main()
{
 int    n;			        // last index
 double sum_i,sum_k;		// outer and inner sum
 double time1=0.0, time2=0.0, tstart;  // time measurment

 cout << endl;
 cout << "  Input n : ";
 cin  >> n;				// read n

//	conventional version
 tstart = clock();
 sum_k = 0.0;				// initialize outer sum

 for ( int k = 1; k <= n; ++k)
  {
    sum_i = 0.0;			// initialize inner sum
    for ( int i = 1; i <= k; ++i)		// last index depends on k !!
     {
        sum_i = sum_i + 1.0/i/i;
     }
 //   cout << "  Sum (" << k << ") = " << sum_i << endl;
    sum_k = sum_k + sum_i;		// sum_k grows unbounded
//    sum_k = sum_k + sum_i/n;		// sum_k is bounded
  }
 time1 += clock()-tstart;

 cout << endl;
 cout << "  a) Double-Sum (" << n << ") = " << sum_k;
 cout << "  in  " << time1/CLOCKS_PER_SEC << " sec." <<  endl;
 cout << endl;

//
//	fast version
 tstart = clock();
 double t_k   = 0.0;
 sum_k = 0.0;

 for ( int k = 1; k <= n; ++k)
  {
    t_k = t_k + 1.0/k/k;
 //   cout << "  Sum (" << k << ") = " << sum_i << endl;
    sum_k = sum_k + t_k;		// sum_k grows unbounded
//    sum_k = sum_k + t_k/n;		// sum_k is bounded
  }
time2 += clock()-tstart;

 cout << endl;
 cout << "  b) Double-Sum (" << n << ") = " << sum_k;
 cout << "  in  " << time2/CLOCKS_PER_SEC << " sec." << endl;
 cout << endl;
 return 0;
}









