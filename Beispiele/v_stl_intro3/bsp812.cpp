//  g++ -std=c++11 -Wall -Wextra -pedantic bsp812.cpp

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
    ofstream outfile(outfilename);     // Ausgabefile oeffnen

    while (infile.good()) {
        char ch;
        infile.get(ch);                // Zeichenweises lesen
        outfile.put(ch);               // Zeichenweises schreiben
    }

    return 0;
}
