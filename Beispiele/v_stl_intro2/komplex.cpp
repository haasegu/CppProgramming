#include <iostream>
using namespace std;
#include "komplex.h"

// Methoden der Klasse Komplex

Komplex::Komplex()
    : _re(0.0), _im(0.0)
{
    //ctor
}

Komplex::Komplex(double re, double im)
    : _re(re), _im(im)
{
    //ctor
}

Komplex::Komplex(const Komplex& org)
    : _re(org._re), _im(org._im)
{

}

Komplex::~Komplex()
{
    //dtor
}

Komplex& Komplex::operator=(const Komplex& rhs)       // Assignment operator
{
    if ( this!=&rhs)              // Avoids self-assignment (critical with dynnamic memory)
    {
        _re = rhs._re;
        _im = rhs._im;
    }
    return *this;
}

Komplex Komplex::operator+(const Komplex& rhs) const
{
    Komplex tmp(_re+rhs._re, _im+rhs._im);
    return tmp;
}


bool Komplex::operator<(const Komplex& rhs) const
{
    return (_re<rhs._re) || ( _re==rhs._re && _im<rhs._im );
}


bool Komplex::operator==(const Komplex& rhs) const
{
    return _re==rhs._re && _im==rhs._im ;
}

//   Ende: Methoden der Klasse Komplex
// -------------------------------------------------------------------------
//   Funktionen, welche die Klasse Komplex als Datentyp benutzen

ostream& operator<<(ostream& s, const Komplex& rhs)
{
    s << "("<< rhs.Get_re()<< ","<<rhs.Get_im() <<")";
    return s;
}

Komplex operator+(double lhs, const Komplex& rhs)
{
//     Komplex tmp(lhs+rhs.Get_re(), rhs.Get_im());
//    return tmp;
    return rhs+lhs; // Ruft Methode operator+ der Klasse Komplex: rhs.operator(lhs)
}

