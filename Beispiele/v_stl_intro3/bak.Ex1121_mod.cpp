//	Ex1121_mod.cpp	 11.2.1

//	Calculates a polynom at point x in two different ways
//		and compare the execution time
//		g++ -O3 -std=c++11 -Wall -Wextra -pedantic Ex1121_mod.cpp
//      vs. 
//		g++ -O3 -std=c++11 -ffast-math  -Wall -Wextra -pedantic Ex1121_mod.cpp
//      Here, -ffast-math accelerates dramatically

#include <chrono>           // contains timing routines
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<double> dsec;

int main()
{
    const int NRUN = 10000000;	// number of test runs
    const int N = 20;		// highest degree in polynom
    double a[N + 1];		// (N+1) coefficients
    double x;

    cout << endl;
    cout << "Polynom calculation" << endl;
    cout << "  Read coeff" << endl;

    for ( int k = 0; k <= N; ++k ) {
        cin >> a[k];
    }

    cout << endl;
    cout << "  Read X" << endl;
    cout << "  x = ";
    cin >> x;
    cout << endl;

//	version a (slow)
    auto tstart = Time::now();
//     ...
    double s1;
    for (int j = 1; j <= NRUN; ++j) {
        s1 = 0.0;
        for ( int k = 0; k <= N; ++k) {
            const double xk  = pow(x, k);
            s1 += xk * a[k];
        }
    }
    dsec time1 = Time::now() - tstart;

//	version b (fast)

    tstart = Time::now();
    double s2;
    for (int j = 1; j <= NRUN; ++j) {
        s2 = a[0];
        double xk = 1.0;
        for ( int k = 1; k <= N; ++k) {
            xk *= x;
            s2 += xk * a[k];
        }
    }
    dsec time2 = Time::now() - tstart;

    cout << "  slow (   pow) = " << s1 << "   (" << time1.count() << " sec.)\n";
    cout << "  fast (no pow) = " << s2 << "   (" << time2.count() << " sec.)" << endl;

    cout << endl;
    return 0;
}









