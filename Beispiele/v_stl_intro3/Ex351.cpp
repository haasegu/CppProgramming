//	Ex351.cpp

//	Sec. 3.5 of lecture
//	mask for odd numbers

#include <iostream>
using namespace std;

int main()
{
 const int   Maske = 1;               // 0..00000L
       int   i;

 cout << endl << "   Eingabe einer ganzen Zahl: ";
 cin  >> i;                          //  read number

//	Check for odd number:
//	      Last bit remains unchanged for odd numbers
 cout << "  " << i << " ist eine ";
 if ((i | Maske) == i)
  {
    cout << "ungerade";
  }
 else
  {
    cout << "gerade";
  }
 cout << " Zahl." << endl << endl;
 return 0;
}









