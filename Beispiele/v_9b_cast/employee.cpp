#include "employee.h"

int Employee::_counter = 0; //!<  Der  e i n e   Zaehler fuer alle Instanzen wird definiert.

Employee::Employee(const string& name)
: _name(name)
{
    //ctor
    ++_counter;
}

Employee::~Employee()
{
    //dtor
    --_counter;
}


void Employee::print(ostream& s) const
{
    s << "Name: " << _name << endl;
    s << "Bezahlung: " << payment() << endl;
//                        Bei virtuellen Methoden wird hier zur Laufzeit
//                        via der VMT die konkrete Methode  Klasse::payment()
//                        aufgerufen.
}

ostream& operator<<(ostream &s, const Employee& org)
{
    org.print(s);
    return s;
}

