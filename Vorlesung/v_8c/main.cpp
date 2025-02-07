//  Klasse Komplex wird erweitert; Templates
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
ostream  &operator<<(ostream &s, const vector<T> &v)
{
//     for (auto it=v.begin(); it!=v.end; ++it)  cout << *it << "  ";
    copy(v.begin(), v.end(), ostream_iterator<T, char>(s, "  "));
    return s;
}

template <class T>
bool islargerequal(T a, T b)
{
    return !(a < b);
}

int main()
{
    const Komplex<double> a(3.2, -1.1), b(4, -1); // Konstruktor Komplex(double,double)
    Komplex<double> c;           //  Konstruktor  Komplex()   wird benoetigt

    c = a + b;           // OK: a.operator+(const Komplex&)

    cout << a << endl;   // Ausgabeoperator
    cout << c << endl;

    Komplex<double> dd(-3.2);
    dd += a;                        // OK: a.operator+(const Komplex&)
    cout << dd << endl;

    cout << (dd < a) << endl;
    cout << (dd == a) << endl;
    cout << (dd > a) << endl;

    vector<Komplex<float>> vv = { {3.0f, -1.0f}, {3.0f, -3.0f}, {1.2f, -4.f}, {4.3f, -1.f} };
    cout << "vv : " << vv << endl;
    sort(vv.begin(), vv.end());    // requires operator<, ans operator= (for vector-container)
    cout << "vv : " << vv << endl;

    sort(vv.begin(), vv.end(), islargerequal<Komplex<float>>);
    cout << "vv : " << vv << endl;

    // order wrt. abs(), with lambda function
    sort(vv.begin(), vv.end(), //islargerequal<Komplex<float>>
         [] (const Komplex<float> &aa, const Komplex<float> &bb) -> bool
             { return abs(aa) < abs(bb); }
        );
    cout << "vv: abs : " << vv << endl;


    auto it = find(vv.begin(), vv.end(), Komplex<float>(1.22f, -4.0f) );
    if (it != vv.end()) cout << " found " << *it << endl;

    //
//    cout << "Komplex with string members: ";
//    Komplex<string> ss("Real","Imag");
//    cout << ss << endl;
////    cout << "|ss|" << abs(ss) << endl;

    return 0;
}
