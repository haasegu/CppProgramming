#include "manager.h"

manager::manager(const string& name, float wageWeek)
: Employee(name), _wageWeek(wageWeek)
{
    //ctor
}

manager::~manager()
{
    //dtor
}

//void manager::Print() const
//{
//    cout << "Name: " << Get_name() << endl;
//    cout << "Wochenlohn: " << _wageWeek << endl;
//}

void manager::print(ostream& s) const
{
    Employee::print(s);
 //   s << "Wochenlohn: " << _wageWeek << endl;   // dank virtueller Methode payment() nicht mehr noetig
}
