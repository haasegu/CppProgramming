//  g++ -std=c++11 -Wall -pedantic bsp752.cpp student.cpp

#include <iomanip>			// setw
#include <iostream>
#include <string>
using namespace std;

#include "student.h"

int main()
{
    Student arni;

    cout << endl << " Vorname           : ";
    cin >> arni.vorname;
    cout << endl << " Name              : ";
    cin >> arni.name;
    cout << endl << " Studentenkennzahl : ";
    cin >> arni.skz;
    cout << endl << " Matrikelnummer    : ";
    cin >> arni.matrikel;

    Student_Mult robbi;

    Copy_Student(robbi, arni);

    cout << endl << "-------- output -----------" << endl;
    cout << robbi.vorname << " "   << robbi.name     << ", SKZ: ";
    cout << robbi.skz[0]  << "   " << robbi.matrikel << endl << endl;

    return 0;
}









