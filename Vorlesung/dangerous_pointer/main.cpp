#include <cassert>
#include <iostream>
#include <numeric>      // iota

using namespace std;


/** \brief Initializes a dynamic C array.
 *
 * \param[in]      n  number of elements
 * \param[in,out]  x  array
 *
 */
void init_Carray(int n, double *x);

void init_Carray(int n, double *x)
{
    assert(n >= 0);
    iota(x,x+n,3);
}

/** \brief Print a dynamic C array into the console.
 *
 * \param[in]  n  number of elements
 * \param[in]  x  array
 *
 */
//void print_Carray(int n, double const * const x)
void print_Carray(int n, double const x[])     // hidden pointer x
{
    assert(n >= 0);
    for (int k=0; k<n; ++k)
    {
		cout << x[k] << "  ";
	}
	cout << endl;
	delete[] x;               // dangerous side effect
}


int main()
{
    cout << "Dangerous Pointer" << endl;
    int n;
    cout << "Number of elements  n = "; cin >>n;
    
    double* const v = new double [n];
    init_Carray(n,v);
    
    print_Carray(n,v);
    
    v[0] = -3;
    
    print_Carray(n,v);

    delete[] v;
 
    return 0;
}
