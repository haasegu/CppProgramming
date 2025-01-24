//	Ex450.cpp

//	Sec. 4.5 of lecture
//	WHILE-loop
//				Example : Binary log. of a number

#include <iostream>
using namespace std;

int main()
{
 cout << endl << " Eingabe x : " ;
 double x;
 cin  >> x;
 const double xsave = x;           // Save to restore x

 int cnt = 0;                      // Initialize loop index !!
 while ( x > 1.0 )
   {
     x   = x/2.0 ;
     cnt = cnt + 1;
   }

 cout << endl << "Binary log. of " << xsave << " = " << cnt << endl;
 return 0;
}









