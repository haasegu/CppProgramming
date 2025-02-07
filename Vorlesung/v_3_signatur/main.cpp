#include <iostream>

using namespace std;


double square(double x)
{
    cout << "  -->  double" << endl;
    return x*x;
}


int square(int x)
{
    cout << "  -->  int" << endl;
    return x*x;
}


int main()
{
    cout << "Hello world!" << endl;

    int    ia(2),ib;
    double da(2.65),db;
    float  fa(2.65f),fb;

    ib = square(ia);
    cout << "int    : (" << ia << ")^2  = " << ib << endl;

    db = square(da);
    cout << "double : (" << da << ")^2  = " << db << endl;

    fb = square(fa);
    cout << "float  : (" << fa << ")^2  = " << fb << endl;

//    char ca('a'), cb;
//    cb = square(ca);
//    cout << "char   : (" << ca << ")^2  = " << cb << endl;
//    cout << "char   : (" << static_cast<int>(ca) << ")^2  = " << static_cast<int>(cb) << endl;

    return 0;
}
