//		virtuelle Methoden
//		Richtig einsteigen in C++: p. 158-160

//	abgeleitet von a3_1.cpp
//	g++ -Wall a4_1.cpp employ.cpp

#include <iostream>
#include <vector>
#include "employ.hpp"
using namespace std;


int main()
{
 Employee  simple("Josef Gruber");

 WageEmployee hilf("Heiko");
 hilf.setWage(20.0f); hilf.setHours(7.8f);

 SalesPerson emp("Gundolf Haase");
 emp.setWage(hilf.getWage());  emp.setHours(hilf.getHours());
 emp.setComission(0.05f); emp.setSales(10000.0f);

 Manager man("Max Planck");
 man.setSalary(1000.0f);


 //	Basisklassenzeiger
 cout << endl << "           Basisklassenzeiger" << endl;


 vector<Employee*> liste(4);		// array von Pointern auf Employee


 liste[0] = &simple;
 liste[1] = &hilf;
 liste[2] = &emp;
 liste[3] = &man;

 cout << endl << "   Nur die Namen ausgeben" << endl;
 for (size_t i=0; i<liste.size(); ++i)
  {
      liste[i]->info();
  }

//		NEU !!
 cout << endl << endl << "   Name und (spezifisches) Gehalt klappen  j e t z t" << endl;
 for (size_t i=0; i<liste.size(); ++i)
  {
      liste[i]->payment();
  }

 return 0;
}


