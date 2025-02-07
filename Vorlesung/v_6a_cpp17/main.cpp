//  Klasse Komplex
//    ohne automatisch, implizit generierte Methoden
//    mit Operator+
#include "komplex.h"
#include <algorithm>   // sort
#include <iostream>
#include <vector>
using namespace std;

//#define PRINT(x)  #x << " : " << v

/** Ausgabeoperator fuer die Vektor Komplex.
 * \param[in] s  ein beliebiger Ausgabestrom
 * \param[in] rhs  auszugebender Vektor
 * \return Ausgabestrom
 */
std::ostream& operator<<(std::ostream& s, const std::vector<Komplex>& rhs);

int main()
{
    const Komplex a(3.2,-1.1), b(4,-1); // Konstruktor Komplex(double,double)
    Komplex c;           //  Konstruktor  Komplex()   wird benoetigt

    c = a+b;             // OK: a.operator+(const Komplex&)

    cout << a << endl;   // Ausgabeoperator
    cout << c << endl;

    double dd(-3.2);
    // OK: a.operator+(const Komplex&)
    c = a + Komplex(dd,0.0);//  explizites Casting double --> Komplex durch Konstruktor Komplex(double)
    c = a + dd;             //  implizites Casting durch Konstruktor Komplex(double)
    cout << c << endl;

    c = dd+a;               // Achtung: keine Methode operator+(const Komplex&)
                            //          fuer double verfuegbar.
                            // Daher  Funktion  operator+(double, const Komplex&)  noetig
    cout << c << endl;

    //------------------------------------------------------------------
    vector<Komplex> v{ {-1,2.0}, {3.0}, {0.0, -4}, {1,1} };
    cout << "original         " << v << endl;
    //cout << PRINT(v) << endl;

    sort(v.begin(),v.end());          // Komplex:operator<()
    cout << "nach operator<() " << v << endl;

    sort(v.begin(),v.end(),          // Lambda-Funktion
        [](Komplex const &lhs, Komplex const &rhs) -> bool
          { return lhs.abs()<rhs.abs(); }
    );
    cout << "nach lambda-Fkt. " << v << endl;



    return 0;
}

ostream& operator<<(ostream& s, const vector<Komplex>& rhs)
{
    for (auto const &vk: rhs )
    {
        s << vk << "  ";
    }
    return s;
}
