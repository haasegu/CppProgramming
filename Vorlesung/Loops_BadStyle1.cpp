//	Loops.cpp
//	Bad Style 1: no comments

#include <iostream>
using namespace std;

int main()
{
 int i,n;

 n=5;


 cout << endl <<  "Classical loop by  for" << endl;

 for (i = 0; i < n; ++i)
   {
    cout << "  " << i;
   }
 cout << endl;


 cout << endl << "Loop by  while" << endl;

 i = 0;
 while ( i < n )
   {
    cout << "  " << i;
    ++i;
   }
 cout << endl;


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
 return 0;
}









