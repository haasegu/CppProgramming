//	Bisect6.cpp
//	Recursive function
//			Example: Find the point of zero by bisection

//	Version 6: All three Bisection functions with the same name
//

#include <cmath>
#include <functional>             // function; C++11
#include <iostream>
using namespace std;

constexpr double EPS = 1e-6;	// accuracy constant (global)

double f(const double x)		// declaration and
{
    return sin(x) - 0.5 * x ;    //   definition of function f(x)
}

double g(const double x)		// declaration and
{
    return -(x - 1.234567) * (x + 0.987654) ;    //   definition of function g(x)
}

double h(const double x)		// declaration and
{
    return 3.0 - exp(x) ;    //   definition of function h(x)
}

double t(const double x)		// declaration and
{
    return 1 - x * x ;    //   definition of function t(x)
}

//	The three versions of Bisect differ by its signature
//	declaration of Bisect
double Bisect(const double a, const double b, const double eps);
// declaration of Bisect2
double Bisect(const double a, const double b);
// declaration of Bisect3
double Bisect(const std::function<double(double)>& func, 
              const double a, const double b, const double eps);

int main()
{
    cout << endl;
    cout << " Determine point of zero in [a,b] by bisection " << endl;

    cout << "  f(x) :=  sin(x) - x/2" << endl;
    cout << "  g(x) := (1.234567-x)*(x+0.987654)" << endl;
    cout << "  h(x) :=  3.0 - exp(x)" << endl;
    cout << "  t(x) :=  1-x*x" << endl;

    std::function<double(double)> ff;   //function variable
    char   choice;
    cout << endl << "Which function do you prefer ? ";
    cin  >> choice;

    switch (choice) {
        case 'f':
            ff = f;
            break;
        case 'g':
            ff = g;
            break;
        case 't':
            ff = t;
            break;
        default:
            choice = 'h';
            cout <<  " no correct choice. h(x) is used." << endl;
            [[fallthrough]];
        case 'h':
            ff = h;
            break;
    }

    double a, b;
    cout << " " << choice << "(a) > 0,  a : ";
    cin >> a;
    cout << " " << choice << "(b) < 0,  b : ";
    cin >> b;
    cout << endl;

    double fa = ff(a),
           fb = ff(b),
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
                x0 = Bisect(ff, b, a, EPS);		// Bisect(3) is called
            }
            else {				// f(a) > 0 && f(b) < 0
                x0 = Bisect(ff, a, b, EPS);		// Bisect(3) is called
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
//	Recursive  function Bisect
//	---------------------------------------------------------------
//	definition of Bisect

double Bisect(const double a, const double b, const double eps)
{
    double x0, fc, c = (a + b) / 2;

    fc = sin(c) - 0.5 * c;
    if ( std::abs(fc) < eps ) {
        x0 = c;			// end of recursion
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect(c, b, eps);	// search in right intervall
    }
    else {			// i.e., fc < 0.0
        x0 = Bisect(a, c, eps);	// search in left intervall
    }

    return x0;			// return the solution
}

//	---------------------------------------------------------------
//	Recursive  function Bisect2
//	---------------------------------------------------------------

double Bisect(const double a, const double b)	// definition of Bisect2
{
    double x0, fc, c = (a + b) / 2;

    fc = f(c);
    if ( std::abs(fc) < EPS ) {
        x0 = c;			// end of recursion
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect(c, b);		// search in right intervall
    }
    else {			// i.e., fc < 0.0
        x0 = Bisect(a, c);		// search in left intervall
    }

    return x0;			// return with solution
}

//	---------------------------------------------------------------
//	Recursive  function Bisect3
//	---------------------------------------------------------------
//	definition of Bisect3

double Bisect(const std::function<double(double)>& func, 
              const double a, const double b, const double eps)
{
    double c = (a + b) / 2, fc = func(c), x0;

    if ( std::abs(fc) < eps ) {
        x0 = c;			// end of recursion
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect(func, c, b, eps);	// search in right intervall
    }
    else {		// i.e., fc < 0.0
        x0 = Bisect(func, a, c, eps);	// search in left intervall
    }

    return x0;			// return with solution
}









