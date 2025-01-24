//	Ex362.cpp
//
//	Sec. 3.6.2 of Lecture
//	String functions

#include <cstring>		// functions for C-strings
#include <iostream>
using namespace std;

int main()
{
//    Definition and initialization of string variables 
//        --> Sec. 5.1

 char s[30], s1[30] = "Hello", s2[] = "World";
 int  i;

 cout << "s1 = " << s1 << endl;	
 cout << "s2 = " << s2 << endl;	 
 
 i = strcmp(s1,s2);		// lex. comparison
 
 cout << "cmp : " << i << endl;

 strcpy(s,s1);			// copy s1 on s
 
 cout << "s  : " << s << endl;
 
 strcat(s,s2);			// Appends s2 on s
 
 cout << "s  : " << s << endl;
 
 i = strlen(s);			// length of string s
 
 cout << "Length of s : " << i << endl;

}
 
 
 
 
 
 
 
 
 
