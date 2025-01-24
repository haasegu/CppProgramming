//	Ex443.cpp

//	Sec. 4.4 of lecture
//	FOR-loop
//				Example : sum of even natural numbers

#include <iostream>
using namespace std;

int main()
{
 int   n;               // last index

 cout << endl << "  Sum of even numbers " << endl;
 cout << endl << "  n = ";
 cin  >> n;             // initialize last index

 int isum = 0;          // initialize sum (integer !)

 for ( int i = 2; i <= n; i+=2)
   {
     isum = isum +i;
   }

 cout << endl << "  Sum of first " << n/2 << " even numbers = " << isum << endl;
 cout << endl;
 return 0;
}









