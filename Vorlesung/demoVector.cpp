// Demonstration von  C++ - vector
// Der notwendige Speicher wird bereitgestellt
// Keine Vektorarithmetik

#include <iostream>
#include <vector>
using namespace std;

int main()
{
 vector<int>    aa(5);       //    int-vector der Laenge 5       uninitialisiert : [???, ???, ???, ???, ???]
 vector<double> bb(5, 3.1);  // double-vector der Laenge 5 mit 3.1 initialisiert : [3.1, 3.1, 3.1, 3.1, 3.1]
 vector<float>  dd{5,3.1};   //  float-vector der Laenge 2 über initializer list : [5, 3.1]
 vector<double> cc;          // double-vector der Laenge 0;                      : []

 cc.resize(aa.size());      //  cc wird 5 Elemente lang                          : [???, ???, ???, ???, ???]
 for (unsigned int i = 0; i < aa.size(); ++i )   // Laenge von Vektor aa: aa.size()
 {
    aa[i] = i+1;
    cc[i] = aa[i]+bb[i];
 }

 for (unsigned int i = 0; i < cc.size(); ++i )
 {
    cout << cc[i] << "   ";
 }
 cout << endl;

 cout << "letztes Element von aa " << aa.back() << " , Laenge aa ist " << aa.size() << endl;
 // Hange ein Element an das Ende an.
 aa.push_back(77);
 cout << "letztes Element von aa " << aa.back() << " , Laenge aa ist " << aa.size() << endl;
 // Entferne letztes Element
 aa.pop_back();
 cout << "letztes Element von aa " << aa.back() << " , Laenge aa ist " << aa.size() << endl;
 // Verlaengere aa auf die Laenge 20;
 aa.resize(20); // Achtung aa[5...19] sind nicht initialisiert !
 aa[6] = aa[3]+aa.at(4);      // sicherer Zugriff mit at()
 
 
 
 
 
 
// Zugriff auf Elemente ausserhalb des Indexbereichs.
// g++ -DDEMO_RANGE demoVector.cpp
 #ifdef DEMO_RANGE
 //     Ungesichert
 cout << "Access to bb[5]   : \n";
 cout << bb[5]    << "      Done" << endl;
 //     Gesichert
 cout << "Access to bb.at(5): \n";
 //           without catching exception
 //cout << bb.at(5) << "      Done" << endl;
 //           catch exception
 try{
     cout << bb.at(5) << "      Done" << endl;
 }
 catch(std::out_of_range)
 {
     cout << "Don't access a vector outside its index range!" << endl;
 }
 #endif

 return 0;
}

