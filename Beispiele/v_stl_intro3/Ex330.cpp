//	Ex330.cpp

//	Sec. 3.3 and Sec 3.4 of lecture
//	Comparisons and logical operations

#include <iostream>
using namespace std;

int main()
{
 bool bi = ( 3 <= 4 );                              // Boolean
 bool bj = ( 3 >  4 );                              // Boolean

 cout << " 3 <= 4    TRUE   = " << bi << endl;
 cout << " 3 >  4    FALSE  = " << bj << endl;                   //    1/0
 cout << " 3 >  4    FALSE  = " << std::boolalpha << bj << endl;  // true/false
//		if - statement will be defined in Sec. 4
 int i;
 i = 3;
 if (i <= 4)
   {
     cout << "\n i less or equal 4 \n\n";
   }

//		Equal vs. Assignment

 i = 2;
 cout << " i == 3  ist ein  Vergleich : " << ( i == 3) << endl;
 cout << "         und belaesstt den Wert von i bei " << i << endl;
 cout << " i =  3  ist eine Zuweisung : " << ( i = 3) << endl;
 cout << "         und aendert den Wert von i in " << i << endl;
//
//		Use of wrong expression has side effects
 i = 2;
 cout << " AA: i = " << i << endl;
 if ( i = 3 )                      //  E R R O R : Assignment i=3 is always true !!
   {
     cout << " BB: i = " << i << endl;
     i = 0;
   }
 cout << " CC: i = " << i << endl; // i is always 0 !!


 return 0;
}









