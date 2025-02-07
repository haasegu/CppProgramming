#include <iostream>
#include <string>
#include <cassert>    // assert()
#include <cstdlib>    // rand()
#include <ctime>      // time()
using namespace std;


/** Einlesen einer ganze Zahl solange, bis diese aus dem Intervall [a,b] ist.
*  @param[in]  a  Intervallanfang
*  @param[in]  b  Intervallende
*  @return     ganze Zahl aus [a,b]
*  @warning Keine Absicherung bzgl. Fehleingaben
*/
int eingabe(const int a, const int b);            // Prototype

int eingabe(const int a, const int b)
{
    assert(a<=b);   // Bricht ab, falls Voraussetzung a<=b nicht erfuellt ist
    int k(a-1);
    do
    {
        cout << " Gib Zahl aus [" << a << "," << b << "] ein : ";
        cin >> k;
    }
    while ( !( a<=k && k<=b ) );

    return k;
}

/** Erraten einer gegebenen Geheimzahl @p iSecret aus dem Intervall [ @p a, @p b].
*  @param[in]  iSecret Geheimzahl
*  @param[in]  a       Intervallanfang
*  @param[in]  b       Intervallende
*  @return     Anzahl der Versuche
*  @warning Keine Absicherung bzgl. Fehleingaben
*/
int geheimZahl(const int iSecret, const int a, const int b);            // Prototype

int geheimZahl(const int iSecret, const int a, const int b)
{
    int count(0);
    int iGuess(a-1);
    do
    {

        cout << " Zahl aus [" << a << "," << b << "]" << endl;
        iGuess = eingabe(a,b);  // Garantiert  [a,b]
        ++count;
        string ss;
        if (iGuess == iSecret)
        {
            ss = "richtig";
        }
        else if (iGuess < iSecret)
        {
            ss = "zu klein";
        }
        else
        {
            ss = "zu gross";
        }
        cout << iGuess << " ist " << ss <<endl;
    }
    while (iGuess != iSecret);

    return count;
}

int main()
{
    cout << "Hello world!" << endl;
    const int anf(4), ende(14);         // Kann auch via Tastatur eingegeben werden

    srand ( time(NULL) );               // Zufallszahlengenerator started "zufaellig"
    const int is = rand() % (ende-anf+1)+anf;  // ganze Zufallszahl aus [anf, ende]

    const int cc = geheimZahl(is, anf, ende);
    cout << cc << " Versuche gebraucht!" << endl;

    return 0;
}
