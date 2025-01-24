//	Sec. 7.4 of lecture
//	2D arrays
//	Output matrix
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp740.cpp
//  cppcheck --enable=all --inconclusive --std=c++11 --std=posix bsp740.cpp

#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MCOL = 3;             // global constants (for static 2D array)

//	----      Declarations   -----------------
/*    Prints the elements of a vector
 *
 *     @param[in]  x  vector
 */
void PrintVec(const vector<double> &x);

/*    Prints the elements of a matrix stored in 2D with a globally fixed
 *    number of columns @p MCOL.
 *
 *     @param[in]  a     2D C-array
 */
void PrintMat_fix(const vector<array<double,MCOL>> &a);

/*    Prints the elements of a vector interpreted as matrix with
 *    @p nrows rows and @p ncol columns.
 *
 *     @param[in]  nrow  number of rows
 *     @param[in]  ncol  number of columns
 *     @param[in]  a     vector
 */
void PrintMat(const int nrow, const int ncol, const vector<double> &a);

//	----      Definitions   -----------------

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
//		Print elements of a matrix - 2D storage
//			(nrow rows and fixed number MCOL of columns)
//
//void PrintMat_fix(const int nrow, const double a[][])	// doesn't compile
// 		doesn't help to fix that
//void PrintMat_fix(const int nrow, const int ncol, const double a[][])
//
void PrintMat_fix(const vector<array<double,MCOL>> &a)
//      uses the global constant MCOL |
{
    cout << endl;
    for (size_t i = 0; i < a.size(); ++i) {         // loop on rows
        cout << "row " << i << ":";
        for (int j = 0; j < MCOL; ++j) {            // loop on columns
            cout << "  " << a[i][j];
        }
        cout << endl;
    }
    cout << endl << endl;
    return;
}

//-------------------------------------------------------------------
//		Print elements of a matrix - 1D storage
//			(nrow rows and ncol columns)
//
void PrintMat(const int nrow, const int ncol, const vector<double> &a)
{
    assert(nrow*ncol == static_cast<int>(a.size()));
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

//  ############################################################

int main()
{
    const int NROW = 4;                     // local constant
                                            // static matrix as 2D-Array
    const vector<array<double,MCOL>> a{{ {{4, -1, -0.5}}, {{ -1, 4, -1}}, {{ -0.5, -1, 4}}, {{3, 0, -1}} }};
    assert( NROW ==  static_cast<int>(a.size()) );        // check number of rows

                                            
    vector<double> b(NROW * MCOL);          // allocate dynamic matrix b as 1D-Array

    for (int i = 0; i < NROW; ++i)          // copy matrix 'a' on matrix 'b'
        for (int j = 0; j < MCOL; ++j)
            b[i * MCOL + j] = a[i][j];

                                            // output matrices
    PrintMat_fix(a);                        //   2D with globally fixed #columns
    PrintMat(NROW, MCOL, b);                //   1D interpreted as matrix

//			output static vector
    vector<double> u(MCOL);
    for (size_t i=0; i<u.size(); ++i)  u[i] = i+1;  
    PrintVec(u);
    
    return 0;
}





