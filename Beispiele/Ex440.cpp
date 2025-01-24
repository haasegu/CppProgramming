//	Ex440.cpp

//	Sec. 4.4 of lecture
//	FOR-loop
//				Example : sum of natural numbers

#include <iostream>
using namespace std;

int main()
{
 int   i,isum,n;			// loop index, sum, last index
 
 n = 5;					// initialize last index

//
//					  Conventional version
//

 isum = 0;				// initialize sum (integer !)
 
 for ( i = 1; i <= n; i=i+1)
   {
     isum = isum +i;
   }
 
 cout << endl << "Sum of first " << n << " natural numbers = " << isum << endl; 

//
//					  Sophisticated version (poor style)
//
 
 for ( isum = 0, i = 1; i <= n; isum += i , ++i) ;
 
 cout << endl << "Sum of first " << n << " natural numbers = " << isum << endl;
  
}
 
 
 
 
 
 
 
 
 
