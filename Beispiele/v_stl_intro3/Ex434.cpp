//	Ex434.cpp

//	Sec. 4.3 of lecture
//	Alternative
//				Example: Minimum of three numbers

#include <iostream>
using namespace std;

int main()
{
 int i1,i2,i3,imin;

 cout << endl << " Input Arguments   i1 i2 i3  : ";
 cin  >> i1 >> i2 >> i3;

//
//                  Version a) geschachtelte Alternativen
//

 if ( i1 < i2 )
   {
     if ( i1 < i3 )
       {
         imin = i1;
       }
     else
       {
         imin = i3;
       }
   }
 else
   {
     if ( i2 < i3 )
       {
         imin = i2;
       }
     else
       {
         imin = i3;
       }
   }

 cout << " Min  (a) : " << imin  << endl;

//
//                  Version b), mit Enscheidungsoperator
//

 if ( i1 < i2 )
   {
     imin = ( i1 < i3 ) ? i1 : i3 ;
   }
 else
   {
     imin = ( i2 < i3 ) ? i2 : i3 ;
   }

 cout << " Min  (b) : " << imin  << endl;

//
//                  Version c) Entscheidungsoperator wird intensiv genutzt,
//                  Code wird sehr kompakt - jedoch unlesbar
//                  (WOP - Write Only  Programming)
//

 imin = (i1 < i2) ? ( ( i1 < i3 ) ? i1 : i3 ) : ( ( i2 < i3 ) ? i2 : i3 ) ;

 cout << " Min  (c) : " << imin  << endl;
 return 0;
}









