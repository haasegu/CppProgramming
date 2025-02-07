//   Democode um einige Fehler aufzuzeigen
//   g++ -pedantic -std=c++11 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized main.cpp fkt.cpp
//   cppcheck --enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem main.cpp  fkt.cpp
//   clang++ -std=c++11 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic main.cpp  fkt.cpp
#include <iostream>
#include <vector>
#include "fkt.h"
using namespace std;

/**
 * Calculates the largest fibonacci number that fits into an int
 *
 * @return array of the fibonacci number and its index
 *
 */
int*  fibo_wrong()
{
    int temp = 0;
    int last = 1;
    int fib  = 1;

    // the indices of fib 1 and fib 2 is 1
    // so we have already 2 fib numbers
    int index = 2;

    while((fib + last) > fib)
    {
        temp = fib;
        fib += last;
        last = temp;

        index++;
    }

    int result[2] = {index, fib};

    return result;     // pointer to a temorary object is returned
}

/**
 * Main function of the program.
 * Calls the largestFibonacci() function and prints the
 * largest fibonacci number and its indexq
 *
 * @return 0
 */
int main()
{
    //-------------------------------------------------------------------------------
    int* result = fibo_wrong();      // temporary object is already deallocated
        string ss("gshsghagh");    // switch on to demonstrate that elements in result will be changed

    cout << "Largest fibonacci number that fits into an int is: " << result[1]
         << " at index: " << result[0] << endl;
    //-------------------------------------------------------------------------------
    int* result2 = fibo_dangerous();      // object in heap is still available
        string ss2("gshsghagh");    // switch on to demonstrate

    cout << "Largest fibonacci number that fits into an int is: " << result2[1]
         << " at index: " << result2[0] << endl;
    //int* rr=result;
    delete [] result2;                // deallocate the heap memory
    //cout << rr[0] << endl ;
    //delete [] rr;
//    // better use  unique_ptr<int>  instead of  int*
//    //-------------------------------------------------------------------------------
    vector<int> result3 = fibo_vector();
    cout << "Largest fibonacci number that fits into an int is: " << result3[1]
         << " at index: " << result3[0] << endl;
    //-------------------------------------------------------------------------------
    vec2 result4 = fibo_struct();      // temporary object is already deallocated
    cout << "Largest fibonacci number that fits into an int is: " << result4.fibon
         << " at index: " << result4.idx << endl;
    //-------------------------------------------------------------------------------

    return 0;
}
