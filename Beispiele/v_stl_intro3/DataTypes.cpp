//	DataTypes.cpp
//			Accuracy ??

#include <iostream>
using namespace std;

int main()
{
//	Define variables

 float		rf;
 double		rd;
 long double	rl;
 short		is;
 int		ii;
 long int	il;
 long long int	ill;
 unsigned int	iu;

//	Set variables

 rf = 1.23456789f;
 rd = 1.23456789;
 rl = 1.23456789l;

 is  = 123;
 ii  = 123;
 il  = 123;
 ill = 123;
 iu  = 123;

//	Print variables
				/*	"endl" - new line		*/
 cout << endl << " Double" << endl;
				/*	limited #digits in output	*/
				/*	Rounding !			*/
 cout << "rd = " << rd << endl;

 cout.precision(10);		/*	10 digits in output		*/
 cout << "rd = " << rd << endl;

 cout << endl << " Float" << endl;
 				/*	Only 8 digits accurate in float	*/
 cout << "rf = " << rf << endl;

 cout << endl << " Long Double" << endl;

 cout << "rl = " << rl << endl;

 cout << endl << " Integer" << endl;

 cout << "ii = " << ii << endl;
 cout << "iu = " << iu << endl;
 cout << "is = " << is << endl;
 cout << "il = " << il << endl;
 cout << "ill = " << ill << endl;

 cout << endl << "################################" << endl;
 cout << " Size of Data Types: sizeof()" << endl << endl;

 cout << "Size of          bool: " << sizeof(bool) << endl;
 cout << "Size of   signed char: " << sizeof(signed char) << endl;
 cout << "Size of     short int: " << sizeof(short int) << endl;
 cout << "Size of           int: " << sizeof(int) << endl;
 cout << "Size of           int: " << sizeof(ii) << endl;
 cout << "Size of  unsigned int: " << sizeof(unsigned int) << endl;
 cout << "Size of      long int: " << sizeof(long int) << endl;
 cout << "Size of long long int: " << sizeof(long long int) << endl;
 cout << endl;
 cout << "Size of         float: " << sizeof(float) << endl;
 cout << "Size of        double: " << sizeof(double) << endl;
 cout << "Size of   long double: " << sizeof(long double) << endl;
 cout << endl;

 return 0;
}









