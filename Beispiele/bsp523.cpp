//	Ex523.cpp

//	Sec. 5.2 of lecture
//	structure in structure
//		a.out < input.523

#include <cmath>                        // sqrt()
#include <iostream>
using namespace std;

struct Point3D {
    double x, y, z;	                    // Point consists of coordinates
};
struct Line3D {
    Point3D p1, p2;            	        // Line is defined by two points
};

int main()
{
    Line3D line;                        // one line
    

    cout << "\n Input Line , Point 1 (x,y,z) : ";
    cin  >> line.p1.x >> line.p1.y >> line.p1.z;
    cout << "             Point 2 (x,y,z) : ";
    cin  >> line.p2.x >> line.p2.y >> line.p2.z;

//    Calculate distance between points
    const double length = 
               sqrt(   (line.p2.x - line.p1.x) * (line.p2.x - line.p1.x)
                     + (line.p2.y - line.p1.y) * (line.p2.y - line.p1.y)
                     + (line.p2.z - line.p1.z) * (line.p2.z - line.p1.z) );

    cout << endl << " has length  " << length << endl<< endl;
    return 0;
}









