//     Vorlesung: 19.06.2017
//     Klassenhierarchie:
//                    Employee
//             Manager         Worker
//                             SalesPerson

#include "employee.h"
#include "manager.h"
#include "salesperson.h"
#include "worker.h"

#include <iostream>
using namespace std;


ostream& operator<<(ostream &s, const Employee& org);     // Deklaration

ostream& operator<<(ostream &s, const Employee& org)      // Definition
{
    org.print(s);
    return s;
}

void printPayment(const Employee& org);
void printPayment(const Employee& org)
{
    cout << "         LOHN : " << org.payment() << endl;
}

int main()
{
    cout << "Hello world!" << endl;

    //Employee aa("Angestellter");       // rein virtuelle Methode payment()
                                         // ==> abstrakte Basisklasse Employee
                                         // ==> keine Instanz von Employee mehr moeglich
    Worker bb("Hugo", 160, 15.50);
    salesPerson cc("Wanda", 80, 10.2f, 10000, 0.05f);
    manager dd("Brenda", 2000);
    //cout << aa;                    // nicht mehr moeglich, da Employee abstrakte Basisklasse ist
    cout << bb;
    cout << "##########  " << dd.get_Counter() <<"  ###########\n";
    cout << cc;
    cout << "----------------\n" << dd << endl;

    printPayment(bb);
    printPayment(cc);
    printPayment(dd);

    return 0;
}
