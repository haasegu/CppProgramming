// Vorlesung 12.04.2024: File-IO
#include <fstream>                           // ifstream, ofstream
#include <iostream>

using namespace std;

int main()
{
    ofstream out_file("out.txt");             // Stream fuer Outputfile
    out_file << "HeLLo worLd!" << endl;       // Ausgabe darauf

    string fstring("my_in.txt");
    //ifstream in_file(fstring.c_str());      // alt: C-String als Filename benoetigt
    ifstream in_file(fstring);                // C++11 C++-String als Filename
    string c1,c2;
    in_file >> c1 >> c2;
    cout << c1 << c2 << endl;

    double d;
    in_file >> d;
    cout << d << endl;

    {
        ifstream tmp("my_in.txt");
        string name;                  //  lies eine ganze Zeile des Inputfiles
        getline(tmp,name);            //       als String ein
        cout << name << endl;
    }

    return 0;
}
