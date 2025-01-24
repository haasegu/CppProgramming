//	Ex432.cpp

//	Sec. 4.3 of lecture
//	Alternative
//				Example: Signum function

#include <iostream>
using namespace std;

int main()
{
 double x,y;

 cout << endl << " Input Argument      : ";
 cin  >> x;

//
//					Version a)
//

 if ( x > 0.0 )
   {
     y = 1.0 ;
   }
 else
   {
     if ( x == 0.0 )
       {
         y = 0.0 ;
       }
     else
       {
         y = -1.0 ;
       }
   }

 cout << " Result of version a) : " << y << endl;

//
//					Version b)
//


 if ( x > 0.0 )
   {
     y = 1.0 ;
   }
 else if ( x == 0.0 )        // else und nachfolgendes, inneres if zusammengezogen
   {
     y = 0.0 ;
   }
 else                        // diese else gehoert zu inneren if
   {
     y = -1.0 ;
   }

 cout << " Result of version b) : " << y << endl;

//
//					Version c) Entscheidungsoperator
//

 y = (x > 0 ? 1. : 0.) + (x < 0 ? -1. : 0.);

 cout << " Result of verion c) : " << y << endl << endl;

 return 0;
}









