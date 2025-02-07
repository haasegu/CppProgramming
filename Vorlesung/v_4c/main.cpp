// Vorlesung 21.03.2024
// Trennung von Deklaration (Headerfile) und Definition (Source)

#include "fkt.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    double d = 2.3;
    cout << sgn(d) << endl;

    float f = 2.3f;
    cout << sgn(f) << endl;

    cout << sgn("fsadsfadf") << endl;

    int b;
    set_value(b);

    float x;
    int k;
    cout << "x und k = ";
    cin >> x >> k;
    cout << mypow(x,k);

    return 0;
}

