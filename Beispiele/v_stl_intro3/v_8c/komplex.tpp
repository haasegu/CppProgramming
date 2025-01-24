#include "komplex.h"

template <class T>
Komplex<T>::Komplex()
: _re(0.0), _im(0.0)
{
    //ctor
}

template <class T>
Komplex<T>::Komplex(T re, T im)
: _re(re), _im(im)
{
    //ctor
}

template <class T>
Komplex<T>::~Komplex()
{
    //dtor
}

template <class T>
Komplex<T>& Komplex<T>::operator+=(const Komplex<T>& rhs)
{
    _re += rhs._re;
    _im += rhs._im;
    return *this;    // this ist ein Pointer auf die aktuelle Instanz
}

template <class T>
Komplex<T> Komplex<T>::operator+(const Komplex<T>& rhs) const
{
    Komplex<T> tmp(*this);
//    tmp += rhs;
//    return tmp;
    return tmp+=rhs;
}

template <class T>
ostream& operator<<(ostream& s, const Komplex<T>& rhs)
{
    s << "("<< rhs.Get_re()<< ","<<rhs.Get_im() <<")";
    return s;
}

template <class T>
Komplex<T> operator+(T lhs, const Komplex<T>& rhs)
{
//     Komplex tmp(lhs+rhs.Get_re(), rhs.Get_im());
//    return tmp;
   return rhs+lhs; // Ruft Methode operator+ der Klasse Komplex

}
