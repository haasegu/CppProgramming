//	Ex530.cpp

//	Sec. 5.3 of lecture
//	Union

#include <iostream>
using namespace std;

union operand {
    int    i;
    float  f;
    double d;
};

int main()
{
    operand u;                     // Variable of union type

    cout << endl << "Size (operand) : " << sizeof(u) << " Bytes" << endl;

    u.i = 123;                     // Data input

    cout << endl << u.i << "  " << u.f << "  " << u.d << endl;

    u.f = 123;

    cout << endl << u.i << "  " << u.f << "  " << u.d << endl;

    u.d = 123;

    cout << endl << u.i << "  " << u.f << "  " << u.d << endl;

    return 0;
}









