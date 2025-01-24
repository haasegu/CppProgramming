//	printvec.cpp
//
//		Includes definition for print routines used
//		in  Ex751-old.cpp  and  Ex751.cpp
//
//	Compile with: g++ -c printvec.cpp
//	Produces  printvec.o

#include <cassert>                      // assert()
#include <iostream>
#include <vector>
using namespace std;

//-------------------------------------------------------------------
//		Print elements of a vector (length n)
//
void PrintVec(const vector<double> &x)
{
    cout << endl;
    for (size_t i = 0; i < x.size(); ++i) {
        cout << "  " << x[i];
    }
    cout << endl << endl;
    return;
}

//-------------------------------------------------------------------
//		Print elements of a matrix
//			(nrow rows and ncol columns)
//
void PrintMat(const int nrow, const int ncol, const vector<double> &a)
{
    assert(nrow*ncol==a.size());        // sind die Parameter kompatibel?
    cout << endl;
    for (int i = 0; i < nrow; ++i) {
        cout << "Row " << i << ":";
        for (int j = 0; j < ncol; ++j) {
            cout << "  " << a[i * ncol + j] ;
        }
        cout << endl;
    }
    cout << endl << endl;
    return;
}









