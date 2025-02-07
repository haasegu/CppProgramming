// g++ -std=c++11 main.cpp

#include <iostream>
using namespace std;

constexpr int int_pow(int b, int e, int res = 1)
{
    return (e == 0) ? res : int_pow(b, e - 1, b * res);
}

constexpr int my_pow(const int b, const int e)
{
    return (e == 0) ? 1 : b*my_pow(b,e-1);
}

int main()
{
    cout << "Pow(int,int) via recursive function and constexpr" << endl;

    //
    int b = 3;
    int e = 5;
    cout << b << "^" << e << " = " << int_pow(b,e)  << "    " << my_pow(b,e)<< endl;

    cout << " b = ";
    cin >> b;
    cout  << " e = ";
    cin >> e;
    cout << b << "^" << e << " = " << int_pow(b,e)  << "    " << my_pow(b,e) << endl;

    return 0;
}
