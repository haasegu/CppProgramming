// Variadic function
// see https://kubasejdak.com/variadic-functions-va-args

#include <cstdarg>
#include <iostream>
using namespace std;

//   Variadic function (no constexpr possible)
int sum1(int count, ...)
{
    int sum = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        sum += num;
    }

    va_end(args);
    return sum;
}

//   Variadic template (constrexpr ist only an add on)
//       special function to stop recursion
template <typename T>
constexpr auto sum2(T arg)
{
    return arg;
}

//       general recursive function
template <typename T, typename... Args>
constexpr auto sum2(T first, Args... args)
{
    return first + sum2(args...);
}

//  main test code
int main()
{
    auto p1 = sum1(4, 6, 7, 8, 9);
    cout << p1 << endl;
    
    auto p2 = sum2(   6, 7, 8, 9);
    cout << p2 << endl;
    
    auto p3 = sum2(   6, 7, 8, 9.1);
    cout << p3 << endl;
    return 0;
}
/*
 g++ -pedantic -std=c++17 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized *.cpp
 cppcheck --enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem *.cpp
 clang++ -std=c++17 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -Wno-shorten-64-to-32 -Wno-sign-conversion -pedantic *.cpp
 clang++ -std=c++17 -Weverything -Wno-c++98-compat -Wno-shorten-64-to-32 -Wno-sign-conversion -Wno-padded *.cpp
 clang++ -cc1 --help
 icpc -std=c++17 -Wall -Wextra -pedantic *.cpp
*/
