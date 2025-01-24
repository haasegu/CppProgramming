//	Loops.cpp
//			3 versions of a  loop

#include <iostream>
using namespace std;

int main()
{
 int i,n;
 
 n=5;
 
// ---------------------------------------	Classical loop

 cout << endl <<  "Classical loop by  for" << endl;

 for (i = 0; i < n; ++i)
   { 
    cout << "  " << i;
   }
 cout << endl;

// ---------------------------------------	While

 cout << endl << "Loop by  while" << endl;

 i = 0;
 while ( i < n )
   {
    cout << "  " << i;
    ++i;
   }
 cout << endl;

// ---------------------------------------	Do While

 cout << endl << "Loop by  do while" << endl;
 cout << "           wrong for n <= 0 !!" << endl;

 i = 0;
 do
   {
    cout << "  " << i;
    ++i;
   }
 while ( i < n );
 
 cout << endl;

}
 
 
 
 
 
 
 
 
 
