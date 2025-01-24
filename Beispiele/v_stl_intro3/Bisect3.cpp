//	Bisect3.cpp
//	Recursive function
//			Example: Find the point of zero by bisection

//	Version 3: func(x) and epsilon as parameters

#include <cmath>
#include <functional>             // function; C++11
#include <iostream>
using namespace std;

/** \brief Calculates function @f$ f(x) = \sin(x) - \frac{x}{2} @f$
 *
 * \param[in]   x  position for funtion evaluation
 * \return function value
 *
 */
double f(const double x)		// declaration and
{
    return sin(x) - 0.5 * x ;    //   definition of function f(x)
}

/** \brief Calculates function @f$ f(x) = -(x-1.234567)*(x+0.987654) @f$
 *
 * \param[in]   x  position for funtion evaluation
 * \return function value
 *
 */
double g(const double x)		// declaration and
{
    return -(x - 1.234567) * (x + 0.987654) ;    //   definition of function g(x)
}

// declaration of Bisect3
/** \brief Returns one solution for the equation @f$ func(x) = 0 @f$ with
 *    @f$ x \in [a,b] @f$.
 *
 *   The solution is determined by bisection.
 *
 * \param[in]   func  function with one @p double input parameter that returns
 *              a  @p double value
 * \param[in]   a     interval begin
 * \param[in]   b     interval end
 * \param[in]   eps   accuracy @f$ \varepsilon @f$
 * \return solution @f$ x^\ast@f$ such that  @f$ |func(x^\ast)| < \varepsilon @f$
 * \warning {@f$ func(a) @f$ and @f$ func(b) @f$ musst have different signs}
 *
 */
double Bisect3(const std::function<double(double)>& func, 
               const double a, const double b, const double eps = 1e-6);

int main()
{
    //    ...
    const double EPS = 1e-6;		// accuracy constant

    cout << endl;
    cout << " Determine point of zero in [a,b] by bisection " << endl;

    double a, b;
    cout << "f(a) > 0,  a : ";
    cin >> a;
    cout << "f(b) < 0,  b : ";
    cin >> b;
    cout << endl;

    double x0 = Bisect3(f, a, b, EPS);		// call recursive function with f
    //double x0 = Bisect3(g,a,b,EPS);		// call recursive function with g

    cout << endl << " point of zero = " << x0 << endl;
    cout << endl;

    return 0;
}

//	---------------------------------------------------------------
//	Recursive  function Bisect3
//	---------------------------------------------------------------
//	definition of Bisect3

double Bisect3(const std::function<double(double)>& func, const double a, const double b,
               const double eps)
{
    double x0;
    double c = (a + b) / 2;             // center of interval
    double fc = func(c);                // function value in center

    if ( std::abs(fc) < eps ) {         // end of recursion
        x0 = c;
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect3(func, c, b, eps);  // search in the right intervall
    }
    else {		// i.e., fc < 0.0
        x0 = Bisect3(func, a, c, eps);  // search in the left intervall
    }

    return x0;                          // return the solution
}









