#include "komplex.h"
#include <cmath>
#include <iostream>

Komplex::Komplex(float re, float im)
: _re(re), _im(im)                     // member initializiation list
{
    //ctor
}

Komplex::~Komplex()
{
    //dtor
}


float Komplex::abs() const
{
    return std::sqrt( _re*_re + _im*_im );
}

Komplex Komplex::add(Komplex const &rhs) const
{
    float real = Get_re() + rhs.Get_re();
    float imag = Get_im() + rhs.Get_im();
    Komplex tmp(real,imag); // tmp = aktuelle Instanz
    return tmp;
}

Komplex Komplex::operator+(Komplex const &rhs) const  // operator +=
{
    float real = this->Get_re() + rhs.Get_re();
    float imag = _im + rhs.Get_im();
    Komplex tmp(real,imag); // tmp = aktuelle Instanz
    return tmp;
}

std::ostream& operator<<(std::ostream& s, Komplex const &rhs)
{
    s << "(" << rhs.Get_re() << "," << rhs.Get_im() << ")";
    return s;
}


