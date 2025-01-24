//	Ex514.cpp

//	Sec. 5.1 of lecture
//	2D arrays
//	Multiplication Matrix*Vector  f := A * u
//		with A as 2D array   or  B as 1D array

#include <iostream>
using namespace std;

int main()
{
    const int NROW = 4, MCOL = 3;
    double       f[NROW];
    const double u[MCOL] = {1, 2, 3};

//      matrix as 2D-Array
    const double a[NROW][MCOL] = {{4, -1, -0.5}, { -1, 4, -1}, { -0.5, -1, 4}, {3, 0, -1} };
//		matrix times vector : f := A * u
    for (int i = 0; i < NROW; ++i) {
        f[i] = 0.0;			                   // initialize f[i]
        for (int j = 0; j < MCOL; ++j) {
            f[i] = f[i] + a[i][j] * u[j];
        }
    }
//			output result
    cout << endl;
    for (int i = 0; i < NROW; ++i) {
        cout << "  " << f[i];
    }
    cout << endl << endl;

//---------------------------------------------------------------

//      matrix as 1D array with index calculation
    const double b[NROW * MCOL]  = {4, -1, -0.5, -1, 4, -1, -0.5, -1, 4, 3, 0, -1 };
//		matrix times vector : f := B * u
    for (int i = 0; i < NROW; ++i) {
        f[i] = 0.0;			                   // initialize f[i]
        for (int j = 0; j < MCOL; ++j) {
            f[i] = f[i] + b[i * MCOL + j] * u[j];
        }
    }
//			output result
    cout << endl;
    for (int i = 0; i < NROW; ++i) {
        cout << "  " << f[i];
    }
    cout << endl << endl;
    return 0;
}









