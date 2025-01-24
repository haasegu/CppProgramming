//	Ex431.cpp

//	Sec. 4.3 of lecture
//	Alternative
//				Example: Heaviside function

#include <iostream>
using namespace std;

int main()
{
 double x,y;

 cout << endl << " Input Argument      : ";
 cin  >> x;

//
//                            Version a) Einseitige Alternative
//

 y = 0.0 ;               // Setzen des Wertes fuer den else-Zweig
 if ( x >= 0.0 )
     y = 1.0 ;           // genau eine Anweisung im if-Zweig, daher keine {} noetig

 cout << " Result of version a) : " << y << endl;

//
//                            Version b) Zweiseitige Alternative
//

 if ( x >= 0.0 )
     y = 1.0 ;          // genau eine Anweisung im if-Zweig, daher keine {} noetig
 else
     y = 0.0 ;          // genau eine Anweisung im else-Zweig, daher keine {} noetig

 cout << " Result of version b) : " << y << endl;

//
//                            Version c) Zweiseitige Alternative mit Klammern
//

 if ( x >= 0.0 )
   {
     y = 1.0 ;
   }
 else
   {
     y = 0.0 ;
   }

 cout << " Result of version c) : " << y << endl;

//
//                            Version d) Entscheidungsoperator
//

 y = x >= 0 ? 1.0 : 0.0 ;

 cout << " Result of version d) : " << y << endl << endl;

 return 0;
}









