#include "salesperson.h"

salesPerson:: salesPerson(const string& name, int hours, float wageHour,
                    float commission, float percent)
: Worker(name,hours,wageHour), _commission(commission),
 _percent(percent)
{
    //ctor
}

salesPerson::~salesPerson()
{
    //dtor
}

void salesPerson::print(ostream& s) const
{
    Worker::print(s);
 //   s << "Sales-Gehalt:" << payment() << endl;   // dank virtueller Methode payment() nicht mehr noetig
    s << "Prozent: " << _percent << endl;
}
