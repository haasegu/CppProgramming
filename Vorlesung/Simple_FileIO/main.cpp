/* Beschreibung: Hier handelt es sich um ein Minimalbeispiel, das zeigen
   soll, wie man in C++ ganz grundsätzlich mit Textdateien arbeiten kann.
   Funktionalität: Wir lesen eine Textdatei in.txt Zeile für Zeile ein und
   speichern die die Zeilen jeweils rückwärts in out.txt.
   Wichtig: C++11 Compiler-Flag aktivieren!
   Author: Andreas Kucher, 2015
*/

#include <algorithm>  // Für std::revese(...)
#include <cassert>    // assert(); Programmausstieg mit Fehler.
#include <fstream>    // "Arbeiten mit Files"
#include <iostream>

/* Diejenigen, die using "namespace std;" verwenden möchten, können im weiteren
   Programm auf "std::" verzichten! */

// using namespace std;

int main()
{
    std::string input_file("in.txt");   // Name der einzulesenden Datei.
                                        // Muss normalerweise im selben Ordner
                                        // wie main.exe liegen! Bei Ausfuehrung
                                        // ueber CodeBlocks im selben Ordner wie
                                        // das Projektfile.
    std::string output_file("out.txt"); // Name der auszugebenden Datei.

    // Stream auf die zu lesende Datei.
    std::ifstream in_file(input_file, std::ofstream::in);

    // Überprüfen, ob das Öffnen der Datei erfolgreich war.
    if(in_file.fail())
        assert("Fehler beim Oeffnen der Datei");// Quick'n'dirty
                                                // Programmabbruch

    // Stream auf die zu schreibende Datei
    std::ofstream out_file(output_file, std::ofstream::out);

    // Überprüfen, ob das Öffnen/Anlegen der Datei erfolgreich war.
    if(out_file.fail())
        assert("Fehler beim Oeffnen der Datei");// Quick'n'dirty
                                                // Programmabbruch

    // Solange das Ende der zu lesenden Datei noch nicht erreicht wurde...
    while(!in_file.eof()) {
        std::string line;
        std::getline(in_file,line); // "in_file >> line" würde nicht
                                    // ganze Zeilen auf einmal einlesen,
                                    // sondern nur bis zum nächsten Leerzeichen.

        std::reverse(line.begin(),line.end()); // String umdrehen mit STL
        std::cout << line << std::endl;        // In Terminal schreiben
        out_file << line << std::endl;         // In die Datei out.txt schreiben.
        //out_file.flush();  // Erst damit ist garantiert, dass die Zeile tatsächlich
                             // in out.txt geschrieben wurde und nicht nur in einem
                             // buffer liegt! An dieser Stelle für unsere Zwecke
                             // nicht notwendig.
    }

    in_file.close();
    out_file.close(); // Erst hier ist garantiert, dass die geschriebenen
                      // Strings nicht nur in einem Zwischenpuffer liegen,
                      // sondern auch "in der datei selbst".
                      // Alternative ohne den Stream zu schließen:
                      //       out_file.flush();

    return 0;
}
