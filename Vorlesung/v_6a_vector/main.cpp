//  Klasse Komplex
//    ohne automatisch, implizit generierte Methoden
//    mit Operator+
//    mit vector<Komplex>
#include "komplex.h"
#include <iostream>
#include <vector>

/** Ausgabeoperator fuer die vector<Komplex>.
 * \param[in] s  ein beliebiger Ausgabestrom
 * \param[in] rhs  der auszugebende Vektor
 * \return Ausgabestrom
 */
std::ostream& operator<<(std::ostream& s, std::vector<Komplex> const &rhs);

using namespace std;

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

    // Demo Eingabeoperator;
    Komplex tin;
    cout << "Eingabe Realteil 'Leerzeichen' Imaginaerteil: ";
    cin >> tin;
    cout << "tin = " << tin << endl;

    //  neuer Teil bzgl. vector
    vector<Komplex>   vv(4);

    cout << "vv = " << vv << endl;

    vector<Komplex>  tt{ {3,4},{-1.2,4.3} };       // OK: C++17
//    vector<Komplex>  tt{ (3,4),(-1.2,4.3) };       // funktioniert nicht korrekt
//    vector<Komplex>  tt{ Komplex(3,4), Komplex(-1.2,4.3) };   // OK
    cout << "tt = " << tt << endl;

    return 0;
}


ostream& operator<<(ostream& s, vector<Komplex> const &rhs)
{
    for (auto const &val: rhs)
    {
        s << val << "  ";
    }
    return s;
}
