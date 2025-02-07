// Demonstration von  C++ - map
//           https://en.cppreference.com/w/cpp/container/map
// g++ -std=c++17 demoMap.cpp

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> bb{ {"Zwei", 2}, {"Vier", 4}, {"Neun", 9}, {"Fuenf", 5} };

    for (const auto& [key, value] : bb) {
        cout << key << " --> " << value << endl;
    }
    cout << endl;


    cout << "Generate new Element in map." << endl;
    bb["Eins"] = 1;           // access  or  i n s e r t
    //bb.at("Eins") = 1;      // acess throws exception because key "Eins" not in range

    for (const auto& [key, value] : bb) {
        cout << key << " --> " << value << endl;
    }






// Zugriff auf Elemente ausserhalb des Ranges.
// g++ -std=c++17 -DDEMO_RANGE demoMap.cpp
#ifdef DEMO_RANGE
//     Ungesichert
    cout << "Access to bb[\"Sechs\"]   : \n";
    auto tmp = bb["Sechs"];     // access to non-exisitent element ==> insert with standard value
    cout << tmp   << "      Done" << endl;
//     Gesichert
    cout << "Access to bb.at(\"Sechs\"): \n";
//           without catching exception
    //cout << bb.at("Sieben") << "      Done" << endl;
//           catch exception
    try {
        auto tt = bb.at("Sieben");
        cout << tmp << "      Done" << endl;
    }
    catch (std::out_of_range) {
        cout << "Take care when accessing a map outside its index range!" << endl;
    }
#endif

    return 0;
}

