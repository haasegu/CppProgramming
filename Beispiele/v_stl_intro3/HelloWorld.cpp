//	HelloWorld.cpp

//	Include file "iostream" is needed, since cout is not declared in C++
//		     (/usr/include/g++/iostream)
//	Otherwise (gpp==g++):
//		% g++ HelloWorld.cpp
//		==>  `cout' undeclared (first use this function)
//		==>  `endl' undeclared (first use this function)
//	Info which Header file is needed:
//		man iostream; man ostream

#include <iostream>                        // deklariert  cout, endl
using namespace std;                       // erlaubt Nutzung des Namensraumes std
                                           //         nutze  cout  statt  std::cout
int main()                                 // Beginn Hauptprogramm
{                                          // Beginn Scope
 std::cout << "Hello World" << std::endl;
 return 0;                                 // Beende das Programm
}                                          // Ende Scope, Ende Hauptprogramm









