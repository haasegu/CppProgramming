//		virtuelle Methoden
//		Richtig einsteigen in C++: p. 158-160
/*
Demonstration, daß mit virtuellen Funktionen ein übersetzter
Programmteil nachträglich verändert werden kann.
============================================================

von a4_2.cpp eine Funktion PrintListe separieren
--> a4_3.cpp liste.cpp liste.hpp
--> a4_3.cpp liste.cpp kompilieren und mit employ2.o linken

Neue Klasse BoxPromoter von Manager ableiten
--> bestech.hpp bestech.cpp
--> (geändertes) a4_3.cpp bestech.cpp kompilieren und mit employ2.o liste.o linken
!! PrintListe ruft die Methode payment() von BoxPromoter auf, obwohl
   diese Methode zur Kompilierungszeit unbekannt war !!
*/

#include <iostream>
#include <vector>
#include "employ2.hpp"
#include "bestech.hpp"		// NEW
#include "liste.hpp"		// !! employ2.hpp wird 2-mal eingebunden!!
using namespace std;


int main()
{
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

  // NEW
 BoxPromoter boxer("Larry King");
 boxer.setBestechung(19300.0);

 liste[0] = &boxer;
 liste[1] = &hilf;
 liste[2] = &emp;
 liste[3] = &man;

 PrintListe(liste);

 return 0;
}


