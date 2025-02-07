//	Bisect6.cpp
//	Recursive function
//			Example: Find the point of zero by bisection

//	Version 6: All three Bisection functions with the same name
//	Version 7: now with array of functions
//

#include <array>
#include <cmath>
#include <functional>             // function; C++11
#include <iostream>
#include <map>
using namespace std;
    
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
double Bisect(double a, double b, double eps);
// declaration of Bisect2
double Bisect(double a, double b);
// declaration of Bisect3
double Bisect(const std::function<double(double)> &func,
              double a, double b, double eps);

int main()
{
    constexpr double EPS = 1e-6;	// accuracy constant
    array<string, 4> ssf{"f(x) :=  sin(x) - x/2",
                         "g(x) := (1.234567-x)*(x+0.987654)",
                         "h(x) :=  3.0 - exp(x)",
                         "t(x) :=  1-x*x" };

// now with array of functions
    array< std::function<double(double)>, 4> vff{f, g, h, t};

    // map  char to index
    map<char, int> mmf{{'f', 0}, {'g', 1}, {'h', 2}, {'t', 3}};

    // map  char to function
    map<char, std::function<double(double)> > mapff{{'f', f}, {'g', g}, {'h', h}, {'t', t}};


    cout << endl;
    cout << " Determine root in [a,b] by bisection " << endl;

    for (size_t k = 0; k < ssf.size(); ++k) {
        //cout << "[" << k << "]   ";
        cout << ssf[k] << endl;
    }

    char   choice;
    cout << endl << "Which function do you prefer ? ";
    cin  >> choice;

    std::function<double(double)> ff;
    try {
                   // http://www.cplusplus.com/reference/map/map/at/
        ff = mapff.at(choice);  //function variable
    }
    catch (out_of_range& ) {
        choice = 'h';
        ff = mapff.at(choice);
        cout <<  " incorrect choice. h(x) is used." << endl;
    }


    double a;
    double b;
    cout << " " << choice << "(a) > 0,  a : ";
    cin >> a;
    cout << " " << choice << "(b) < 0,  b : ";
    cin >> b;
    cout << endl;

    double const fa = ff(a);
    double const fb = ff(b);
    double       x0;

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
//	Recursive  function Bisect3
//	---------------------------------------------------------------
//	definition of Bisect3

double Bisect(const std::function<double(double)> &func,
              const double a, const double b, const double eps)
{
    double const c = (a + b) / 2;
    double const fc = func(c);
    double       x0;

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









