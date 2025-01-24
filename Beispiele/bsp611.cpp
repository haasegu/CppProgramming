//	Ex611.cpp

//	Sec. 6.3 of lecture
//	Reference
//	i, ri, *pi are different names for one variable

#include <iostream>
using namespace std;

int main()
{
    int   i;                       // variable 'i'
    int &ri = i;                   // declaration reference on 'i'
    int *pi;

    pi = &i;                       // define 'pi' as pointer on 'i';

    i = 7;
    cout << endl << "     i = " << i
         << " ,  ri = " << ri
         << " , *pi = " << *pi;

    ++ri;
    cout << endl << "     i = " << i
         << " ,  ri = " << ri
         << " , *pi = " << *pi;

    ++(*pi);
    cout << endl << " ,   i = " << i
         << " ,  ri = " << ri
         << " , *pi = " << *pi;
    cout << endl;
    return 0;
}









