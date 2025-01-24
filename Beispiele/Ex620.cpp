//	Ex620.cpp

//	Sec. 6.2 of lecture
//	Pointer operators

#include <iostream>
using namespace std;

int main()
{
    int i, j, *pint;

    i      = 10;
    pint   = &i;                        // pointer initialization
    j      = *pint;                     // access on 'i' via pointer

    cout << endl << "  " << i << "  " << j << "  " << *pint << "  " << pint << endl;

    *pint  = 0;                         // initialize 'i' by 0  via pointer

    cout << endl << "  " << i << "  " << j << "  " << *pint << "  " << pint << endl;

    *pint += 2;                         // add 2 to 'i'  via pointers

    cout << endl << "  " << i << "  " << j << "  " << *pint << "  " << pint << endl;
    return 0;
}









