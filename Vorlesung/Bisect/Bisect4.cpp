//	Bisect4.cpp
//	Recursive function
//			Example: Find the point of zero by bisection

//	Version 4: func(x) and epsilon as parameters
//		   more robust wrt. intervall bounds


#include <cmath>
#include <functional>             // function; C++11
#include <iostream>
using namespace std;

double f(const double x)		// declaration and
{
    return sin(x) - 0.5 * x ;    //   definition of function f(x)
}

double g(const double x)		// declaration and
{
    return -(x - 1.234567) * (x + 0.987654) ;    //   definition of function g(x)
}

// declaration of Bisect3
double Bisect3(const std::function<double(double)>& func, 
               const double a, const double b, const double eps);

int main()
{
    const double EPS = 1e-6;		// accuracy constant

    cout << endl;
    cout << " Determine point of zero in [a,b] by bisection " << endl;

    double a, b;
    cout << "f(a) > 0,  a : ";
    cin >> a;
    cout << "f(b) < 0,  b : ";
    cin >> b;
    cout << endl;

    double fa = f(a),
           fb = f(b),
           x0;

    if (fa*fb<=0) {  // one root in [a,b]
        if ( abs(fa) < EPS || abs(fb) < EPS) {	// solution is a or/and b
            if ( abs(fa) < EPS ) {		// solution is a
                x0 = a;
                cout << endl << " point of zero = " << x0 << endl;
            }
            if ( abs(fb) < EPS ) {		// solution is b
                x0 = b;
                cout << endl << " point of zero = " << x0 << endl;
            }
        }
        else {  // root in open interval (a,b)
            if ( fa < 0.0 ) {		// f(a) < 0 && f(b) > 0
                cout << "I have to swap a and b" << endl;
                x0 = Bisect3(f, b, a, EPS);		// Bisect(3) is called
            }
            else {				// f(a) > 0 && f(b) < 0
                x0 = Bisect3(f, a, b, EPS);		// Bisect(3) is called
            }
            cout << endl << " point of zero = " << x0 << endl;
        }
    }
    else {  // no solution in [a,b]
        cout << endl << "There is potentially no solution in [" << a << "," << b << "]" << endl;
    }
    cout << endl;


    return 0;
}

//	---------------------------------------------------------------
//	Recursive  function Bisect3
//	---------------------------------------------------------------
//	definition of Bisect3

double Bisect3(const std::function<double(double)>& func, 
               const double a, const double b, const double eps)
{
    double x0, fc, c = (a + b) / 2;

    fc = func(c);
    if ( std::abs(fc) < eps ) {
        x0 = c;			// end of recursion
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect3(func, c, b, eps);	// search in right intervall
    }
    else {		// i.e., fc < 0.0
        x0 = Bisect3(func, a, c, eps);	// search in left intervall
    }

    return x0;			// return with solution
}









