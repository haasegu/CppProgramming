//	g++ -std=c++11 Ex550_11.cpp

//	Sec. 5.6 of lecture
//	general type definitions

#include <iostream>
using namespace std;
                                    // new alias
using Boolean = short int;          // 2 Byte boolean (waste of memory)
using Text = char[100];             // Text is a C-String of length 99
using Point3D = struct {            // the same as struct Point3D
    double x, y, z;
};

int main()
{
    Text    eintrag{"A beautiful code"};
    Point3D pts[10];                    // C-array of 10 points unitialized
    const Point3D  p{1, 2, 3.45};       // one point initialized

    pts[0]    = p;
    Boolean a = (p.x == pts[0].x);      // my boolean variable
    Boolean b = !a;                     // my boolean variable

    cout<< endl << eintrag << endl;     //output
    cout << "p = " << p.x << " , " << p.y << " , " << p.z << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}









