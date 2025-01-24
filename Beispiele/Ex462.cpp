//	Ex460.cpp

//	Sec. 4.6 of lecture
//	DO-WHILE-loop and  WHILE-loop
//			Example: Find the solution by bisection

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
  const double Eps = 1e-6;
  double a,b,c,fc;

  cout << endl;
  cout << " Nullstellenberechnung durch Halbierung [a,b]" << endl;

  cout << " f(a) > 0,  a : "; cin >> a;
  cout << " f(b) < 0,  b : "; cin >> b;

//	Check that f(a) > 0,  f(b) < 0 !!
// ...

//	While loop
  c  = (a+b)/2.0;
  fc = sin(c)-c/2;
  while ( std::abs(fc) > Eps)
  {
   if ( fc > 0.0 )
    {
      a = c;
    }
   else
    {
      b = c;
    }
   c  = (a+b)/2.0;
   fc = sin(c)-c/2;
  }

  cout << endl;
  cout << " (a) Nullstelle = " << c << endl;

//		Do-While loop
  c  = a;		// since f(a) > 0
  fc = sin(c)-c/2;
  do
   {
    if ( fc > 0.0 )
     {
       a = c;
     }
    else
     {
       b = c;
     }
    c  = (a+b)/2.0;
    fc = sin(c)-c/2;
   }
  while ( std::abs(fc) > Eps);
//  while ( std::abs(fc) != 0.0);	// endless!! Why ?

  cout << endl;
  cout << " (b) Nullstelle = " << c << endl;
  cout << endl;
  return 0;
}









