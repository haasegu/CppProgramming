//	Ex420.cpp

//	Sec. 4.2 of lecture
//	Block

#include <iostream>
using namespace std;

int main()
{                                     // Begin outer scope
 int i{1}, j{1};                         // outer i

 {                                       // Begin inner scope
   int k;                                   // inner k
   int i;                                   // inner i

   i = k = 3;
   cout << "  inner i = " << i << endl;     // inner i is used
   cout << "i_outer j = " << j << endl;
 }                                       // End inner scope

 cout << "  outer i = " << i << endl;     // outer i is used
 cout << "  outer j = " << j << endl;

// j = i+k;			                     // k undeclared !!

}                                     // End outer scope









