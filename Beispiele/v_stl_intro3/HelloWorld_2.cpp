//   erweitertes Hello-World-Programm
#include <iostream>                        // deklariert  cout, endl
#include <string>                          // deklariert Klasse string
using namespace std;                       // erlaubt Nutzung des Namensraumes std
                                           //      nutze  string  statt  std::string
int main()                                 // Beginn Hauptprogramm
{                                          // Beginn Scope
 cout << "Hello World" << endl;

 int i;                                    // Deklaration Ganzzahl-Variable i
 cout << " i = ";
 cin >> i;                                 // Einlesen eines Wertes fuer i
                                           // Ausgeben des Wertes von i
 cout << endl << " i ist gleich " << i << " eine ganze Zahl" << endl;
                                           //
 float a, b;                               // Deklaration Gleikomma-Variablen
 cout << " a b : " ;
 cin >> a >> b;
 cout << " ::  " << a << "  " << b << endl;//	`endl' - new line
                                           //
 float c = a+b;                            // Deklaration und Definition von c
 const string ss(" c :: ");                // Deklaration und Definition von ss
 cout << ss << c << endl;

 return 0;                                 // Beende das Programm
}                                          // Ende Scope, Ende Hauptprogramm









