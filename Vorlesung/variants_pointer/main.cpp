// Demo um C-Pointer, unique_ptr und shared_ptr zu zeigen.

#include <cmath>
#include <iostream>
#include <memory>               // shared_ptr
using namespace std;

// Simple class
class Basis
{
public:
    Basis(double a, double b) : _s(sqrt(a*a+b*b)) {}
    double fkt() const {return _s;}
private:
    double _s;
};

int main()
{
    {
        cout << "\n####  Demo C-Pointer and dynamic memory ####\n";
        Basis* a = new Basis(3,4);          // allocate memory and init instance

        Basis* b=a;                         // copies the pointer, n o t  the data
        cout << b->fkt() << endl;

        delete a;                         // free the allocated memory
//        delete b;                         // WRONG: free already deallocated memory
    }

    {
        cout << "\n####  Demo shared pointer ####\n";
//        shared_ptr<Basis> a(new Basis(3,4));          // allocate memory
        auto a = make_shared<Basis>(3,4);

        shared_ptr<Basis> b=a;                         // copies the pointer, n o t  the data
        cout << b->fkt() << endl;
        cout << endl;
    }    // destructor of shared_ptr frees the allocated memory (only once !)

    {
        cout << "\n####  Demo unique pointer ####\n";
//        unique_ptr<Basis> a(new Basis(3,4));          // allocate memory
        auto a = make_unique<Basis>(3,4);             // C++-14

        //unique_ptr<Basis> b=a;                      // copy not possible with unique_ptr
        unique_ptr<Basis>& b=a;                       // but reference is possible
        cout << b->fkt() << endl;
        cout << endl;
    }    // destructor of unique_ptr frees the allocated memory (only once !)

    {
        cout << "\n####  Demo raw pointer to shared pointer ####\n";
//        https://stackoverflow.com/questions/4665266/creating-shared-ptr-from-raw-pointer
        // Don't do it, or do it in that way:
        shared_ptr<Basis> a(new Basis(3,4));
    }

    return 0;
}


/*
 g++ -pedantic -std=c++14 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized *.cpp
 cppcheck --enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem *.cpp
 clang++ -std=c++14 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -Wno-shorten-64-to-32 -Wno-sign-conversion -pedantic *.cpp
 clang++ -std=c++14 -Weverything -Wno-c++98-compat -Wno-shorten-64-to-32 -Wno-sign-conversion -Wno-padded *.cpp
 clang++ -cc1 --help
 icpc -std=c++14 -Wall -Wextra -pedantic *.cpp
*/
