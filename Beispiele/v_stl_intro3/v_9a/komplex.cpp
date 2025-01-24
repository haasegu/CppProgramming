#include "komplex.h"

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

Komplex::~Komplex()
{
    //dtor
}

Komplex Komplex::operator+(const Komplex& rhs) const
{
    Komplex tmp(_re+rhs._re, _im+rhs._im);
    return tmp;
}

ostream& operator<<(ostream& s, const Komplex& rhs)
{
    s << "("<< rhs.Get_re()<< ","<<rhs.Get_im() <<")";
    return s;
}

Komplex operator+(double lhs, const Komplex& rhs)
{
//     Komplex tmp(lhs+rhs.Get_re(), rhs.Get_im());
//    return tmp;
   return rhs+lhs; // Ruft Methode operator+ der Klasse Komplex

}
