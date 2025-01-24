//	Ex710.cpp

//	Sec. 7.1 of lecture
//	Demonstration of function declaration and definition

#include <iostream>
using namespace std;

double sgn(double x);       // declare function sgn // prototype

double sgn(double x);       // 2nd identical declaration possible

// double sgn(double& x);   // not allowed in this context !!
// int sgn(double x);       // not allowed in this context  !!

double sgn(double* x);	    // declaration of another, not used, sgn function
         //  |  different type of argument
//----------------------------------------------------------------------
int main()
{
    double a, b;

    cout << endl << " Input Argument      : ";
    cin  >> a;

    b  = sgn(a);                        // function call

    cout << "  sgn(" << a << ") = " << b << endl;
    return 0;
}

//----------------------------------------------------------------------

double sgn(double x)                    // definition of function sgn
{
    double y;                           // local variable in function

    y = (x > 0 ? 1. : 0.) + (x < 0 ? -1. : 0.);

    return y;                           // return value of function sgn
}









