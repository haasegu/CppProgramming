//	Ex721.cpp

//	Sec. 7.2 of lecture
//	Demonstration of function parameters

#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------------
//		declare function sgn( <double-var> )
double sgn(double x);                   // by value
//double sgn(double& x);                // by reference
//double sgn(const double& x);          // by reference, const. data

//		declare function sgn( <double-var>* )
double sgn(double *x);                  // by address
//double sgn(const double* x);          // by address, const. data
//double sgn(const double* const x);    // by address, const. pointer, const pointer
//-----------------------------------------------------------------------------------

int main()
{
    double a, *pa = &a;

    cout << endl << " Input Argument      : ";
    cin  >> a;

    double b  = sgn(a);		            // call by value or by reference

    cout << " 1:  sgn(" << a << ") = " << b << endl;

    b = sgn(&a);		                // call by address

    cout << " 2:  sgn(" << a << ") = " << b << endl;

    if (pa == &a) {
        cout << endl << "Adress of x remains the same." << endl;
    }
    return 0;
}

//------------------------------------------

//		define  functions
double sgn(double x)                    // by value
//double sgn(double& x)                 // by reference
//double sgn(const double& x)           // const. reference
{
    double y;

    if ( x > 0.0 ) {
        y = 1.0 ;
    }
    else {
        if ( x == 0.0 ) {
            y = 0.0 ;
        }
        else {
            y = -1.0 ;
        }
    }
    x++;  // Try with different parameter types, doesn't work with const. reference
    return y;
}

//------------------------------------------

double sgn(double *x)                   // by address
//double sgn(const double* x)           // by address, const. data
//double sgn(const double* const x)     // by address, const. pointer, const. data
{
    double y;

    if ( *x > 0.0 ) {
        y = 1.0 ;
    }
    else {
        if ( *x == 0.0 ) {
            y = 0.0 ;
        }
        else {
            y = -1.0 ;
        }
    }
    (*x)++; 	// increments data   : doesn't work with 'const double*' 
    x++; 		// increments pointer: doesn't work with 'double* const'
    return y;
}










