// Vorlesung  12.März 2024
// Einfuerung von String und C++-Vektor von Strings in Funktion geheimZahl

// g++ -g  -std=c++11 -pedantic -Wall main.cpp
// valgrind -v --leak-check=yes --tool=memcheck  --log-file=mem.out -show-reachable=yes ./a.out

#include <array>      // array
#include <cassert>    // assert()
//#include <cstdlib>  // rand()
#include <iostream>
#include <random>     // random classes: minstd_rand0::operator()
#include <string>     // string
#include <vector>     // vector
using namespace std;

/** Einlesen einer ganze Zahl solange, bis diese aus dem Intervall [a,b] ist.
*  @param[in]  a  Intervallanfang
*  @param[in]  b  Intervallende
*  @return     ganze Zahl aus [a,b]
*  @warning Keine Absicherung bzgl. Fehleingaben
*/
int eingabe(const int a, const int b);

/** Erraten einer gegebenen Geheimzahl @p iSecret aus dem Intervall [ @p a, @p b].
*  @param[in]  iSecret Geheimzahl
*  @param[in]  a       Intervallanfang
*  @param[in]  b       Intervallende
*  @return     Vektor mit allen Versuchen
*  @warning Keine Absicherung bzgl. Fehleingaben
*/
vector <int> geheimZahl(const int iSecret, const int a, const int b);

/** The number to be searched is determined by a C++ random number generator class
 *   <a href="http://www.cplusplus.com/reference/random/minstd_rand">minstd_rand0</a>  and
 *   its generating routine
 *   <a href="http://www.cplusplus.com/reference/random/linear_congruential_engine/operator%28%29">minstd_rand0:operator()</a>.
 *   More pseudo-random number engines are
 *   <a href="http://www.cplusplus.com/reference/random/">available</a>.
 *
 * \return correctness of code
 */
int main()
{
    const int anf(1), ende(10);         // Intervall: Kann auch via Tastatur eingegeben werden
    cout << "Zahlensuche im Intervall [" << anf << "," << ende << "]\n";

//  C-Style random
//    srand ( time(NULL) );               // Zufallszahlengenerator started "zufaellig"
//    const int is = rand() % (ende-anf+1)+anf;  // ganze Zufallszahl aus [anf, ende]

//  C++-Style random
//  see: http://www.cplusplus.com/reference/random/linear_congruential_engine/operator%28%29
//  see: http://www.cplusplus.com/reference/random/
    std::minstd_rand0 generator (time(NULL));        // minstd_rand0 is a standard linear_congruential_engine
    // const unsigned grand = generator();           // generate the next random number from interval  [generator.min(), generator.max() ]
    const int mysecret = generator() % (ende-anf+1)+anf; // generate the next random number from [anf, ende]
    cout << generator.min() << "  " << generator.max() << "  " << mysecret << endl;

    const vector<int> cc = geheimZahl(mysecret, anf, ende);
    cout << cc.size() << " Versuche gebraucht!" << endl;

    return 0;
}


int eingabe(const int a, const int b)
{
    assert(a<=b);   // Bricht ab, falls Voraussetzung a<=b nicht erfuellt ist
    int k;
    do
    {
        cout << " Gib Zahl aus [" << a << "," << b << "] ein : ";
        cin >> k;
    }
    while ( !( a<=k && k<=b ) );

    return k;
}

vector <int> geheimZahl(const int iSecret, const int a, const int b)
{
    vector <int> tip;
    int iGuess;
//    const string myss[] = {"richtig","zu klein","zu gross"}; //C-array of strings, at() nicht verfuegbar
    const array<string,3> myss = {{"richtig","zu klein","zu gross"}}; //Array of strings 
//    const vector<string> myss = {"richtig","zu klein","zu gross"}; //Vector of strings

    do
    {
        int idx(0);
        cout << " Zahl aus [" << a << "," << b << "]" << endl;
        iGuess = eingabe(a,b);  // Garantiert  [a,b]
        if (iGuess == iSecret)
        {
            idx = 0;
        }
        else if (iGuess < iSecret)
        {
            idx = 1;
        }
        else
        {
            idx = 2;
        }
        // Remark:    idx = (iGuess>iSecret)+(iGuess!=iSecret);
        cout << iGuess << " ist " << myss.at(idx) <<endl;  //  Achtung: 0 <= idx <= 2
        tip.push_back(iGuess);
    }
    while (iGuess != iSecret);

    return tip;
}
