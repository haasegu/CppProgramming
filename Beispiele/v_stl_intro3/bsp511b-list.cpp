//	Sec. 511 of lecture
//	Dynamic C++-Vector; extend vector until a negative number is given
//  g++ -std=c++11 -Wall -Wextra -pedantic bsp511b-list.cpp

#include <cmath>                        //       sqrt()
#include <iostream>
#include <list>                         //       list<>
using namespace std;

int main()
{
    list<double> x;             // Deklariere Liste der Laenge 0

    do {                        // Verlaengere die Liste mit Eingabedaten
        double tmp;
        cout << endl << "Zahl: "; cin >> tmp;
        x.push_back(tmp);               // Verlaengere die Liste
    } while( x.back() >= 0.0 ); // solange kein negatives Elemement entsteht
    x.pop_back();               // Entferne das letzte, negative Element

    double norm = 0.0;
    for (auto pi=x.begin(); pi != x.end(); ++pi) {    // Normberechnung
        norm += *pi * *pi;
    }
    norm = sqrt(norm);

    cout << "\n Lange: " << x.size() << "   letztes Element : " <<  x.back();
    cout << "\n Norm : " << norm << endl;

    return 0;
}









