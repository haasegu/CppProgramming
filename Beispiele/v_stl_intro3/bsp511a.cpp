//	Sec. 511 of lecture
//	Dynamic C++-Vector
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp511a.cpp

#include <cmath>                        //       sqrt()
#include <iostream>
#include <vector>                       //       vector<>
using namespace std;

int main()
{
    unsigned int n;
    cout << "\n Anzahl der Vektorelemente : ";
    cin >> n;                           // Dynamische Laenge des Vektors

    vector<double> x(n);                // Deklariere Vektor dieser Laenge

    for (size_t k=0; k<x.size(); ++k) {    // Belege den Vektor mit Daten
        x.at(k) = 1.0/(k+1.0);
    }

    double norm = 0.0;
    for (size_t k=0; k<x.size(); ++k) {    // Normberechnung
        norm += x[k]*x[k];
    }
    norm = sqrt(norm);

    cout << "\n Norm : " << norm << endl;

    return 0;
}









