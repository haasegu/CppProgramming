//  Vorlesung: 11.April 2014,
//  Klasse Komplex
//    ohne automatisch, implizit generierte Methoden
//    mit Operator+
#include <iostream>
#include "komplex.h"
using namespace std;

int main()
{
    const Komplex a(3.2,-1.1); // Konstruktor Komplex(double,double)
    Komplex b(a);              // Kopierkonstruktur wird benoetigt
    Komplex c;                 // Konstruktor  Komplex()   wird benoetigt

    c = a+b;                   // OK: a.operator+(const Komplex&)
                               // Zuweisungsoperator:  c.operator+(const Komplex&)

    cout << a << endl;         // Ausgabeoperator: operator<<()  ist eine Funktion!
    cout << c << endl;

    double dd(-3.2);
                               // OK: a.operator+(const Komplex&)
    c = a + Komplex(dd,0.0);   // explizites Casting double --> Komplex
                               //            via Konstruktor Komplex(double)
    c = a + dd;                // implizites Casting via Konstruktor Komplex(double)
    cout << c << endl;

    c = dd+a;                  // Achtung: keine Methode operator+(const Komplex&)
                               //                        fuer double verfuegbar.
                               // Daher  Funktion  operator+(double, const Komplex&)  noetig
    cout << c << endl;

    return 0;
}                              // impliziter Destruktoraufruf
