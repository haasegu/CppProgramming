//	Ex470.cpp
//	Sec.4.7 of lecture
//			Demonstration of Switch statement (break !!)

#include <iostream>
using namespace std;

int main()
{
 int number;

//  number = 2,
 cin >> number;
 
 cout << endl << "  Note " << endl;

 switch(number)
  {
   case 1:
   case 2:
   case 3:
   case 4:
    	cout << "  Bestanden "  << number << endl;
 	break;
   default:
    	cout << " nicht best. " << number << endl;
	break;
  }
 cout << endl;

}
 
 
 
 
 
 
 
 
 
