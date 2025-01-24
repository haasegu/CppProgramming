//	Ex630.cpp

//	Sec. 6.3 of lecture
//	Pointers and arrays

#include <iostream>
using namespace std;

int main()
{
    const int N = 10;
    double    x[N], *px, *pp;

    px = &x[0];                         // address of x[0]
    pp = x;                             // address of C-array begin

    if ( px == pp) {
        cout << endl << " px and pp are identical" << endl;
    }

                                        // initialize x
    for (int i = 0; i < N; ++i ) {
        *(px + i) = (i + 1) * (i + 1);  // x[i] = ...
    }

    int i = 6;                          // check element 6
    cout << endl;                       // 4 different ways to access x[6]
    cout << x[i]    << endl;
    cout << *(x + i)  << endl;
    cout << px[i]   << endl;
    cout << *(px + i) << endl << endl;
                                       // for-loop with pointer as loop variable
    pp = x + N;                        // pointer to address after last element of x
    for ( double *pi = x; pi < pp; ++pi) {      // pointer pi as loop variable
        cout << "  " << *pi << endl;
    }
    return 0;
}









