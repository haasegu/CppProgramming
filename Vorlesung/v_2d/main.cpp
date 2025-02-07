//      Einige Demos mit Loops und Genauigkeit der Zahldarstellung.
//
//      Gleitkommazahlen:  https://de.wikipedia.org/wiki/IEEE_754
//                         https://de.wikipedia.org/wiki/Gleitkommazahl
//
//      Ganze Zahlen: https://de.wikipedia.org/wiki/Integer_%28Datentyp%29#Maximaler_Wertebereich_von_Integer
//
//
#include <iostream>
#include <cmath>         // M_PI , auch  M_PI=4*atan(1)       moeglich
using namespace std;

int main()
{
//-------------------------------------------------------------------------------
    // Berechne sum 1/k^2  mit k = 1,...
    //                                  --> pi^2 / 6
    int n = 100000;

    float s1=0.0f, s2=0.0f;

    // Forwaerts
    for (int k=1; k<=n; ++k)   s1 += 1.0f/k*1.0f/k;

    // Rueckwaerts
    //for (int k=n; k>=1; --k)   s2 += 1.0f/(k*k);        // Achtung k*k > 2^32 moeglich !
    for (int k=n; k>=1; --k)   s2 += 1.0f/k*1.0f/k;

    // Exact
    const double s_e = M_PI*M_PI/6.0;

    // Welche Berechnung ist genauer?  s1 oder s2 ?  Warum ?
    cout << endl << "################################" << endl;
    cout << endl << "s_e - s1 :"  << s_e - s1  << endl;
    cout << endl << "s_e - s2 :"  << s_e - s2  << endl;
    cout << endl << "################################" << endl;

//-------------------------------------------------------------------------------

    // Demo zu Zahldarstellung im Computer
    {
        int nn = 10;                            // nn: keine Zweierpotenz
        float sum = 1.0f, h = 1.0f/nn;          //  h: periodischer Dezimalbruch in Binaerdarstellung

        for (int k=1; k<=nn; ++k)   sum -= h;
        // sum should be 0
        cout << endl << " nn = " << nn << " : sum = " << sum << endl;
    }
    {
        int nn = 1024;                         // nn: 2^10 == 1<<10  (10x bitShift nach links)
        float sum = 1.0f, h = 1.0f/nn;         //  h: exakt in Binaerdarstellung


        for (int k=1; k<=nn; ++k)   sum -= h;
        // sum should be 0
        cout << endl << " nn = " << nn << " : sum = " << sum << endl;
    }




    return 0;
}
