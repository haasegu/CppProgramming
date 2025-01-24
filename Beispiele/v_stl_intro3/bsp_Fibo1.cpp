//		Sec. 5.1 in Lecture
//		Demo of Fibonacci numbers
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp_Fibo1.cpp
#include <cmath>                     // sqrt()
#include <iostream>
#include <vector>                    // vector<T>
using namespace std;

int main()
{
    const int N = 40;                // What happens with N=50 ?? Why ??
    vector<int> x(N+1);              // !!   N + 1   !!

    x[0] = 0;                        // Calculate Fibonacci numbers
    x[1] = 1;
    for ( int i = 2; i <= N; ++i ) {
        x.at(i) = x[i - 1] + x[i - 2];
    }

//		Output x
    cout << endl;
    for ( size_t i=0; i<x.size(); ++i ) {
        cout << i << " : " << x[i] << endl;
    }
    cout << endl;

///		Check last Fibonacci number (Moivre-Binet)
    const double fib = (   pow(0.5 * (1.0 + sqrt(5.0)), N)
                         - pow(0.5 * (1.0 - sqrt(5.0)), N) ) / sqrt(5.0);
    cout << "Check :" << fib - x[N] << endl;

    cout << endl;
    cout << "fib(" << N << ") = " << fib << endl;
    cout << endl;
    return 0;
}









