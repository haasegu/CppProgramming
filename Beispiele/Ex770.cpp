//	Ex770.cpp

//	Sec. 7.7 of lecture
//	Recursive function

#include <iostream>
using namespace std;

// declare function power
double power(const double x, const int k);


int main()
{
    double a, b;
    int    i;

    cout << endl << " x^k : x = ";
    cin  >> a;
    cout <<         "     : k = ";
    cin  >> i;

    b  = power(a, i);		// function call

    cout << endl;
    cout << "  " << a << "^" << i << "  = " << b << endl;
    cout << endl;
}

//---------------------------------------------

// definition of function power
double power(const double x, const int k)
{
    double y;

    if ( k == 0) {
        y = 1.0;                        // stops recursion
    }
    else {
        y = x * power(x, k - 1);        // recursive call
    }

    return y;                           // return value of function power
}









