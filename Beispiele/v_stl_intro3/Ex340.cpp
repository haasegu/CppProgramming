//	Ex340.cpp

//	Sec 3.4 of lecture
//	Logical operations. Check weather a number is in an intervall.

#include <iostream>
using namespace std;

int main()
{
 const int Ne = 5;              // one limit
       int i;

 cout << " i = " ; cin  >> i;   // Input i
                                //
 if ( 0 <= i && i <= Ne )       // Is 'i' in intervall [0,Ne] ?
  {
    cout << "i between 0 and 5" << endl;
  }

 return 0;
}









