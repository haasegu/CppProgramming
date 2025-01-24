//	Ex1121_mod.cpp	 11.2.1

//	Calculates a polynom at point x in two different ways
//		and compare the execution time
//		g++ -O3 -std=c++11 -Wall -Wextra -pedantic Ex1121_mod.cpp
//      vs. 
//		g++ -O3 -std=c++11 -ffast-math  -Wall -Wextra -pedantic Ex1121_mod.cpp
//      Here, -ffast-math accelerates the std::pow()

#include "timing.h"          // contains my timing routines
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int NRUN = 10000000;	// number of test runs
    vector<double> a{1.1,-1.2,1.3,-1.4,1.5,-1.6,1.7,-1.8,1.9,1.001,
                     2.1,-2.2,2.3,-2.4,2.5,-2.6,2.7,-2.8,2.9,2.001,-0.5};		
    int N;		// highest degree in polynom
    cout << "Eingabe N (<= " << a.size() <<  ") = "; 
    cin >> N;
    N = min( N, static_cast<int>(a.size()) );
    
    cout << "Calculation of polynom with degree " << N-1 << endl;
    double x;
    cout << "  Read X" << endl;
    cout << "  x = ";
    cin >> x;
    cout << endl;

//	version a (slow)
    tic();
//  some code
    double s1_out=0.0;
    for (int j = 1; j <= NRUN; ++j) {
        double s1 = 0.0;
        for ( int k = 0; k <= N; ++k) {
            const double xk  = std::pow(x, k);
            s1 += xk * a[k];
        }
        s1_out += s1;
    }
    double tdiff1 = toc();

//	version b (fast)

    tic();
    double s2_out=0.0;
    for (int j = 1; j <= NRUN; ++j) {
        double s2 = a[0];
        double xk = 1.0;
        for ( int k = 1; k <= N; ++k) {
            xk *= x;
            s2 += xk * a[k];
        }
        s2_out += s2;
    }
    double tdiff2 = toc();

    cout << "slow (   pow) = " << s1_out/NRUN << " (" << tdiff1 << " sec.)";
    cout << endl;
    cout << "fast (no pow) = " << s2_out/NRUN << " (" << tdiff2 << " sec.)" << endl;

    cout << endl;
    return 0;
}
