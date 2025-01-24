//	Bisect2.cpp

//	Recursive function
//			Example: Find the solution by bisection

//	Version 2: f(x) is globally declared and defined
//		   epsilon as global constant

#include <cmath>
#include <iostream>
using namespace std;

const double EPS = 1e-6;		// global constant

double f(const double x)		// declaration and
{
    return  sin(x) - 0.5 * x ;    //   definition of function f(x)
}

double Bisect2(const double a, const double b);	// declaration of Bisect2

int main()
{
    double a, b;

    cout << endl;
    cout << "  Determine point of zero in [a,b] by bisection" << endl;

    cout << " f(a) > 0,  a : ";
    cin >> a;
    cout << " f(b) < 0,  b : ";
    cin >> b;

    double x0 = Bisect2(a, b);			// call recursive function

    cout << endl;
    cout << " point of zero = " << x0 << endl;
    cout << endl;

    return 0;
}

//	---------------------------------------------------------------
//	Recursive  function Bisect2
//	---------------------------------------------------------------

double Bisect2(const double a, const double b)	// definition of Bisect2
{
    double x0, fc, c = (a + b) / 2;

    fc = f(c);
    if ( std::abs(fc) < EPS ) {
        x0 = c;			// end of recursion
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect2(c, b);		// search in right intervall
    }
    else {			// i.e., fc < 0.0
        x0 = Bisect2(a, c);		// search in left intervall
    }

    return x0;			// return with solution
}









