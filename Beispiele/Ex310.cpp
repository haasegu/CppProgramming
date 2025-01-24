//	Ex310.cpp

//	Sec. 3.1. of lecture
//	Assignments

#include <iostream>
using namespace std;

int main()
{
 int   a,b,c;
 float x,y;
 
 x = 0;
 y = x+4;

 cout << " x = " << x << endl;
 cout << " y = " << y << endl;

 a = b = c = 123;              // 1. Moeglichkeit
 a = (b = (c = 123));          // 2. Moeglichkeit
 c = 123; b = c;  a = b;       // 3. Moeglichkeit


 cout << " a = " << a << endl;
 cout << " b = " << b << endl;
 cout << " c = " << c << endl;
 
 return 0;
}
 
 
 
 
 
 
 
 
 
