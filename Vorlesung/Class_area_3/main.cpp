//     Simple class demo
//  g++ -std=c++11 -Wall -W -Wfloat-equal -Wshadow -Wredundant-decls -Weffc++ -pedantic main.cpp form.cpp polygon.cpp
#include "form.h"
#include "polygon.h"
#include <algorithm>         // sort
#include <iostream>
#include <vector>            // vector
using namespace std;

//----------    Hauptprogramm  (nicht veraendern!!)   ----------------------
int main()
{
    const Kreis   a( 0.0F, 1.0F, 2.1F);
    Quadrat b(-1.0F, 0.5F, 2.0F);

    cout << endl << a << endl << b << endl;    // function operator<<() uses polymorphism

    if (a<b)
    {
        cout << "Flaeche von " << a.classname() << "  < als von " << b.classname() << endl;
    }
    else
    {
        cout << "Flaeche von " << b.classname() << " <= als von " << a.classname() << endl;
    }
    cout << endl;

    // dynamic memory allocation
    vector<Form*> v{new Kreis(a), new Quadrat(b), new Kreis(2.0F, 1.0F, 1.1F), new Quadrat(-1.0F, 1.5F, 1.9F),
        new Polygon(127)};

    // Sort ascending wrt. area
    cout << " SORT\n";
    sort(v.begin(),v.end(),kleiner);
    for (const auto pi : v) { cout << *pi << endl; } cout << "-------------\n";

    // Sort descending wrt. area; lambda function
    sort(v.begin(),v.end(),
         [](const Form *aa, const Form *bb) -> bool
         {
             return aa->area() > bb->area();
         }
         );
    for (auto *const pi : v) { cout << *pi << endl; } cout << "-------------\n";

    // distance matrix
    vector<vector<float>> distmatrix(v.size());       // #rows
    for (auto &di : distmatrix )  di.resize(v.size());                            // #cols per row (Reference !!)
//    for (vector<float> &di : distmatrix )  di.resize(v.size());                 // #cols per row (Reference !!)
//    for (size_t i=0; i<distmatrix.size(); ++i)  distmatrix[i].resize(v.size()); // #cols per row

    // calculate distances between objects
    for (size_t i=0; i<v.size(); ++i)
    {
        for (size_t j=0; j<v.size(); ++j)
        {
            distmatrix[i][j] = euclid_dist( v[i], v[j] );
            cout << i << "  " << j << "   " << distmatrix[i][j] << endl;
        }
    }

    // Output distances
    cout.precision(6);
    cout.setf(ios::fixed, ios::floatfield);     // arranges output in columns
    for (const auto &vi: distmatrix)            // Reference avoids copying, const ensures no changes
    {
        for (const auto vj: vi)
        {
            cout << vj << "  ";
        }
        cout << endl;
    }



    // deallocate dynamic memory
    for (auto &pi : v) { delete pi;}

    return 0;
}
