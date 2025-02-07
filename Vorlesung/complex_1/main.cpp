#include "komplex.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    const Komplex a(-1.5, 2.0);  // Konstruktoraufruf.
    cout << a.Get_re() << " " << a.Get_im() << endl;
    cout << " abs : " << a.abs() << endl;

    Komplex b = a;
    b.Set_re(4.2);
    b.Set_im(-1.2);
    cout << b.Get_re() << " " << b.Get_im() << endl;

    Komplex c = a+b;
    cout << c.Get_re() << " " << c.Get_im() << endl;

    cout << "----------------------\n";
    cout << a << " " << c << endl;



    return 0;
}
