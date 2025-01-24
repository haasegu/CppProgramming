// Ausgabe eines C++ - vectors
#include <iostream>
#include <iterator>                             // ostream_iterator fuer Variante 2
#include <vector>
using namespace std;

//            operator overloading fuer   operator<<
ostream& operator<<(ostream& s, const vector<double>& v)// Funktion fuer Variante 3
{
    for (unsigned int k=0; k<v.size(); ++k)  s << v[k] << "  ";  //nutzt Variante 1
    return s;
}

int main()
{
 vector<double> bb(5, 3.1);  // double-vector der Laenge 5  mit 3.1 initialisiert

 for (unsigned int k=0; k<bb.size(); ++k)  cout << bb[k] << "  ";     // Variante 1

 copy(bb.begin(),bb.end(),ostream_iterator< double,char >(cout,"  "));// Variante 2

 cout << bb;                                                          // Variante 3

 return 0;
}
