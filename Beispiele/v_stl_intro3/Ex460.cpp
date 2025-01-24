//	Ex460.cpp

//	Sec. 4.6 of lecture
//	DO-WHILE-loop
//			Example : Input of a character until 'x'

#include <iostream>
using namespace std;

int main()
{
 char ch;

 do
   {
     cout << endl << "Input command (x = exit, ...)  ";
     cin  >> ch;
   }
 while ( ch != 'x' );

 cout << endl << "          Exit program" << endl << endl;
 return 0;
}









