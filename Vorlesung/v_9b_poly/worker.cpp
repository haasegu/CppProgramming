#include "worker.h"
#include <iostream>
#include <string>
using namespace std;

Worker::Worker(const string& name, float hours, float wageHours)
: Employee(name), _hours(hours),_wageHours(wageHours)
{
    //ctor
}

Worker::~Worker()
{
    //dtor
}

void Worker::print(ostream& s) const
{
    Employee::print(s);
 //   s << "Lohn: " << payment() << endl;    // dank virtueller Methode payment() nicht mehr noetig
}
