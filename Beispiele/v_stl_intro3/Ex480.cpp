//	Ex480.cpp

//	Sec. 4.8 of lecture
//	Use of break, continue, goto
//			!!!!!!!  poor style of programming !!!!!!!

#include <iostream>
using namespace std;

int main()
{
    int   i, isum, n;

    n = 5;					// initialize last index

    cout << endl << "  Exit FOR-loop with BREAK" << endl;
    isum = 0;				// initialize sum (integer !)

    for ( i = 1; i <= n; i = i + 1) {
        cout << "  Index ";
        if ( isum >= 6 ) {
            break;
        }
        isum = isum + i;
        cout <<  i << endl;
    }

    cout << endl << "  Sum = " << isum << endl;
    cout << "---------------------" << endl;

//
//
//

    cout << endl << "  Exit FOR-loop with GOTO" << endl;
    isum = 0;				// initialize sum (integer !)

    for ( i = 1; i <= n; i = i + 1) {
        cout << "  Index ";
        if ( isum >= 6 ) {
            goto NOPRINT;
        }
        isum = isum + i;
        cout <<  i << endl;
    }

    cout << endl << "  Sum = " << isum << endl;

NOPRINT:
    cout << "---------------------" << endl;

//
//
//

    cout << endl << "  Start next FOR-loop with CONTINUE" << endl;
    isum = 0;				// initialize sum (integer !)

    for ( i = 1; i <= n; i = i + 1) {
        cout << "  Index ";
        if ( isum >= 6 ) {
            continue;
        }
        isum = isum + i;
        cout <<  i << endl;
    }

    cout << endl << "  Sum = " << isum << endl;
    cout << "---------------------" << endl;

}









