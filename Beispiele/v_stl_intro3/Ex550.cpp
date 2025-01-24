//	Ex550.cpp

//	Sec. 5.5 of lecture
//	general type definitions

#include <cstring>
#include <iostream>
using namespace std;
                                        // new types
typedef short int Boolean;              // 2 Byte boolean (waste of memory)
typedef char      Text[100];            // Text is a C-String of length 99
typedef struct {                        // the same as struct Point3D
    double x, y, z;
} Point3D;

int main()
{
    Boolean a, b;
    Text    eintrag;
    Point3D pts[10];                    // C-array of 10 points unitialized
    const Point3D  p = {1, 2, 3.45};    // one point initialized

    strcpy(eintrag, "A beautiful code");//                   init
    pts[0] = p;
    a      = (p.x == pts[0].x);         // my boolean variable
    b      = !a;                        // my boolean variable

    cout<< endl << eintrag << endl;     //output
    cout << "p = " << p.x << " , " << p.y << " , " << p.z << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}









