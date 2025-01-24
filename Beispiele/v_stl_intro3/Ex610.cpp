//	Ex610.cpp

//	Sec. 6.1 of lecture
//	Pointer declaration

#include <iostream>
using namespace std;

struct Student {
    long long int matrikel;
    int skz;
    string name, vorname;
};

int main()
{
    char            *cp;                // pointer on char
    int          x, *px;                // int-variable, pointer on int
    float           *fp[20];            // C-array of 20 pointers on float
    float           *(fap[20]);         // pointer on a C-array of 20 float
    Student         *ps;                // pointer on structure Student
    char           **ppc;               // pointer on pointer of char
                                        //  ALL pointers are undefined yet !!

    px = &x;                            // address of variable x
    cout << endl;
    cout << " Size  px : " << sizeof(px) << endl;
    cout << " Value px : " << px << endl;
//			   px is undefined (LINUX-gcc)
//			or px = 0 = 0x0 = nulptr (C++11)

    px = nullptr;                       //  px = 0
    if ( px == nullptr) {
        cout << endl << "px == nullptr : " << px << endl;
    }
    return 0;
}









