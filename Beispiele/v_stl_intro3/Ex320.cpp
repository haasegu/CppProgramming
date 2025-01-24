//	Ex320.cpp

//	Sec. 3.2 of lecture
//	Aritmetic Operations

#include <iostream>
using namespace std;

int main()
{
 float ij_mod, ij_div, float_ij_div;
 int   i=8, j=3;
 
 ij_div = i / j;                          // Achtung: Ergebnis ist 2
 ij_mod = i % j;                          // Modulu-Rechnung

                      // Casting des Nenners ==> Resultat ist 2.666666
 float_ij_div = i/(float)j;               // explizites C-casting  (alt)
 float_ij_div = i/static_cast<float>(j);  // explizites C++-casting
 float_ij_div = i/(j+0.);                 // implizites Casting
 
 cout << i << " div " << j << " = " << ij_div << endl;
 cout << i << " mod " << j << " = " << ij_mod << endl;
 cout << i << "/" << j << " = " << float_ij_div << endl;

//-----------------------------------------------------

 cout << endl << "-------------------------" << endl;
 
 int k;
 double x = 2.1;
 
 k = 1;                         // k stores 1
 cout << " k_1 : " << k << endl;
 
 k = 9/8;                       // k stores 1, Int. Div.
 cout << " k_2 : " << k << endl;

 k = 3.14;                      // k stores 3, truncated
 cout << " k_3 : " << k << endl;
 
 k = -3.14;                     // k stores -3 or -4, compiler dependent
 cout << " k_4 : " << k << endl;
 
 k = 2.9e40;                    // undefined ee
 cout << " k_5 : " << k << endl;
 
 x = 9/10;                      // x stores 0
 cout << " x_1 : " << x << endl;
 
 x = (1.0+1)/2;                 // x stores 1.0
 cout << " x_2 : " << x << endl;
 
 x = 1 + 1.0/2;                 // x stores 1.5
 cout << " x_3 : " << x << endl;
 
 x = 0.5 + 1/2;                 // x stores 0.5
 cout << " x_4 : " << x << endl;
 
 return 0;
}
 
 
 
 
 
 
 
 
 
