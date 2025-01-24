//	Sec. 511 of lecture
//	Dynamic C++-Vector; extend vector until a negative number is given
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp511b.cpp

#include <cmath>                        //       sqrt()
#include <iostream>
#include <vector>                       //       vector<>
using namespace std;

int main()
{
    vector<double> x;           // Deklariere Vektor mit Laenge 0
    
    do {                        // Verlaengere den Vektor mit Eingabedaten
        double tmp;
        cout << endl << "Zahl: "; cin >> tmp;
        x.push_back(tmp);               // Verlaengere den Vektor
    } while( x.back() >= 0.0 ); // solange kein negatives Elemement entsteht
    x.pop_back();               // Entferne das letzte, negative Element
    
    double norm = 0.0;
    for (size_t k=0; k<x.size(); ++k) {    // Normberechnung
        norm += x[k]*x[k];
    }
    norm = sqrt(norm);

    cout << "\n Lange: " << x.size() << "   letztes Element : " <<  x.back();
    cout << "\n Norm : " << norm << endl;

    return 0;
}









