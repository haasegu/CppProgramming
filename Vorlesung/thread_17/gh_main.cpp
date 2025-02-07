// C++ Vorlesung  xxx
// C++-17: Threads, execution policies
//   Great web pages, great book by Filipek:   https://www.bfilipek.com/2018/06/parstl-tests.html

/*
 g++ -O3 -std=c++17 gh_main.cpp -ltbb
 g++ -O3 -std=c++17 -pedantic -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized gh_main.cpp -ltbb
 ---
 cppcheck --enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem gh_main.cpp
 clang++ -O3 -std=c++17 -ltbb gh_main.cpp
 clang++ -std=c++17 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic gh_main.cpp
 clang++ -std=c++17 -Weverything -Wno-c++98-compat -Wno-padded -ltbb gh_main.cpp
 clang++ -cc1 --help
 ---
 icpc -O3 -std=c++17 -ltbb -Wall -Wextra -pedantic gh_main.cpp
*/
#include <algorithm>
#include <chrono>
#include <execution>          // execution policy
#include <iostream>
#include <numeric>            //  accumulate
#include <random>
#include <vector>
using namespace std;
using namespace std::chrono;  // timing


/** \brief Prints the whole vector of base class pointers
 *  \param[in,out]  s   output stream
 *  \param[in]      v   vector
 *  \return        changed output stream
 */
template <class T>
ostream& operator<<(ostream &s, const vector<T>& v)
{
    for (const auto& it: v)             // Reference is required with unique_ptr. No copy constructor for unique_ptr available!
    {
        cout << *it << " ";
    }
    return s;
}


int main()
{
    cout << "Threads C++17" << endl;

    size_t const N = 1<<25;
    vector<double> v(N);
    iota(v.begin(), v.end(), 1);
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});

    auto const v_bak(v);

    {
        v = v_bak;
        cout << "----   sort old   ----" << endl;
        auto t1 = system_clock::now();
        sort(v.begin(), v.end());
        auto t2 = system_clock::now();
        //auto duration = duration_cast<microseconds>(t2 - t1);
        auto duration = std::chrono::duration <double, std::micro>(t2 - t1);
        cout << "sort old   : " << duration.count() / 1e6 << " sec." << endl;
    }

    {
        v = v_bak;
        cout << "----   sort seq   ----" << endl;
        auto t1 = system_clock::now();
        sort(std::execution::seq, v.begin(), v.end());
        auto t2 = system_clock::now();
        auto duration = std::chrono::duration <double, std::micro>(t2 - t1);
        cout << "sort seq   : " << duration.count() / 1e6 << " sec." << endl;
    }

    {
        v = v_bak;
        cout << "----   sort par   ----" << endl;
        auto t1 = system_clock::now();
        sort(std::execution::par, v.begin(), v.end());
        //auto cnt = count(std::execution::par, v.begin(), v.end(), 17);
        auto t2 = system_clock::now();
        auto duration = std::chrono::duration <double, std::micro>(t2 - t1);
        cout << "sort par   : " << duration.count() / 1e6 << " sec." << endl;
    }
    
    {
        v = v_bak;
        cout << "----   sort par_unseq   ----" << endl;
        auto t1 = system_clock::now();
        sort(std::execution::par_unseq, v.begin(), v.end());
        auto t2 = system_clock::now();
        auto duration = std::chrono::duration <double, std::micro>(t2 - t1);
        cout << "sort par_unseq: " << duration.count() / 1e6 << " sec." << endl;
    }
    
    auto ip = max_element(std::execution::par,v.cbegin(), v.cend());
    cout << "*ip "  << *ip << endl;


    return 0;
}

