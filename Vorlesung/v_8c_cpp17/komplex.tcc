//#include "komplex.h"

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
    return tmp+=rhs;
}

template <class T>
std::ostream& operator<<(std::ostream& s, const Komplex<T>& rhs)
{
    s << "("<< rhs.Get_re()<< ","<<rhs.Get_im() <<")";
    return s;
}

template <class T>
Komplex<T> operator+(T lhs, const Komplex<T>& rhs)
{
   return rhs+lhs; // Ruft Methode operator+ der Klasse Komplex

}
