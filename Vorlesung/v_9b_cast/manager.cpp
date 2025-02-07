#include "manager.h"
#include <iostream>
#include <string>
using namespace std;

manager::manager(const string& name, float wageWeek)
: Employee(name), _wageWeek(wageWeek)
{
    //ctor
}

manager::~manager()
{
    //dtor
}


void manager::print(ostream& s) const
{
    Employee::print(s);
 //   s << "Wochenlohn: " << _wageWeek << endl;   // dank virtueller Methode payment() nicht mehr noetig
}
