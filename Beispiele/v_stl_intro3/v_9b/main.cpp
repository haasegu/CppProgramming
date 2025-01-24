//     Vorlesung: 06.06.2014
//     Klassenhierarchie:
//                    Employee
//             Manager         Worker
//                             SalesPerson

#include <iostream>
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "salesperson.h"
using namespace std;


ostream& operator<<(ostream &s, const Employee& org);     // Deklaration

ostream& operator<<(ostream &s, const Employee& org)      // Definition
{
    org.print(s);
    return s;
}

int main()
{
    cout << "Hello world!" << endl;

    //Employee aa("Angestellter");       // rein virtuelle Methode payment()
                                         // ==> abstrakte Basisklasse Employee
                                         // ==> keine Instanz von Employee mehr moeglich
    Worker bb("Hugo", 160, 15.50f);
    salesPerson cc("Wanda", 80, 10.2f, 10000, 0.05f);
    manager dd("Brenda", 2000);
    //aa.print(cout);                    // nicht mehr moeglich, da Employee abstrakte Basisklasse ist
    bb.print(cout);
    cout << "##########  " << dd.get_Counter() <<"  ###########\n";
    cc.print(cout);
    dd.print(cout);

    cout << "----------------\n" << dd << endl;


    return 0;
}
