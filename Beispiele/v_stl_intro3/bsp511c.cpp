//	Sec. 511 of lecture
//	Static C++-Vector
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp511c.cpp

#include <array>                        //       array<T,N>
#include <cmath>                        //       sqrt()
#include <iostream>
using namespace std;

int main()
{
    array<double,10> x;                 // Statischer Vektor der Lange 10
    
    for (size_t k=0; k<x.size(); ++k) { // Belege den Vektor mit Daten
        x.at(k) = 1.0/(k+1.0);
    }
    
    double norm = 0.0;
    for (size_t k=0; k<x.size(); ++k) {  // Normberechnung
        norm += x[k]*x[k];
    }
    norm = sqrt(norm);

    cout << "\n Lange: " << x.size() << "   letztes Element : " <<  x.back();
    cout << "\n Norm : " << norm << endl;

    return 0;
}









