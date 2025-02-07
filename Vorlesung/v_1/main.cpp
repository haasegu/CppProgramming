//  Vorlesung:  6.3.2020
#include <iostream>                //  cout, cin, endl

using namespace std;               //  vermeidet  std::


int main()                         //  Hauptprogramm als Funktion
{
    std::cout << "Hello world!  im SS 20" << std::endl;

    int d(5);                     // Deklaration und Initialisierung einer ganzen Zahl (32 bit)
    cout << " Variable = " << d<< endl;          // Wert der Variablen
    cout << " Adresse = " << &d<< endl;          // Anfangsadresse der Variablen im Speicher
    cout << " Byte = " << sizeof(d)<< endl;      // Anzahĺ der Bytes zur Speicherung der Variablen

    return 0;                      //  Rueckgabewert
}
