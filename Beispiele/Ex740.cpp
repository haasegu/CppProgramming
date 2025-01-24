//	Ex740.cpp

//	Sec. 7.4 of lecture
//	2D arrays
//	Output matrix

#include <iostream>
using namespace std;

const int MCOL = 3;             // global constants (for static 2D array)

//	----      Declarations   -----------------
/*    Prints the elements of a C-array
 *
 *     @param[in]  n  number of elements
 *     @param[in]  x  C-array
 *
 */
void PrintVec(const int n, const double x[]);

/*    Prints the elements of a C-matrix stored in 2D with a globally fixed
 *    number of columns @p MCOL.
 *
 *     @param[in]  nrow  number of rows
 *     @param[in]  a     2D C-array
 *
 */
void PrintMat_fix(const int nrow, const double a[][MCOL]);

/*    Prints the elements of a C-array interpreted as matrix with
 *    @p nrows rows and @p ncol columns.
 *
 *     @param[in]  nrow  number of rows
 *     @param[in]  ncol  number of columns
 *     @param[in]  a     C-array
 *
 */
void PrintMat(const int nrow, const int ncol, const double a[]);

//	----      Definitions   -----------------

void PrintVec(const int n, const double x[])
{
    cout << endl;
    for (int i = 0; i < n; ++i) {
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
void PrintMat_fix(const int nrow, const double a[][MCOL])
//                    uses the global constant MCOL |
{
    cout << endl;
    for (int i = 0; i < nrow; ++i) {
        cout << "row " << i << ":";
        for (int j = 0; j < MCOL; ++j) {
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
void PrintMat(const int nrow, const int ncol, const double a[])
{
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
    // static matrix a
    const double a[NROW][MCOL] = {{4, -1, -0.5}, { -1, 4, -1}, { -0.5, -1, 4}, {3, 0, -1} };

    const int nrow = NROW,                  // instead of input
              ncol = MCOL;
                                            
    double *b = new double [NROW * MCOL];   // allocate dynamic matrix b

    for (int i = 0; i < NROW; ++i)          // copy matrix 'a' on matrix 'b'
        for (int j = 0; j < MCOL; ++j)
            b[i * MCOL + j] = a[i][j];

                                            // output matrices
    PrintMat_fix(NROW, a);                  //   2D with globally fixed #columns
    PrintMat(NROW, MCOL, a[0]);             //   first row of matrix a
    PrintMat(nrow, ncol, b);                //   1D interpreted as matrix

//			output vector
    const double u[MCOL] = {1, 2, 3};
    PrintVec(MCOL, u);
    delete [] b;
    return 0;
}





