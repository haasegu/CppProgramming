// Demonstration von  C++ - vector
// Der notwendige Speicher wird bereitgestellt

//  g++ -std=c++11 -pedantic -Wall main.cpp

#include <iostream>
#include <vector>
using namespace std;

int main()
{
 const int N=11;
 vector<int> cc;          // Laenge 0;

 for (int i = 0; i < N; ++i )   // Laenge von Vektor aa: aa.size()
 {
    cc.push_back(i+1);
    cout << cc.size() << " :: " << cc.capacity() << endl;
 }

 cc.resize(N);          // Laenge 11, Capacity 16
 cout << cc.size() << " # resize  # " << cc.capacity() << endl;

 cc.reserve(2*N);          // Laenge 11, Capacity 22
 cout << cc.size() << " # reserve # " << cc.capacity() << endl;

 cc.erase( cc.begin()+4 , cc.end() ); // Laenge 4, Capacity 22
 cout << cc.size() << " # erase   # " << cc.capacity() << endl;

 vector<int> dd(cc);    // Laenge 4, Capacity 4
 cout << dd.size() << " * Copy-Konstr.          * " << dd.capacity() << endl;


 cc.shrink_to_fit(); // C++11: Laenge 4, Capacity 4
 cout << cc.size() << " * shrink_to_fit [C++11] * " << cc.capacity() << endl;

 return 0;
}
