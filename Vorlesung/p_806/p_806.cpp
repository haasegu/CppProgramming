// Bsp. Celsius nach Fahrenheit und Kelvin.
// Alternative Outputuebergabe nach:
//       T. Will: C++ Das umfassende Handbuch, p.806ff (§28.1.1); ; Rheinwerk Verlag, 2018

//  g++ -std=c++14 -Wfatal-errors -Wall -Wextra -pedantic p_806.cpp   (without lines 47-49)
//  g++ -std=c++17 -Wfatal-errors -Wall -Wextra -pedantic p_806.cpp   (gcc-7.2) 
//  clang++ -std=c++17 -Wc++17-extensions p_806.cpp


#include <iostream>
#include <utility>             // pair
#include <tuple>               // tuple

//using std:cout; using std:endl;
//using std::pair;
using namespace std;

constexpr 
pair<float, float> c2fk(const float celsius)
{
    return make_pair( celsius*9.0f/5+32.0f, celsius+273.15f);
}

constexpr 
tuple<float, float> c2fk_tup(const float celsius)
{
    return make_tuple( celsius*9.0f/5+32.0f, celsius+273.15f);
}


int main()
{
    float c{};
    cout << " Celsius    : "; cin >> c;
    
    const auto pp = c2fk(c);
    cout << " Fahrenheit : " << pp.first << endl;
    cout << " Kelvin     : " << pp.second << endl;
    cout << "---------------------------  " << endl;
    
    const auto tt = c2fk_tup(c);
    cout << " Fahrenheit : " << get<0>(tt) << endl;
    cout << " Kelvin     : " << get<1>(tt) << endl;
    cout << "---------------------------  " << endl;
    
    float f{}, k{};
    tie(f,k) = c2fk_tup(c);
    cout << " Fahrenheit : " << f << endl;
    cout << " Kelvin     : " << k << endl;
    cout << "---------------------------  " << endl;

//     https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html   
//#if __GNUC__ >= 7 && _GNUC_MINOR__ >= 2
    auto [ff,kk] = c2fk_tup(c);                  //  : -std=c++1z (gcc-7.2)
    cout << "--  C++17  --" << endl;
    cout << " Fahrenheit : " << ff << endl;
    cout << " Kelvin     : " << kk << endl;
    cout << "---------------------------  " << endl;
//#endif    

    return 0;
}

