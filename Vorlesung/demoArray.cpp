// Demonstration von  C++11 - array
// Der notwendige Speicher wird bereitgestellt
// Keine Vektorarithmetik

#include <iostream>
#include <array>
using namespace std;

int main()
{
 array<int,5>    aa;                    //    int-array der Laenge 5, uninitialized : [???, ???, ???, ???, ???]
 array<double,5> bb;                    // double-array der Laenge 5, uninitialized : [???, ???, ???, ???, ???]
 array<double,5> cc{3.1,-1.2,2,3,4.5};  // double-array der Laenge 5,   initialized : [3.1,-1.2,   2,   3, 4.5]

 //cc.resize(aa.size());      //  geht nicht
  for (unsigned int i = 0; i < aa.size(); ++i )   // Laenge von Vektor aa: aa.size()
 {
    aa[i] = i+1;
    bb[i] = 3.1;
    cc[i] = aa[i]+bb[i];
 }

 for (unsigned int i = 0; i < cc.size(); ++i )
 {
    cout << cc[i] << "   ";
 }
 cout << endl;

 cout << "letztes Element von aa " << aa.back() << " , Laenge aa ist " << aa.size() << endl;
 // Hange ein Element an das Ende an.
 // aa.push_back(77);  // Geht nicht
 // cout << "letztes Element von aa " << aa.back() << " , Laenge aa ist " << aa.size() << endl;
 // Entferne letztes Element
 // aa.pop_back();  // Geht nicht
 // cout << "letztes Element von aa " << aa.back() << " , Laenge aa ist " << aa.size() << endl;
 // Verlaengere aa auf die Laenge 20;
 //aa.resize(20);   // Geht nicht
 aa[2] = aa[3]+aa.at(4);      // sicherer Zugriff mit at()


 return 0;
}

