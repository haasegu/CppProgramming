//	Ex362.cpp
//
//	Sec. 3.6.2 of Lecture
//	String functions

#include <iostream>
#include <string>		        // C++-strings and functions for C++-strings
using namespace std;

int main()
{
 string s, s1("Hello"), s2("World");

 cout << "s1 = " << s1 << endl;
 cout << "s2 = " << s2 << endl;

 bool bi = s1 < s2;             // lex. comparison

 cout << "cmp : " << bi << endl;

 s = s1;                        // copy s1 on s

 cout << "s  : " << s << endl;

 s = s + s2;                   // Appends s2 on s

 cout << "s  : " << s << endl;

 int i = s.size();              // length of string s

 cout << "Length of s : " << i << endl;

}









