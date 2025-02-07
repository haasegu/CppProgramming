//   Einfuehrung in die STL
//       Container, Algorithmen, Iteratoren
//
//    Demo mit vector<double>
//       copy
//       sort
//       find
//       remove, erase

//       sort mit Praedikatorfunktion, Funktionsobjekt
//       count
//       count_if
//
#include "komplex.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>
using namespace std;

//  Ausgabe von vector
template <class T>
ostream& operator<<(ostream& s, const vector<T>& x)
{
    for (unsigned int i=0; i<x.size(); ++i)
    {
        s << x[i] << "  ";
    }
    return s;
}


template <class T>
ostream& operator<<(ostream& s, const list<T>& x)
{
//    for (const auto &pi: x)
//    {
//        s << pi << "  ";
//    }
    copy(x.cbegin(), x.cend(), ostream_iterator<T>(s, "  "));
    return s;
}

//  binaere Praedikatorfunktionen
bool IsLarger (double i,double j);

bool IsLarger (double i,double j)
{
    return (i>j);
}

bool IsLargerAbs (double i,double j);

bool IsLargerAbs (double i,double j)
{
    return std::abs(i)>std::abs(j);
}

//  unaere Praedikatorfunktionen
bool IsNegative(double i);

bool IsNegative(double i)
{
    return i<0;
}

int main()
{
    cout << "Hello world!" << endl;

// Demo STL mit vector<double>
    vector<double> v{-1,-3,-3,4,-1,4};
    cout << v << endl;

    // kopiere
    vector<double> z;
    // vorher den Speicher fuer den Zielvektor anfordern !!
//  Variante 1 (exakte Preallokierung von z)
    z.resize(v.size());
    copy(v.begin(),v.end(),z.begin());
//  Variante 2 (ueberschaetzte Preallokierung von z)
//    z.resize(2*v.size());
//    auto it_1 = copy(v.begin(),v.end(),z.begin());
//    z.erase(it_1,z.end());
    cout << z << endl;

    // Finden
//     vector<double>::iterator it;
//     it = find(v.begin(),v.end(),4);
    auto it = find(v.begin(),v.end(),4);
    if (it != v.end())    // wirklich etwas gefunden ?
    {
        cout << "gefunden " << *it << endl;
    }
    cout << it - v.begin() << endl;   // Index (nur bei vector)

    sort(v.begin(),v.end());
    cout << " sort (aufsteigend)  " << v << endl;
    //   Entferne alle mehrfachen Elemente hintereinander
    it = unique(v.begin(),v.end());      // nach vorn schieben
    cout << v << endl;
    cout << it - v.begin() << endl;   // Index (nur bei vector)
//   Wirkliches Entfernen aus dem Vektor
    v.erase(it,v.end());
    cout << v << endl;

//   absteigend sortieren
    sort(v.begin(),v.end(),greater<double>());   // Erfordert  double::operator>
    sort(v.begin(),v.end(),IsLarger);            // binaere Praedikatorfunktion
    sort(v.begin(),v.end(), [](auto a, auto b){return a>b;} );  // dasselbe via Lambda-Fkt
    cout << v << endl;

// Finde das erste negative element
    auto ip = find_if(v.begin(),v.end(),IsNegative);
    cout << "erste negative Zahl: " << *ip << endl;

//  Desgleichen via Lambda-Funktion [C++11]
    auto ip2 = find_if(v.begin(),v.end(),
                      [](double a) -> bool { return a<0.0; }
                      );
    cout << "erste negative Zahl: " << *ip2 << endl;

    // Zaehlen von Elemente
    int p = count(z.begin(),z.end(),-3);
    cout << " z : " << z << endl;
    cout << "p(-3) :" << p << endl;
    p = count_if(z.begin(),z.end(),IsNegative);
    cout << "p(neg.) :" << p << endl;

    cout << "#############################################\n";

// Demo STL mit vector<Komplex>
    vector<Komplex> kv{Komplex(1,3), Komplex(2,5), Komplex(-1,3), Komplex(1,4),Komplex(1,3), Komplex(1,3) };
    const vector<Komplex> kz(kv);
    cout << kv << endl;

    sort(kv.begin(),kv.end());    // braucht: Komplex::operator<  und Komplex::operator=
    cout << kv << endl;

    auto ik=find(kv.begin(),kv.end(), Komplex(1,4));   // braucht: Komplex::operator==
    if (ik != kv.end())    // wirklich etwas gefunden ?
    {
        cout << "gefunden " << *ik << endl;
    }

    // Anzahl der Elemente mit |re| < 2;
    double const vergl=2.0;
    int n2 = count_if(cbegin(kv),cend(kv),
                 [vergl] (auto const &a) {return std::abs(a.Get_re())<vergl;}
                 );
    cout << "|re| < 2 in  " << n2 << " Elementen." << endl;


    cout << "-------- jetzt Liste -----------\n";
    list<Komplex> al(kz.begin(),kz.end()); // Allokiere und kopiere von unsortiertem Vector
    //list<Komplex> al;               // leere Liste
    //al.assign(kz.begin(),kz.end()); // Allokiere und kopiere von unsortiertem Vector
    cout << al << endl;
    al.sort();                      // braucht: Komplex::operator<  und Komplex::operator=
    cout << al << endl;
    
    // Finde einen Eintrag mit Imaginärteil==3, via Lambda-Funktion
    double fim{3.0};
    list<Komplex> ip_al = find(cbegin(al),cend(al), 
                               [const fim](Komplex const & a)
                               { return fim==a.Get_im(); }
                               );


    return 0;
}
