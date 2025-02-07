//	Sec. 6.3 of lecture
//	Iteratoren für C++-array
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp631a.cpp

#include <array>                          // array<T,N> 
#include <iostream>
using namespace std;

int main()
{
    array<double, 10>  x;                 // static array of length 10 

    double *px = &x[0];                   // address of x[0]
    double *pp = x.data();                // address of C++-array begin

    if ( px == pp) {
        cout << endl << " px and pp are identical" << endl;
    }

                                          // initialize x
    for (size_t i = 0; i < x.size(); ++i ) {
        x[i] = (i + 1) * (i + 1);         // x[i] = ...
    }
                                          // for-loop with pointer as loop variable
    array<double, x.size()>::iterator pi; // declare iterator as loop variable
    for ( pi = x.begin(); pi != x.end(); ++pi) {
        cout << "  " << *pi << endl;
    }
    
    return 0;
}









