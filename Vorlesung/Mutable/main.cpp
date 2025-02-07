//  g++ -O3 -Wall -W -Wfloat-equal -Wshadow -Wredundant-decls -Weffc++ -pedantic main.cpp polygon.cpp
//  clang++ -O3 -Weverything -Wno-conversion -Wno-c++98-compat -Wno-padded main.cpp polygon.cpp
#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>   // sort
#include <cstdlib>     // srand, rand
#include <ctime>       // time
#include "polygon.h"
using namespace std;


//----------    Hauptprogramm    ----------------------
int main()
{
    const Polygon a(19);
    Polygon b(a);
    const Point2D p1(0,0), p2(0.0f, 0.5f);
    cout << "Punktabstand " << dist(p1,p2) << endl; // Abstand zweier Punkte

    cout << "Umfang b: " << b.perimeter() << endl; // Umfang des geschlossenen Polygonzuges b
    b.append(p1);  //   Haenge den neuen Punkt als zusaetzliche, letzte Ecke an das Polygon b
    cout << "Umfang b: " << b.perimeter() << endl; // Umfang des geschlossenen Polygonzuges b

    cout << "Polynom mit " << a.number() << " Ecken" << endl; // Anzahl der Ecken des Polygons a
    cout << "Umfang a: " << a.perimeter() << endl; // Umfang des geschlossenen Polygonzuges a

// -----------------------------------------------------------------------------
//  Now, we demonstrate the difference in runtime between classes
//  Polygon_old (without mutable member) and
//  Polygon (with mutable member).
//  Be sure to switch on optimization (-O3  in my Release version).
//  -----------------------------------------------------------------------------
    vector<Polygon_old>  po;
    vector<Polygon>      pn;
    const int NN=100000;
    po.reserve(NN);                  // avoid multiple memory allocations in following loop
    pn.reserve(NN);
    /* initialize random seed: */
    srand (time(nullptr));
    for (int i=0; i<NN; ++i)
    {
        int kk = rand() % 1000 + 10;
        po.push_back(Polygon_old(kk));
        pn.push_back(Polygon(kk));
    }

    clock_t t;
    float   time_old, time_new;

    //  sort  the without mutable in class
    t = clock();
    sort(po.begin(),po.end());
    time_old = static_cast<float>(clock() - t)/CLOCKS_PER_SEC;


    //  sort  the with mutable in class
    t = clock();
    sort(pn.begin(),pn.end());
    time_new = static_cast<float>(clock() - t)/CLOCKS_PER_SEC;

    cout << "timings    no mutable: " << time_old  << " sec.;      mutable: " <<  time_new << " sec.\n";


    return 0;
}
