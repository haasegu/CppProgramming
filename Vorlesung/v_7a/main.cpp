//   Klasse Student:
//      Output-Operator (friend); Mehrere Studien
#include "student.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Student gg("Tyson", "8956256215", 421);  // Parmeterkonstruktor

    cout << gg.Getname() <<endl;
    {
        const Student pp(gg);                               // Copy-Konstruktor
        cout << pp.Getname() <<endl;

//        cout << pp._name << endl;
    }  // impliziter Destruktoraufruf fuer pp



    cout << gg.Getmatr_nr();
    cout << "\n#######################\n";

    cout << "test 1: " << gg << endl;

    cout << "set new values for name and skz: ";
    cin >> gg;
    cout << "test 2: " << gg << endl;

    gg.Add_SKZ(112);
    cout << "test 3: " << gg << endl;
    gg.Del_SKZ(666);
    gg.Add_SKZ(112);       //  should not add 112 to the vector again

    cout << "test 4: " << gg << endl;

    gg.Del_SKZ(421);
    gg.Del_SKZ(112);
    cout << "test 5: " << gg << endl;


    return 0;
}
