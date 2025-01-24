// Demo STL mit vector<komplex>

#include <iostream>
#include <algorithm>
#include <vector>
#include "komplex.h"
using namespace std;


//  Ausgabe von vector
template <class T>
ostream& operator<<(ostream& s, const vector<T>& x)
{
    for (size_t i=0; i<x.size(); ++i)
    {
        s << x[i] << "  ";
    }
    return s;
}

//
bool fkt_abs_less(const Komplex& a, const Komplex& b)      // Vergleichsfunktion
{
    return abs(a)<abs(b);
}

//
struct myclass
{
    bool operator() (const Komplex& a, const Komplex& b) const  // Funktor
    {
        return abs(a)<abs(b);
    }
} funktor_abs_less;

int main()
{
    vector<Komplex> v{-1,-3,4,-3,-5,-1,4};              // C++11
    cout << v << endl;

// STL-Algorithmus mit Standardvergleich  operator<
    vector<Komplex>::iterator it;
    it = max_element(v.begin(),v.end());                   // int::operator<
    cout << " max : " << *it << endl;
//  ...
//############################################################
// Jetzt das betragsmaessig groesste Element

// STL-Algorithmus mit Vergleichsfunktion
    auto it2 = max_element(v.cbegin(),v.cend(), fkt_abs_less);     // function
    cout << "|max|: " << *it2 << endl;

// STL-Algorithmus mit Vergleichsfunktion
    auto it3 = max_element(v.cbegin(),v.cend(), funktor_abs_less); // functor
    cout << "|max|: " << *it3 << endl;

// STL-Algorithmus mit Lambda-Funktion
    auto it4 = max_element(v.cbegin(),v.cend(),                    // C++11: lambda-function
                      [](const Komplex& a, const Komplex& b) -> bool { return abs(a)<abs(b); }
                    );
    cout << "|max|: " << *it4 << endl;

    return 0;
}
