#include "salesperson.h"
#include <iostream>
#include <string>
using namespace std;

salesPerson:: salesPerson(const string& name, float hours, float wageHour,
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
