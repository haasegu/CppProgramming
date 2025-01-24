// Demonstration von  C++ - vector: Dynamisch wachsender Vektor
#include <iostream>
#include <vector>
using namespace std;

int main()
{
 vector<int>    dd;         // int-vector der Laenge 0

 dd.push_back(-34);         // Laenge 1  Elemente  [-34]
 dd.push_back(3);           // Laenge 2: Elemente  [-34, 3]
 dd.push_back(0);           // Laenge 3: Elemente  [-34, 3, 0]
 
 cout << "Vektorlaenge: " << dd.size() << "  dd[0] : " << dd[0] << endl;
 
 dd.pop_back();             // Laenge 2: Elemente  [-34, 3]
 cout << "Vektorlaenge: " << dd.size() << endl;

 return 0;
}
