//	Ex760.cpp
// 		We play around with exit, abort, return

//	Sec. 7.6 of lecture
//		main as function with parameters and return value
//			input parameters per command line
//
//			see also:  man atoi
//
//		for a real C++ solution, see Stroustrup, p.126 (§6.1.7)

#include <cstdlib>                      // needed for atoi, exit
#include <iostream>
using namespace std;

void spass(const int);			        // Declaration of spass()

int main(const int argc, const char *argv[])
{
    int n;

    cout << endl;
    cout << "This is code " << argv[0] << endl;

    if (argc > 1) {                     // at least one argument
        n = atoi(argv[1]);              // atoi : ACSII to Integer
    }
    else {                              // standard input
        cout << " Eingabe n : "; cin  >> n; cout << endl;
    }

    spass(n);                           // Call spass()
    cout << endl;

    return 0;				// default return value is 0
}


void spass(const int n)
{
    if (n < 0) {                        // usage of exit()
        cout << "Fatal Error in spass(): n = " << n << " < 0" << endl;
        exit(-10);                      // choose an error code
    }

    cout << "Jetzt schlaegt's aber " << n << endl;
    return;
}








