//	Ex226.cpp

//	Sec. 2.1 of lecture
//	Conventions for naming variables

#include <iostream>
using namespace std;

int main()
{
 const int    N = 5;	    // First and only initialization of constant N
       int    j = 5;	    // First          initialization of variable j
 cout << "Hello World\n";
 
 int i = j+ N;              // Better: initialize variable at declaration
 
 cout << endl << i << " " << j << " " << N << endl;
 
 return 0;
}
 
 
 
 
 
 
 
 
 