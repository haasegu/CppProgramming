//	Loop_Float.cpp
//			loop in float and in int

#include <iostream>
using namespace std;

int main()
{
 cout << endl << "  Loop in float (try with n= 100)" << endl;
 cout << endl << "   n = ";
 int n;
 cin  >> n;                             //  # subintervals

 const float xa = 0.0e0,                //  # start interval
             xe = 1.0e0,                //  # end interval
        xstride = (xe-xa)/n;            //  length subinterval
 float xi;
// ---------------------------------------	Loop in int

 cout << endl <<  "Print all subinterval nodes (loop in int)" << endl;

 for (int i = 0; i <= n; ++i)
   {
    xi = xa + i*xstride;
    cout << " node " << i << " : " << xi << endl;
   }
 cout << endl;

// ---------------------------------------	Loop in Float

 cout << endl <<  "Print all subinterval nodes (loop in float)" << endl;

 int i = 0;
 for (xi = xa; xi <= xe+xstride/10; xi += xstride)
   {
    cout << " node " << i << " : " << xi << endl;
    ++i;
   }
 cout << endl;
 cout << "xi - xe = " << xi - xe << endl << endl;
 return 0;
}









