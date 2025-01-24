//   Vorlesung 29. Mai 2015
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
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <cmath>
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
    for (auto pi: x)
    {
        s << pi << "  ";
    }
    return s;
}

//  Praedikatorfunktionen
bool IsLarger (double i,double j)
{
    return (i>j);
}
bool IsLargerAbs (double i,double j)
{
    return std::abs(i)>std::abs(j);
}
bool IsNegative(double i)
{
    return i<0;
}

int main()
{
    cout << "Hello world!" << endl;

// Demo STL mit vector<double>
    vector<double> v = {-1,-3,-3,4,-1,4}, z;
    cout << v << endl;

    // kopiere
    // vorher den Speicher fuer den Zielvektor anfordern !!
    z.resize(v.size());
    copy(v.begin(),v.end(),z.begin());


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
//    sort(v.begin(),v.end(),IsLarger);
    sort(v.begin(),v.end(),greater<double>());   // Erfordert  double::operator>
    cout << v << endl;

// Finde das erste negative element
    auto ip = find_if(v.begin(),v.end(),IsNegative);
    cout << "erste negative Zahl: " << *ip << endl;

    // Zaehlen von Elemente
    int p = count(z.begin(),z.end(),-3);
    cout << " z : " << z << endl;
    cout << "p(-3) :" << p << endl;
    p = count_if(z.begin(),z.end(),IsNegative);
    cout << "p(neg.) :" << p << endl;

    cout << "#############################################\n";

// Demo STL mit vector<Komplex>
    vector<Komplex> kv = {Komplex(1,3), Komplex(2,5), Komplex(-1,3), Komplex(1,4),Komplex(1,3), Komplex(1,3) };
    const vector<Komplex> kz(kv);
    cout << kv << endl;

    sort(kv.begin(),kv.end());    // braucht: Komplex::operator<  und Komplex::operator=
    cout << kv << endl;

    auto ik=find(kv.begin(),kv.end(), Komplex(1,4));   // braucht: Komplex::operator==
    if (ik != kv.end())    // wirklich etwas gefunden ?
    {
        cout << "gefunden " << *ik << endl;
    }

    cout << "-------- jetzt Liste -----------\n";
    list<Komplex> al;               // jetzt mit einer Liste
    al.assign(kz.begin(),kz.end()); // Kopiere von unsortiertem Vector
    cout << al << endl;
    al.sort();                      // braucht: Komplex::operator<  und Komplex::operator=
    cout << al << endl;

    return 0;
}
