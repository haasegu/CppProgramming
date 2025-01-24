//	Sec. 5.2 of lecture
//	Structure

#include <iostream>
#include <string>                       // class string
#include <vector>
using namespace std;

struct Student_Mult{                    // new structure
    Student_Mult(): matrikel(0), skz(0), name(), vorname() {}
    long long int matrikel;
    vector<int> skz;                    // dynamic vector
    string name, vorname;
};

int main()
{
    Student_Mult arni, robbi;          // Variable of type Student
//      ...
    cout << endl << " Vorname : ";
    cin >> arni.vorname;
    cout << endl << " Familienname : ";
    cin >> arni.name;                   // Data input
    cout << endl << " # skz : ";
    int n_skz;
    cin >> n_skz;
    for (int i = 0; i < n_skz; ++i) {
        cout << endl << " Studentenkennzahl : ";
        int tmp; cin >> tmp;
        arni.skz.push_back(tmp);        // append new number to dynamic vector
    }
    cout << endl << " Matrikelnummer    : ";
    cin >> arni.matrikel;

    robbi = arni;

//				output
    cout << endl << "-----------------------------------" << endl;
    cout << robbi.vorname << " "   << robbi.name    << "   "<< robbi.matrikel << ", SKZ: ";
    for (size_t i = 0; i < robbi.skz.size(); ++i) {
        cout << robbi.skz[i] << "   ";
    }
    return 0;
}









