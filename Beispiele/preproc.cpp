//	preproc.cpp (<-- Euler.cpp)

//	Demonstration of preprocessing directives

//	Pre: include file
#include <cmath>
#include <iostream>
using namespace std;

//-------------------------------------------------------------
//	Pre: Alternative - Check whether M_PI is not defined
#ifndef M_PI
//	Pre: Define M_PI in that case
#define M_PI 3.14159
//	Pre: else-branch of alternative may follow
#else
//
//	Pre: End of alternative
#endif
//-------------------------------------------------------------
//	Pre: Define your own variables
#define MY_DEBUG
//	Pre: Undefine your own variable
//#undef MY_DEBUG
//	Pre: Define variable
#define SEE_PI 5
//-------------------------------------------------------------
//	Pre: Define your own macro
#define MAX(x,y)  (x > y ? x : y)
//-------------------------------------------------------------
// See item 2 in  http://codeforces.com/blog/entry/15643
//! \brief Macro that prints a variable name together with its content
//!
//! \param[in]     x  a variable
#define what_is(x) cerr << #x << " is " << (x) << endl;
//-------------------------------------------------------------


int main()
{
    const long long int N(1000), M(100000);

    for (long long int i = 1; i <= N; ++i) {
        long long int j  = i * M;
        float         e1 = pow(1.0 + 1.0 / j, double(j));
//	Pre: Use your own variable
#ifdef MY_DEBUG
        cout << "e - e1  = " << exp(1.0) - e1 << endl;
#endif
    }

    cout << endl << "e = " << exp(1.0) << endl;

//		M_E is the predefined Euler number  (/usr/include/cmath)
    cout << endl << "e = " << M_E - exp(1.0) << endl;

//		Check the value of preprocessor variable
#if (SEE_PI<5)
//		M_PI is the predefined PI number  (/usr/include/cmath)
    cout << M_PI << " " << sizeof(M_PI) << endl;
#endif

//	Use your own macro
    cout << "Max: " << MAX(1.45, 5.6) << endl;

    what_is(N);

    return 0;
}








