//	Ex470.cpp
//	Sec.4.7 of lecture
//			Demonstration of Switch statement (break !!)

#include <iostream>
using namespace std;

int main()
{
 int number;

//  number = 2,
 cout << " number = ";  cin >> number;

 cout << endl << "  Print names of numbers from interval [1,3]" << endl;

 switch(number)
  {
    case 1:
    	cout << "  One = " << number << endl;
// 	break;
    case 2:
    	cout << "  Two = "  << number << endl;
	break;				// Comment this line
    case 3:
    	cout << "  Three = "  << number << endl;
	break;
    default:
    	cout << "  Number " << number << " not in interval" << endl;
	break;
  }
 cout << endl;
 return 0;
}









