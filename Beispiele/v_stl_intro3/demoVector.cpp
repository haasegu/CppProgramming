// Demonstration von  C++ - vector
// Der notwendige Speicher wird dynamisch bereitgestellt

#include <iostream>
#include <vector>
using namespace std;

int main()
{
 //    int-vector der Laenge 5       uninitialisiert : [???, ???, ???, ???, ???]    
 vector<int>    aa(5);
 // double-vector der Laenge 5 mit 3.1 initialisiert : [-3.1, -3.1, -3.1, -3.1, -3.1]  
 vector<double> bb(5, -3.1);
 //  float-vector der Laenge 2 via  initializer list : [5, 3.1]
 vector<float>  dd{5,3.1F};
 // double-vector der Laenge 0;                      : []
 vector<double> cc;

 cc.resize(aa.size());   //  cc wird 5 Elemente lang : [???, ???, ???, ???, ???]
 for (unsigned int i = 0; i < aa.size(); ++i )   // Laenge von Vektor aa: aa.size()
 {
    aa[i] = i+1;
    cc[i] = aa[i]+bb[i];
 }

 for (size_t i = 0; i < cc.size(); ++i )   // Ausgabe des Vektors
 {
    cout << cc[i] << "   ";
 }
 cout << endl;

 return 0;
}
 
