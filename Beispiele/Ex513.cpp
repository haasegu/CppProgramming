//	Ex513.cpp

//	Sec. 5.1 of lecture
//	Array: Pivot for a vector
//		a.out < input.513{a,b,c}

#include <iostream>
#include <limits>                     // numeric_limits
using namespace std;

int main()
{
    const int N = 10;
    double x[N];
//                               Initialize x
//                               ...
    cout << "Input of x-values: ";
    for (int i = 0; i < N ; ++i) {
        cin >> x[i];
    }
//				 Print orig. vector
    cout << endl << " Orig. vector" << endl;
    for (int i = 0; i < N ; ++i) {
        cout << "  " << x[i];
    }
    cout << endl;
//                               Initialize min/max values
    double xmin =  numeric_limits<double>::max(),
           xmax = -xmin;
//				 Initialize indices storing positions for min/max
    int kmin = -1, kmax = -1;
//				 Determine min/max
    for (int i = 0; i < N; ++i) {
        if ( xmin > x[i] ) {
            xmin = x[i];
            kmin = i;
        }
        if ( xmax < x[i] ) {
            xmax = x[i];
            kmax = i;
        }
    }
//				Swap Pivot elements
//			Do nothing for N=0 or constant vector
    if ( kmax != kmin ) {
        double tmp = x[kmin];
        x[kmin] = x[kmax];
        x[kmax] = tmp;
    }
    else {
        cout << endl << " Nothing to swap";
    }
//				 Print Pivot vector
    cout << endl << " Pivot vector" << endl;
    for (int i = 0; i < N ; ++i) {
        cout << "  " << x[i];
    }
    cout << endl;

    return 0;
}









