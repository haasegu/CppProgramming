//  Klasse Komplex
//    ohne automatisch, implizit generierte Methoden
//    mit Operator+
#include "komplex.h"
#include <iostream>
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

    return 0;
}
