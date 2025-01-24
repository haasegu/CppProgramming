//	studenten.cpp

#include <iostream>
#include <cstring>
using namespace std;
#include "studenten.h"


// ---------------------------------------------------------------------

Studenten :: Studenten()
: _matrikel(0), _skz(0), _name(), _vorname()
{
}

// ---------------------------------------------------------------------

Studenten :: Studenten(const string& vorname, const string& name,
                       const long int  matrikel,   const int  skz)
: _matrikel(matrikel), _skz(skz), _name(name), _vorname(vorname)
{
}

// ---------------------------------------------------------------------

ostream & operator<<(ostream  & s, const Studenten & orig)
{
 return s << orig._vorname << " "   << orig._name << " , "
          << orig._matrikel << " , " << orig._skz;
}
// ---------------------------------------------------------------------

void Studenten :: Print(ostream  & s) const
{
  s << _vorname << " ";
  s <<    _name << " , ";
  s << _matrikel << " , " << _skz << endl;
  return;
}









