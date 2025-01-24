//	Bisect.cppx.cpp

//	Recursive function
//			Example: Find the solution by bisection

//	Version 1: f(x) is dircetly implemented in Bisect()
//		   epsilon as parameter

#include <cmath>
#include <iostream>
using namespace std;


//	declaration of Bisect1
double Bisect1(const double a, const double b, const double eps);

int main()
{
    const double EPS = 1e-6;		// global constant

    double a, b;

    cout << endl;
    cout << "  Determine point of zero in [a,b] by bisection" << endl;

    cout << " f(a) > 0,  a : ";
    cin >> a;
    cout << " f(b) < 0,  b : ";
    cin >> b;

    double x0 = Bisect1(a, b, EPS);			// call recursive function

    cout << endl;
    cout << " point of zero = " << x0 << endl;
    cout << endl;

    return 0;
}

//	---------------------------------------------------------------
//	Recursive  function Bisect1
//	---------------------------------------------------------------
//	definition of Bisect1

double Bisect1(const double a, const double b, const double eps)
{
    double x0, fc, c = (a + b) / 2;

    fc = sin(c) - 0.5 * c;
    if ( std::abs(fc) < eps ) {         // end of recursion
        x0 = c;
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect1(c, b, eps);        // search in the right intervall
    }
    else {                              // i.e., fc < 0.0
        x0 = Bisect1(a, c, eps);        // search in the left intervall
    }

    return x0;                          // return the solution
}









