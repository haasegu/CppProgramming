// Demo STL mit vector<double> advanced

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
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

//  Ausgabe von list
template <class T>
ostream& operator<<(ostream& s, const list<T>& x)
{
    for (auto px: x )                   // C++11: range-for
    {
        s << px << "  ";
    }
    return s;
}


//
/** @brief Ueberprueft, ob @p b nichtnegativ ist
*
* @param [in] b  ganze Zahl
* @return true falls b>=0
*
*/
bool IsNotNegative (const int b);                                  // Deklaration
bool IsNotNegative (const int b) { return b>0; }

//! @brief Prueft ob @p |x| kleiner als @p |y| ist.
//!
//! @param [in] x ganze Zahl
//! @param [in] y ganze Zahl
//! @return  true falls |x| < |y|
//!
//!
bool AbsLess(const int x, const int y);
bool AbsLess(const int x, const int y)                           // fuer g)
{
    return abs(x) < abs(y);
}

int main()
{
    vector<int>  v{-1,-3,4,-3,-5,-1,4};                  // C++11
    cout << v << endl;

// b)                             //   Copy
    cout << "--- Kopieren --" << endl;

    vector<int> b(v.size());                   // reserve enough space for b !!
    copy(v.cbegin(),v.cend(),b.begin());
    cout << b << endl;

// c)                             // sort
    cout << "--- Sortieren --" << endl;
    sort(b.begin(), b.end());         //  operator<   is needed
    cout << b << endl;


// d)                             // unique
    cout << "--- unique on  s o r t e d  container--" << endl;
    vector<int>::iterator it;
    it=unique (b.begin(), b.end());          //  operator==   is needed
    b.erase(it,b.end());                     //  Vektor kuerzen
    b.shrink_to_fit();                       //  C++11
    cout << b << endl;

// e)
    cout << "--- copy remove --" << endl;
    vector<int> c(b.size());
    it=copy_if (b.cbegin(),b.cend(),c.begin(), IsNotNegative);
    c.erase(it,c.end());                    //  Vektor kuerzen
    c.shrink_to_fit();                      //  C++11
    cout << c << endl;

// f)
    cout << "--- max/min --" << endl;
    it = max_element(v.begin(),v.end());
    cout << "max: " << *it << endl;
    it = min_element(v.begin(),v.end());
    cout << "min: " << *it << endl;

// g)
    cout <<v << endl;
    cout << "--- max/min|| --" << endl;
    it = max_element(v.begin(),v.end(),AbsLess);   // a < b needed in AbsLess
    cout << "max||: " << *it << endl;
    v.erase(it);
    it = min_element(v.begin(),v.end(),AbsLess);     // a < b needed in AbsLess
    cout << "min||: " << *it << endl;
    v.erase(it);
    cout << v << endl;

// h)
    cout << "--- c absteigend sortieren --" << endl;
//    sort(c.begin(), c.end(),IsGreater);             // via Boolesche Funktion
    sort(c.begin(), c.end(),greater<int>());          // via int::operator>

    cout << c << endl;

// i)
    cout << "--- zaehlen --" << endl;
    const int nc = count(v.cbegin(), v.cend(), -3 );
    cout << nc << " mal '-3'  gefunden" << endl;


//##########  jetzt mit list #########################
    cout << "\n  #############  list  ############\n\n";

    list<int> lv{-1,-3,4,-3,-5,-1,4};                  // C++11
    cout << lv << endl;

// b)                             //   Copy
    cout << "--- Kopieren --" << endl;

    list<int> lb(lv.size());      // reserve enough space for lb !!
    copy(lv.cbegin(),lv.cend(),lb.begin());
    cout << lb << endl;

// c)                             // sort
    cout << "--- Sortieren --" << endl;
//    sort(lb.begin(), lb.end()); //  not for list !!
    lb.sort();                    //  operator<   is needed
    cout << lb << endl;


// d)                             // unique
    cout << "--- unique on  s o r t e d  container--" << endl;
    list<int>::iterator lit;
    lit=unique (lb.begin(), lb.end());      //  operator==   is needed
    lb.erase(lit,lb.cend());                //  Liste kuerzen
//    lb.shrink_to_fit();                   //  not for list !!
    cout << lb << endl;

// e)
    cout << "--- copy remove --" << endl;
    list<int> lc(lb.size());
    lit=copy_if (lb.cbegin(),lb.cend(),lc.begin(), IsNotNegative);
    lc.erase( lit,lc.cend() );             //  Liste kuerzen
    cout << lc << endl;

// f)
    cout << "--- max/min --" << endl;
    lit = max_element(lv.begin(),lv.end());
    cout << "max: " << *lit << endl;
    lit = min_element(lv.begin(),lv.end());
    cout << "min: " << *lit << endl;

// g)
    cout <<v << endl;
    cout << "--- max/min|| --" << endl;
    it = max_element(v.begin(),v.end(),AbsLess);   // a < b needed in AbsLess
    cout << "max||: " << *it << endl;
    v.erase(it);
    it = min_element(v.begin(),v.end(),AbsLess);     // a < b needed in AbsLess
    cout << "min||: " << *it << endl;
    v.erase(it);
    cout << lv << endl;

// h)
    cout << "--- c absteigend sortieren --" << endl;
    lc.sort(greater<int>());          // via int::operator>

    cout << lc << endl;

// i)
    cout << "--- zaehlen --" << endl;
    const int lnc = count(lv.cbegin(), lv.cend(), -3 );
    cout << lnc << " mal '-3'  gefunden" << endl;


    return 0;
}
