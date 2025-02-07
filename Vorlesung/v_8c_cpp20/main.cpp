//  Klasse Komplex wird erweitert; Templates
//    operator+ wird aus operator += abgeleitet
//    Vergleichsoperatoren:  < , ==  und daraus abgeleitet  >
//    ( nur zur Demo:  Vergleichsoperatoren fuer komplexe Zahlen sind nicht transitiv !!)
//#include "komplex.h"
#include "komplex2.h"
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
    const Komplex<double> a(3.2, -1.1); // Konstruktor Komplex(double,double)
    const Komplex<double> b(4, -1);     // Konstruktor Komplex(double,double)
    Komplex<double> c;                  // Konstruktor  Komplex()   wird benoetigt

    c = a + b;           // OK: a.operator+(const Komplex&)

    cout << a << endl;   // Ausgabeoperator
    cout << c << endl;

    Komplex<double> dd(-3.2);
    dd += a;                        // OK: a.operator+(const Komplex&)
    cout << dd << endl;

    cout << (dd < a) << endl;
    cout << (dd == a) << endl;
    cout << (dd > a) << endl;

    vector<Komplex<float>> vv = { {3.0F, -1.0F}, {3.0F, -3.0F}, {1.2F, -4.F}, {4.3F, -1.F} };
    cout << "vv : " << vv << endl;
    sort(vv.begin(), vv.end());    // requires operator<, ans operator= (for vector-container)
    cout << "vv : " << vv << endl;

    sort(vv.begin(), vv.end(), islargerequal<Komplex<float>>);
    cout << "vv : " << vv << endl;

    // order wrt. abs(), with lambda function
    sort(vv.begin(), vv.end(),                          //islargerequal<Komplex<float>>
         [] (auto const &aa, auto const &bb) -> bool
             { return abs(aa) < abs(bb); }
        );
    cout << "vv: abs : " << vv << endl;


    auto it = find(vv.begin(), vv.end(), Komplex<float>(1.22F, -4.0F) );
    if (it != vv.end()) {cout << " found " << *it << endl;}

    Komplex<long double> lda(1.22L, -4.0L); cout << lda << endl;
    //Komplex<int> ia(-1,2); cout << ia << endl;

    // https://stackoverflow.com/questions/53557649/how-do-i-check-for-c20-support-what-is-the-value-of-cplusplus-for-c20
    #if __cplusplus >= 202002L
       cout << " C++20 support" << endl;
    #else
       cout << " C++ version: " << __cplusplus << endl;
    #endif
    
//    Komplex<string> hh("n","a");


    return 0;
}
