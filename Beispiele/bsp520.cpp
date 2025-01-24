//	Sec. 5.2 of lecture
//	Structure

#include <iostream>
#include <string>                       // class string
using namespace std;

struct Student {                        // new structure
    Student(): matrikel(), skz(), name(), vorname() {}
    long long int matrikel;
    int skz;
    string name, vorname;
};

int main()
{
    Student arni, robbi;                // Variable of type Student

    cout << endl << " Vorname : ";
    cin >> arni.vorname;                // Data input
    cout << endl << " Familienname : ";
//                 ...
    cin >> arni.name;
    cout << endl << " Studentenkennzahl : ";
    cin >> arni.skz;
    cout << endl << " Matrikelnummer    : ";
    cin >> arni.matrikel;

    robbi = arni;                       // Copy (!! shallow copy vs. deep copy !!)

//				output
    cout << endl << "-----------------------------------" << endl;
    cout << robbi.vorname << " "   << robbi.name    << ", SKZ: ";
    cout << robbi.skz     << "   " << robbi.matrikel << endl << endl;

    return 0;
}









