// C++ Vorlesung  8. Juni 2018
// Klassenhierarche  mit virtuellen Methoden
// Nutzung des Polymorphismus via unique_ptr
// STL: sorting and accumulate as examples
//      !! now we have a

// 10c --> 10c_unique: use unique_ptr instead of C-pointer
// fahrzeug.cpp, fahrzeug.h  are mostly unchanged. Changes regarding warning messages from compilers etc.

/*
 g++ -pedantic -std=c++14 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized *.cpp
 cppcheck --enable=all --inconclusive --std=c++14 --std=posix --suppress=missingIncludeSystem *.cpp
 clang++ -std=c++14 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic *.cpp
 clang++ -std=c++14 -Weverything -Wno-c++98-compat -Wno-padded *.cpp
 clang++ -cc1 --help
 icpc -std=c++14 -Wall -Wextra -pedantic *.cpp
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>                  // unique_ptr
#include <numeric>                 //  accumulate
#include <typeinfo>
#include "fahrzeug.h"
using namespace std;

/** \brief Prints some info from a vehicle
 *  \param[in,out]  s   output stream
 *  \param[in]     p   a general vehicle
 *  \return        changed output stream
 */
ostream& operator<<(ostream &s, const Fahrzeug& p);

/** \brief Prints the whole vector of base class pointers
 *  \param[in,out]  s   output stream
 *  \param[in]     v   vector of base class pointers
 *  \return        changed output stream
 */
ostream& operator<<(ostream &s, const vector<unique_ptr<Fahrzeug>>& v);

//! @brief Compares the fuel consumption between two vehicles
//!
//! @param[in] a  base class pointer to first vehicle
//! @param[in] b  base class pointer to second vehicle
//! @return true if @p a needs less fuel than @p b
//!
//!
bool fuel_consumption(const unique_ptr<Fahrzeug>& a, const unique_ptr<Fahrzeug>& b);

bool fuel_consumption(const unique_ptr<Fahrzeug>& a, const unique_ptr<Fahrzeug>& b)
{
    return a->verbrauch() < b->verbrauch();
}

//! @brief Adds the fuel consumption of a vehicle @p y to quantity @p x
//!
//! @param[in] x  given quantity
//! @param[in] y  base class pointer to vehicle
//! @return x+y.fuel
//!
//!
float add_fuel(float x, const unique_ptr<Fahrzeug>& y);

float add_fuel(float x, const unique_ptr<Fahrzeug>& y)
{
    return x + y->verbrauch();
}

int main()
{
    cout << " -------- New  in v_10c_unique  --------------\n";
    // new in v_10c
    // container of base class pointers
    vector<unique_ptr<Fahrzeug>> v;
    // push_back and unique_ptr, see: http://stackoverflow.com/questions/3283778/why-can-i-not-push-back-a-unique-ptr-into-a-vector
    //           |-- we need a pointer to an instance
    v.push_back( unique_ptr<Fahrzeug> (new Raba(3600, 4000)) );
    v.push_back( unique_ptr<Fahrzeug> (new Opel(1450)) );
    v.push_back( unique_ptr<Fahrzeug> (new MAN(1200, 12000)) );
    v.push_back( unique_ptr<Fahrzeug> (new Smart(950)) );
    v.push_back( unique_ptr<Fahrzeug> (new Smart(1100)) );


//    C++-14
//    https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
    vector<unique_ptr<Fahrzeug>> w
    {
        make_unique<Fahrzeug> (Raba(3600, 4000))  // doesn't work
    };

    auto ip = make_unique<Raba>(Raba(3600, 4000));


    cout << v << endl;

    cout << " -------- after sort (standard --> incorrect) -------------\n";
    sort(v.begin(),v.end());
    cout << v << endl;

    cout << " -------- only the pointers have been compared -------------\n";

    cout << " -------- after sort (compare regarding fuel consumption) -------------\n";
    sort(v.begin(),v.end(), fuel_consumption );
    cout << v << endl;

    cout << " -------- correct-------------\n";

    // Berechne Flottenverbrauch (gleich gewichtet)
    // konventionell
    float sum=0.0;
    for (unsigned int i=0; i<v.size(); ++i)
    {
        sum += v[i]->verbrauch();
    }
    cout << "konv: durchschnittlicher Verbrauch: " << sum/v.size() << endl;

    // via STL
    float sum2 =accumulate(v.begin(), v.end(), 0.0f, add_fuel);
    cout << "accu: durchschnittlicher Verbrauch: " << sum2/v.size() << endl;


    cout << " --------  sort using lambda function for 'operator>' -------------\n";
//   Sorting by using lambda-functions (ascending order wrt. fuel)
//   http://stackoverflow.com/questions/5122804/sorting-with-lambda
    sort(v.begin(),v.end(),
         [](const unique_ptr<Fahrzeug>& aa, const unique_ptr<Fahrzeug>& cc) -> bool
           {
               return aa->verbrauch() > cc->verbrauch();
           }
        );

    cout << v << endl;
////   Free those element that have been allocated by new: No longer needed when using unique_ptr
    return 0;
}   // free the memory storing the pointers in vector 'v' at the end of the scope


//   We define an output function for references to the basis class
//                                            |--- parameter passing by reference allows polymorphism
ostream& operator<<(ostream &s, const Fahrzeug& p)
{
//                   Virtual Method Table
//             |--   VMT at run time ==> method from derived class
//             |                         |--- always non-virtual method from base class
    s << p.classname() << " : " << p.Get_kg() << " kg   and "
//             |--   VMT at run time ==> method from derived class
      << p.verbrauch() << " l/100km" << endl;
    return s;
}


ostream& operator<<(ostream &s, const vector<unique_ptr<Fahrzeug>>& v)
{
    for (const auto& it: v)             // Reference is required with unique_ptr. No copy constructor for unique_ptr available!
    {
        cout << *it;
    };
    return s;
}
