//  Vorlesung:  17.3.2023
#include <cassert>                      // assert()
#include <cstring>                      // strlen(c-string) from string.h
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// C++
    string hpp("Hello");        // (potentially) flexible C++-string
    size_t spp = hpp.size();
    size_t lpp = hpp.length();
    assert(spp==lpp);           // size==length for C++-string
    cout << "c++ :"<< hpp << ":  lang " << lpp << "  " << spp << endl;
    
    // simple hack C++
    string const sdummy("yUMMMY");
    hpp[lpp] = 'x';             // no compiler warning; but incorrect index
    cout << "c++2:"<< hpp << ":  lang " << lpp << "  " << spp << endl;
    cout << sdummy << endl;

    // C
    char hcc[] = "Hello";       // fixed size C-string  
    size_t lcc = strlen(hcc);
    int scc = sizeof(hcc)/sizeof(char);
    
    cout << "C   :"<< hcc << ":  lang " << lcc << "  " << scc << endl;

    // simple hack C: 
    char const cdummy[] = "Yummy";
    hcc[lcc] = 'X';             // no compiler warning; correct index
    //hcc[scc] = 'Q';           //    compiler warning; const data in cdummy is changed
    //      Suddenly, more charachters of hcc are printed than available
    size_t lcc2 = strlen(hcc);  // len() searches for the first '\0'
    int scc2 = sizeof(hcc)/sizeof(char); // uses static info from declaration
    cout << "C 2 :"<< hcc << ":  lang " << lcc2 << "  " << scc2 << endl;    
    
    cout << cdummy << endl;     // the compiler won't allocate cdummy without using

    return 0;
}
