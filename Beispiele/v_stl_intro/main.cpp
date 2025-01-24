// Demo STL mit vector<double>

#include <iostream>
#include <algorithm>
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

//
bool fkt_abs_less(int a, int b)                            // Vergleichsfunktion
{
    return abs(a)<abs(b);
}

//
struct myclass
{
    bool operator() (int a, int b)  const                // Funktor
    {
        return abs(a)<abs(b);
    }
} funktor_abs_less;

int main()
{
    vector<int> v{-1,-3,4,-3,-5,-1,4};                  // C++11
    cout << v << endl;

// STL-Algorithmus mit Standardvergleich  operator<
    vector<int>::iterator it;
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
                      [](int a, int b) -> bool { return abs(a)<abs(b); }
                    );
    cout << "|max|: " << *it4 << endl;

    return 0;
}
