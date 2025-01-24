// Demonstration von  C++ - valarray
// Der notwendige Speicher wird bereitgestellt
// Vektorarithmetik ist vorhanden

#include <iostream>
#include <valarray>
using namespace std;

int main()
{
 valarray<double> aa(5);       // double-vector der Laenge 5
 valarray<double> bb(3.1, 5);  // double-vector der Laenge 5 mit 3.1 initialisiert
 valarray<double> cc;          // double-vektor der Lange 0;

 cc.resize(aa.size());         //  cc wird 5 lang
 for (unsigned int i = 0; i < aa.size(); ++i )   // Laenge von Vektor aa: aa.size()
 {
    aa[i] = i+1;
 }

  cc = aa + bb;                // Vektorarithmetik
  cc = sqrt(cc/aa) + atan(bb);

 for (unsigned int i = 0; i < cc.size(); ++i )
 {
    cout << cc[i] << "   ";
 }
 cout << endl;

 return 0;
}
 
