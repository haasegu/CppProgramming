//  Musterloesung mit Templates zu : Fibonacci
//	           g++ -O2  -std=c++11 -Wall -pedantic -Wunused -Wredundant-decls  -Wundef  -Wuninitialized  main.cpp
//  Uberleitung der Funktion fibo in eine Templatefunktion fibo<T>
#include <iostream>


#include <type_traits>  // is_integral<T>::value
using namespace std;

/** Ermittlung der groessten Fibonaccizahl im gewaehlten Zahlbereich.
*   Formel @f$ f_n := f_{n-1} + f_{n-2} @f$.
*
*  @param[out] n  Index der groessten darstellbaren Fibonaccizahl
*  @return     groesste darstellbare Fibonaccizahl.
*/
template <class T>
T fibo(T& n)
{
    T fn=1, f1=0, f2;
    n = 1;

    while (fn>=f1)     // Abbruch falls f_n<f_{n-1}
    {
        ++n;
        f2 = f1;
        f1 = fn;
        fn = f1+f2;
    }

    --n;        // wir suchen die letzte darstellbare Fibonacci-zahl
    return f1;  // wir suchen die letzte darstellbare Fibonacci-zahl
}


/** Templatefunktion zum Testen der Templatefunktion fibo<T>.
*   Da die Parameterliste leer ist, muss der Templateparameter beim Aufruf
*   der Funktion explizit angegeben werden.
*   @warning Ausgabe der Ergebnisse bei <signed char> und <char> als Zeichen, nicht als Zahlen.
*/
template <class T>
void check_fibo()
{
    T idx;
    const T f1=fibo(idx);
    cout << " groesste darstellbare Fibonacci-Zahl:  " << f1 << endl;
    cout << " hat den Index  " << idx << endl;
}

/** Spezialisierung der Templatefunktion zum Testen von fibo<T> fuer
*   den Templateparameter <signed char>.
*/
template <>
void check_fibo<signed char>()       // Spezialisierung fuer <signed char>
{
    cout << "Spezialisierung fuer <signed char>" << endl;
    signed char idx;
    const signed char f1=fibo(idx);
    cout << " groesste darstellbare Fibonacci-Zahl:  " << static_cast<int>(f1) << endl;
    cout << " hat den Index  " << static_cast<int>(idx) << endl;
}

/** Templatefunktion zum Testen der Templatefunktion fibo<T>.
*   Da die Parameterliste leer ist, muss der Templateparameter beim Aufruf
*   der Funktion explizit angegeben werden.
*   @warning Anderer Weg, um die Ausgabe von char-Zahlen korrekt durchzufuehren.
*/
template <class T>
void check_fibo2()
{
    // http://en.cppreference.com/w/cpp/types/is_integral
    static_assert(is_integral<T>::value,"Kein integraler Typ");         // erst ab g++-4.7
    cout << "############  check_fibo2  ##################" << endl;
    T idx;
    const T f1=fibo(idx);

    const bool is_char = sizeof(T)<2;                     // liegt eine char-Zahl vor?
    auto tmp1 =  is_char?static_cast<short>(f1):f1;       // resulting type is int or T
    auto tmp2 =  is_char?static_cast<short>(idx):idx;
    cout << " groesste darstellbare Fibonacci-Zahl:  " << tmp1 << endl;
    cout << " hat den Index  " << tmp2 << endl;
}


int main()
{
    cout << "Fibonacci  " << endl;

    short int idx;

    int f2=fibo(idx);     // Parameter ist <short int>, daher wird fibo<<short int>(...) aufgerufen

    cout << " groesste darstellbare Fibonacci-Zahl:  " << f2 << endl;
    cout << " hat den Index  " << static_cast<int>(idx) << endl;
    cout << "##############################" << endl;

    check_fibo<int>();
    check_fibo<short int>();
    check_fibo<signed char>();            // Hier wird die Spezialisierung von fibo<T> fuer <T=signed char> aufgerufen

    check_fibo2<signed char>();
    check_fibo2<long long int>();
    check_fibo2<unsigned long long int>();
//    check_fibo2<double>();           // Nicht moeglich, da durch static_assert() zur Compilezeit abgefangen

    return 0;
}
