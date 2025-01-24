//	Ex224.cpp
//	Example for difference between character and string constants

#include <iostream>
using namespace std;

int main()
{
 cout << "Hello World\n";                          // String literal
 
 cout << "A" << " String " << sizeof("A") << endl; // String
 
 cout << 'A' << " Char   " << sizeof('A') << endl; // Character
 
 return 0;
}
 
 
 
 
 
 
 
 
 
