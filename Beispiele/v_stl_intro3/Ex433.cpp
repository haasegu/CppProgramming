//	Ex433.cpp

//	Sec. 4.3 of lecture
//	Alternative
//				Example: Maximum and Minimum of two numbers

#include <iostream>
using namespace std;

int main()
{
 int i1, i2, imin, imax;

 cout << endl << " Input Arguments   i1 i2 : ";
 cin  >> i1 >> i2 ;

//
//					Version a)
//

 if ( i1 < i2 )
   {
     imin = i1 ;
     imax = i2 ;
   }
 else
   {
     imin = i2 ;
     imax = i1 ;
   }

 cout << " Min,Max  (a) : " << imin << " , " << imax << endl;

//
//					Version b)
//

 imin = imax = i1;
 if ( imin > i2 )
   {
     imin = i2 ;
   }
 else
   {
     imax = i2 ;
   }

 cout << " Min,Max  (b) : " << imin << " , " << imax << endl;

//
//					Version c), Entscheidungsoperator
//

 imin  = (i1 < i2) ? i1 : i2 ;
 imax  = (i1 > i2) ? i1 : i2 ;

 cout << " Min,Max  (c) : " << imin << " , " << imax << endl;


}









