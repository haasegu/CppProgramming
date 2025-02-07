//	Ex470.cpp
//	Sec.4.7 of lecture
//			Demonstration of Switch statement (break !!)

#include <iostream>
using namespace std;

int main()
{
 int number;

//  number = 2,
 cout << " number = "; cin >> number;

 cout << endl << "  Note " << number << endl;

 switch(number)
  {
   case 1:
   case 2:
   case 3:
   case 4:
    	cout << "  Bestanden " << endl;
 	break;
   default:
    	cout << " nicht best. " << endl;
	break;
  }
 cout << endl;
 return 0;
}









