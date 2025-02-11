// C++ Vorlesung 2. Juni 2012
// Klassenhierarche  mit virtuellen Methoden

// v_10a --> v_10b
// T h e  O n l y   c h a n g e s: Marking methods classname() and verbrauch() in Fahrzeug  as virtual

/*
 g++ -pedantic -std=c++11 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized *.cpp
 cppcheck --enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem *.cpp
 clang++ -std=c++11 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic *.cpp
 clang++ -std=c++11 -Weverything *.cpp
 clang++ -cc1 --help
*/

#include "fahrzeug.h"
#include <iostream>
#include <typeinfo>       // operator typeid
using namespace std;

/** \brief Prints some info from a vehicle
 * \param[in]   p   a general vehicle
 */

void PrintInfo(const Fahrzeug& p);



int main()
{
    cout << "Hello world!" << endl;

    Fahrzeug a(1768);
    cout << a.classname() << endl;
    //cout <<typeid(a).name() << endl;

    LKW b(2500, 3100);
    cout << b.classname() << "  "<< b.Get_load() << endl;
    //cout <<typeid(b).name() << endl;

    PKW c(1459, 3);
    cout << c.classname()  << "  "<< c.Get_pass() << endl;

    MAN l1(7500, 10100);
    Raba l2 (3500, 4000);

    Opel p1(1450);
    Smart p2 (1100);

    //
    PrintInfo(a);      // basis class ==> correct information is printed
    PrintInfo(p1);     // derived class ==> correct information is printed, because of virtual methods!!

    return 0;
}


void PrintInfo(const Fahrzeug& p)
{
   cout << p.classname() << " : " << p.Get_kg() << " kg   and "
        << p.verbrauch() << " l/100km" << endl;
}
