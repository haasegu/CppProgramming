#include "komplex.h"
#include <iostream>
#include <vector>
using namespace std;

// Methoden der Klasse Komplex

Komplex::Komplex()
    : Komplex(0.0,0.0)                   // constructor forwarding
{}

Komplex::Komplex(double re, double im)
    : _re(re), _im(im)
{}

Komplex& Komplex::operator+=(const Komplex& rhs)
{
    _re += rhs._re;
    _im += rhs._im;
    return *this;
}

//   Ende: Methoden der Klasse Komplex
// -------------------------------------------------------------------------
//   Funktionen, welche die Klasse Komplex als Datentyp benutzen

ostream& operator<<(ostream& s, const Komplex& rhs)
{
    s << "("<< rhs.Get_re()<< ","<<rhs.Get_im() <<")";
    return s;
}

istream& operator>>(istream& s, Komplex& rhs)
{
    double a,b;
    s >> a >> b;
    rhs = Komplex(a,b);
    return s;
}

