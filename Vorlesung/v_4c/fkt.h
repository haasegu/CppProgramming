#pragma once
#include <string>
#include <vector>
using namespace std;

/**  Signum-Funktion.
*   @param[in]  x  doppelt genaue reelle Zahl
*   @return     Vorzeichen der Zahl (0 ==> 0)
*/
double sgn(const double x);

/**  Signum-Funktion.
*   @param[in]  x  einfach genaue reelle Zahl
*   @return     Vorzeichen der Zahl (0 ==> 0)
*/
float sgn(const float x);

/**  Demonstration einer weiteren Signatur mit Funktion sgn.
*   @param[in]  x  string
*   @return     Laenge des strings
*/
size_t sgn(const string x);

/**  Kopiert eine Vektor auf den anderen. Der Vektor @p b wird bei Bedarf reallokiert.
*   @param[in]   a  zu kopierender Vektor
*   @param[out]  b  kopierter Vektor
*/
void copy_vek(const vector<int>& a, vector<int>& b);

/**  Demonstration der Uebergabe via Refeerenz und Aenderung des Wertes der Variablen.
*   @param[in,out]  a  Zahl
*/
void set_value(int& a);

/**  Meine eigene Powerfunktion. Rekursive Implementierung.
*   @param[in]  x  reelle Zahl
*   @param[in]  k  ganze Zahl >=0
*   @return     x^k
*   @warning    Bricht ab falls k < 0.
*/
float mypow(const float x, const int k);
