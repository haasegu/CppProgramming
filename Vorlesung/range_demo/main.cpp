// C++ Vorlesung  xxx
// C++-20: Demo of ranges, view
//         Will: "The C++ Standard Library", §11

/*
 g++ -O3 -std=c++20 main.cpp
 g++ -O3 -std=c++20 -pedantic -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized main.cpp
 ---
 cppcheck --enable=all --inconclusive --std=c++20 --suppress=missingIncludeSystem main.cpp
 clang++ -O3 -std=c++20 main.cpp
 clang++ -std=c++20 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic main.cpp
 clang++ -std=c++20 -Weverything -Wno-c++98-compat -Wno-padded main.cpp
 clang++ -cc1 --help
 ---
 dpcpp -O3 -std=c++20 -Wall -Wextra -pedantic main.cpp
 *
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Will: "The C++ Standard Library", §11
#include <ranges>
int main()
{
    vector<int> numbers{1,2,3,4,5,6};

    auto results = numbers | std::views::filter   (  [](int n){return n%2 == 0;} )
                           | std::views::transform ( [](int n){return n*2; }     );

    for (auto v:results) cout << v << "  ";
    cout << endl;
    return 0;
}

