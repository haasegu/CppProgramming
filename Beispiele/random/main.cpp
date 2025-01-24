// Zufallszahlen generieren
// g++ -g  -std=c++17 -pedantic -Wall main.cpp

#include <cstdlib>    // rand()
#include <ctime>      // time()
#include <iostream>
#include <random>     // C++11 random classes: minstd_rand0::operator(), std::mt19937, std::uniform_int_distribution
using namespace std;

/** The to be generated is determined by a C++ random number generator class
 *   <a href="http://www.cplusplus.com/reference/random/minstd_rand">minstd_rand0</a>  and
 *   its generating routine
 *   <a href="http://www.cplusplus.com/reference/random/linear_congruential_engine/operator%28%29">minstd_rand0:operator()</a>.
 *   More pseudo-random number engines are
 *   <a href="http://www.cplusplus.com/reference/random/">available</a>.
 *
 * \return correctness of code
 *
 */

int main()
{
    int const ANF   = -5;
    int const ENDE  = 17;
    int const LOOPS = 10;

    cout << "Zahlen aus [" << ANF << "," << ENDE << "]" << endl;

    {   // ganzzahlige Zufallszahlen in C
        cout << "\n##########  ganzzahlige Zufallszahlen in C  ##########\n";
        // Seed
        srand ( time(nullptr) );
        // Generierung
        for (int k=0; k<LOOPS; ++k)
        {
            int is = rand() % (ENDE-ANF+1)+ANF;  // Zufallszahl aus [ANF, ENDE]
            cout << "  " << is;
        }
        cout << endl;
    }

    {   // ganzzahlige Zufallszahlen in C++, analog zu C
        cout << "\n##########  ganzzahlige Zufallszahlen in C++ (wie C)  ##########\n";

        //  see: http://www.cplusplus.com/reference/random/linear_congruential_engine/operator%28%29
        //  see: http://www.cplusplus.com/reference/random/
        // Seed
        std::minstd_rand0 gen(time(nullptr));   //Will be used to obtain a seed for the random number engine
        // Generierung
        for (int k=0; k<LOOPS; ++k)
        {
            int is = gen() % (ENDE-ANF+1)+ANF;  // Zufallszahl aus [ANF, ENDE]
            cout << "  " << is;
        }
        cout << endl;
    }

    {   // ganzzahlige Zufallszahlen in C++: komfortabler
        cout << "\n##########  ganzzahlige Zufallszahlen in C++ (komfortabel)  ##########\n";

        //  see: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
        // Seed
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        // Generierung
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(ANF,ENDE);
        for (int k=0; k<LOOPS; ++k)
        {
            int is = distrib(gen);  // ganze Zufallszahl aus [ANF, ENDE]
            cout << "  " << is;
        }
        cout << endl;
    }

    return 0;
}
