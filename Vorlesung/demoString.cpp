// Demonstration von  C++ - string
// Der notwendige Speicher wird automatisch bereitgestellt

#include <iostream>
#include <string>
using namespace std;

int main()
{
 string aa("Das ist der erste String");
 string bb;

 if (bb.empty())                  // Test auf leeren String
 {
   cout << "String bb ist noch leer" <<endl;
 }

 bb = "zweiter String";
 // cin >> bb;                     // direkte Eingabe eines Strings

 string cc=aa + " und " + bb;      // Strings aneinanderhaengen

 cout << cc << endl;
                                   // Laenge des Strings ausgeben
 cout << " ist " << cc.size() << " Zeichen lang." << endl;

 string dd(cc);                    // String dd hat gleiche Laenge wie aa
                                   //   und gleiche Daten
 for (unsigned int i=0; i<dd.size(); ++i)
 {
     cout << dd[i] << " ";         // Ausgabe i-tes Zeichen von dd
 }

 cout << endl << "#"<< dd[6] <<endl;
 cout << endl << ":"<< dd.at(6) <<endl;  // sicherer Zugriff

 return 0;
}

