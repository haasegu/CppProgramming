//	Ex443.cpp

//	Sec. 4.4 of lecture
//	FOR-loop
//				Example : CountDown

#include <iostream>
using namespace std;

int main()
{
 int   n;				         // last loop index

 cout << endl << "  CountDown " << endl;
 cout << endl << "  n = ";
 cin  >> n;				         // initialize last index

 for ( int i = n; i >= 1; --i )  // loop index i
   {
     cout << " " << i;
   }

 cout << endl << endl;
 return 0;
}









