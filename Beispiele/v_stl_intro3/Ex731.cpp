//	Ex731.cpp

//	Sec. 7.3 of lecture
//		Function without return value

#include <iostream>
using namespace std;

void spass(const int);                  // Declaration of spass()

int main()
{
    int n;
    cout << endl << " Eingabe n : ";  cin  >> n;
    
    spass(n);                          // Call spass()

    return 0;
}


void spass(const int n)                 // definition of spass()
{
    cout << endl << "Jetzt schlaegt's aber " << n << endl << endl;
    return;
}









