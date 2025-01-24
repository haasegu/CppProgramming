//	Format.cpp
//    g++ -Wall -pedantic Format.cpp

#include <iomanip>                // setw()
#include <iostream>
using namespace std;

int main()
{
    const double da = 1.0 / 3.0,
                 db = 21. / 2.0,
                 dc = 1234.56789;

    cout << endl;
    cout << " Vergleich von Ausgabeformaten " << endl << endl;

    cout << "Standard : " << endl;
    cout << da << endl << db << endl << dc << endl << endl;

//	Mehr Stellen
    cout.precision(12);
    cout << "Genauigkeit ist cout.precision(12) : " << endl;
    cout << da << endl << db << endl << dc << endl << endl;

//	Feste Anzahl von Nachkommastellen
    cout.precision(6);
    cout.setf(ios::fixed, ios::floatfield);
    cout << "Fixstellen ist cout.setf(ios::fixed, ios::floatfield) : " << endl;
    cout << da << endl << db << endl << dc << endl << endl;

//	Ausgabe mit Exponent
    cout.setf(ios::scientific, ios::floatfield);
    cout << "Exponnet ist cout.setf(ios::scientific, ios::floatfield) : " << endl;
    cout << da << endl << db << endl << dc << endl << endl;

//	Zurueck zur Standardausgabe
    cout.setf(ios::floatfield);
    cout << "Standard ist cout.setf(0, ios::floatfield) : " << endl;
    cout << da << endl << db << endl << dc << endl << endl;

//	Ausrichtung und Platzhalter
    cout.setf(ios::right, ios::adjustfield);
    cout << "Ausrichtung ist cout.setf(ios::right, ios::adjustfield) : " << endl;
    cout << "Platzhalter ist  cout.width(16) : " << endl;
    cout.width(16); 			// vor jeder Ausgabe
    cout << da << endl;
    cout.width(16); 			// vor jeder Ausgabe die Methode rufen
    cout << db << endl;
//  cout.width(16); 			// vor jeder Ausgabe
    cout << setw(16) << dc << endl << endl;
//		Allg. Loesung erfolgt ber Standardmanipulatoren
//			--> Stroustrup;  1.4.6.2 , p.679


//	Hex-ausgabe
    cout.setf(ios::hex, ios::basefield);
    cout << "Hex ist cout.setf(ios::hex, ios::basefield) : " << endl;
    cout << da << endl << db << endl << dc << endl << endl;
    cout << "127 = " << 127 << endl;
    
    cout.setf(ios::dec, ios::basefield);
    cout << "127 = " << 127 << endl;
    cout << "Alternatively:  " << endl;
    cout << hex;
    cout << "127 = " << 127 << endl;
    
//  Boolean Ausgabe
    cout << true << " " << false << endl;
    cout << boolalpha;
    cout << true << " " << false << endl;

    return 0;
}









