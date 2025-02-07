//	orig.: Bisect5.cpp

//	Recursive function
//			Example: Find the point of zero by bisection

//	Version 5: func(x) and epsilon as parameters
//		   more robust wrt. intervall bounds
//		   choose from a collection of functions
//

#include "bisect.h"
#include <cmath>
#include <functional>             // function; C++11
#include <iostream>
using namespace std;

/** \brief Calculates function @f$ f(x) = \sin(x) - \frac{x}{2} @f$
 *
 * \param[in]   x  position for function evaluation
 * \return function value
 *
 */
double f(const double x);		// declaration and
double f(const double x)		// definition of function f(x)
{
    return sin(x) - 0.5*x ;
}

/** \brief Calculates function @f$ f(x) = -(x-1.234567)*(x+0.987654) @f$
 *
 * \param[in]   x  position for function evaluation
 * \return function value
 *
 */
double g(const double x);    	// declaration and
double g(const double x)		// definition of function g(x)
{
    return -(x-1.234567)*(x+0.987654) ;
}

/** \brief Calculates function @f$ f(x) = 3-\textrm{e}^x @f$
 *
 * \param[in]   x  position for function evaluation
 * \return function value
 *
 */
double h(const double x);		// declaration and
double h(const double x)		// definition of function h(x)
{
    return 3.0 - exp(x) ;
}

/** \brief Calculates function @f$ f(x) = 1-x^2 @f$
 *
 * \param[in]   x  position for function evaluation
 * \return function value
 *
 */
double t(const double x);		// declaration and
double t(const double x)		// definition of function t(x)
{
    return 1-x*x ;
}


int main()
{
    constexpr double EPS = 1e-6;	// accuracy constant (global)

    cout << endl;
    cout << " Determine root in [a,b] by bisection " << endl;

    cout << "  f(x) :=  sin(x) - x/2" << endl;
    cout << "  g(x) := (1.234567-x)*(x+0.987654)" << endl;
    cout << "  h(x) :=  3.0 - exp(x)" << endl;
    cout << "  t(x) :=  1-x*x" << endl;
    cout << "  l(x) :=  2-x*x    (lambda)" << endl;
    cout << "  k(x) :=  x^2+x-6  (lambda)" << endl;

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
            //[[fallthrough]];
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

    if ( std::abs(fa) < EPS || std::abs(fb) < EPS) {	// solution is a or/and b
        if ( std::abs(fa) < EPS ) {		// solution is a
            x0 = a;
            cout << endl << " root = " << x0 << endl;
        }
        if ( std::abs(fb) < EPS ) {		// solution is b
            x0 = b;
            cout << endl << " root = " << x0 << endl;
        }
    }
    else if ( fa * fb > 0.0) {		// no solution in [a,b]
        cout << endl;
        cout << "There is potentially no solution for " << choice
             << "(x) = 0  in [" << a << "," << b << "]" << endl;
    }
    else {
        if ( fa < 0.0 ) {		// f(a) < 0 && f(b) > 0
            cout << "I have to swap a and b" << endl;
            x0 = Bisect(ff, b, a, EPS);		// Bisect(3) is called
        }
        else {				// f(a) > 0 && f(b) < 0
            x0 = Bisect(ff, a, b, EPS);		// Bisect(3) is called
        }
        cout << endl << " root = " << x0 << endl;
    }
    cout << endl;

    return 0;
}


