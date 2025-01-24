//	Fibo1.cpp
//		Sec. 5.1 in Lecture
//		Demo of Fibonacci numbers
#include <cmath>                     // sqrt()
#include <iostream>
using namespace std;

int main()
{
    const int N = 40;                // What happens with N=50 ?? Why ??
    int x[N + 1];                    // !!   N + 1   !!

    x[0] = 0;                        // Calculate Fibonacci numbers
    x[1] = 1;
    for ( int i = 2; i <= N; ++i ) {
        x[i] = x[i-1] + x[i-2];
    }

//		Output x
    cout << endl;
    for ( int i = 0; i <= N; ++i ) {
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









