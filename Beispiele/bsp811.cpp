//  g++ -std=c++11 -Wall -Wextra -pedantic bsp811.cpp

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string  infilename, outfilename;

    cout << " Input file: ";
    cin >> infilename;
    cout << "Output file: ";
    cin >> outfilename;

    ifstream  infile(infilename);      // Eingabefile oeffnen
    if ( !infile.is_open() ) {         // Absicherung, falls File nicht existiert
        cout << "\nFile " << infilename << " has not been found.\n\n" ;
        assert( infile.is_open() );    // exeption handling for the poor programmer
    }

    ofstream outfile(outfilename);     // Ausgabefile oeffnen

    while (infile.good()) {
        string str;
        infile >> str;
        outfile << str;
    }
    
    outfile.close();                   // Ausgabefile schliessen      
    

    return 0;
}                                      // automatisches Schliessen des Eingabefiles
