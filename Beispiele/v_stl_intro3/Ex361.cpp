//	Ex361.cpp
//
//	Sec. 3.6.1 of Lecture
//	Math. functions,

#include <cmath>                  // include defintions for math. functions
#include <iostream>
using namespace std;

int main()
{
 double x = -1;                           //   x < 0 !!
 double y = sqrt(x);                      //   Square root with wrong argument

 cout << "x = " << x << " ,  y  = " << y << endl;

 double z = std::abs(x);                  //   Absolut value
 cout << "x = " << x << " , |x| = " << z << endl;

 y = 3.0;                                 //   try 2.0 , 3.0 and 2.5
 z = pow(x,y);                            //   Power function  x^y
 cout << "(x,y) = " << x << " , " << y << " , x^y = " << z << endl;
 return 0;
}









