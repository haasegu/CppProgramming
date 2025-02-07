//     Simple class demo
//  g++ -std=c++11 -Wall -W -Wfloat-equal -Wshadow -Wredundant-decls -Weffc++ -pedantic main.cpp form.cpp
#include <iostream>
#include <vector>            // vector
#include <algorithm>         // sort
#include "form.h"
using namespace std;

//----------    Hauptprogramm  (nicht veraendern!!)   ----------------------
int main()
{
    const Kreis   a( 0.0f, 1.0f, 2.1f);
    Quadrat b(-1.0f, 0.5f, 2.0f);

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
    vector<Form*> v{new Kreis(a), new Quadrat(b), new Kreis(2.0f, 1.0f, 1.1f), new Quadrat(-1.0f, 1.5f, 1.9f)};

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
    for (const auto pi : v) { cout << *pi << endl; } cout << "-------------\n";

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
    for (const auto pi : v) { delete pi; }

    return 0;
}
