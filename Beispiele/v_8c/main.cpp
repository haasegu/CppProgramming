//  Vorlesung: 9..Mai 2014,
//  Klasse Komplex wird erweitert
//    operator+ wird aus operator += abgeleitet
//    Vergleichsoperatoren:  < , ==  und daraus abgeleitet  >
//    ( nur zur Demo:  Vergleichsoperatoren fuer komplexe Zahlen sind nicht transitiv !!)
#include "komplex.h"
#include <algorithm>          // copy, sort
#include <iostream>
#include <iterator>           // ostream_iterator
#include <vector>
using namespace std;

template <class T>
ostream&  operator<<(ostream& s, const vector<T>& v)
{
//     for (auto it=v.begin(); it!=v.end; ++it)  cout << *it << "  ";
    copy(v.begin(),v.end(), ostream_iterator<T,char>(s,"  "));
    return s;
}

int main()
{
    const Komplex<double> a(3.2,-1.1), b(4,-1); // Konstruktor Komplex(double,double)
    Komplex<double> c;           //  Konstruktor  Komplex()   wird benoetigt

    c = a+b;             // OK: a.operator+(const Komplex&)

    cout << a << endl;   // Ausgabeoperator
    cout << c << endl;

    Komplex<double> dd(-3.2);
    dd += a;                        // OK: a.operator+(const Komplex&)
    cout << dd << endl;

    cout << (dd<a) << endl;
    cout << (dd==a) << endl;
    cout << (dd>a) << endl;

    vector<Komplex<float>> vv= { {3.0F,-1.0F}, {3.0F,-3.0F}, {1.2F, -4.0F}, {4.3F, -1.0F} };
    cout << "vv : " << vv << endl;
    sort(vv.begin(),vv.end());     // requires operator<, ans operator= (for vector-container)
    cout << "vv : " << vv << endl;

    return 0;
}
