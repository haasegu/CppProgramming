#include <iostream>
#include <vector>
#include "employ2.hpp"	// Nur die Basisklasse ist notwendig!!

using namespace std;

void PrintListe(const vector<Employee*>& liste )
{


 cout << endl << "   Nur die Namen ausgeben" << endl;
 for (size_t i=0; i<liste.size(); ++i)
  {
    liste[i]->info();
  }

//		NEU !!
   cout << endl << endl << "   Name und (spezifisches) Gehalt klappt  j e t z t" << endl;
  for (size_t i=0; i<liste.size(); ++i)
  {
    liste[i]->payment();
  }

}
 
