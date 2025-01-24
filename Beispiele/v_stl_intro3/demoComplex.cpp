//				Komplexe Zahlen
#include <complex>                        //	complexe Zahlen 
#include <iostream>
using namespace std;

int main()
{
 const complex<double>  IMAG(0.0,1.0);    // Definition der imaginaeren Einheit
 complex<double> a, b(3.0,-1.0);          // a := 0 + 0 i, b := 3-i
 complex<float>  c(-0.876f, 2.765f), d(c);// c := -0.876 + 2.765 i,  c:=d

 cout << "a = " << a << "   b = " << b << "   c = " << c << endl;
 cout << "real b = " << real(b) << "   imag b = " << imag(b) << endl;

 b /= 3.0;
 a += c;
 cout << "c+b/3 = " << a+b << "   c/b = " <<  a/b << endl;

 cout << " d = " << d << endl;
 cout << "Polarkoord:  betrag= " << abs(d) << "   phi= " << arg(d) << endl;
 cout << " und wieder zurueck:  " << polar(abs(d), arg(d)) << endl;

 cout << "sqrt(d) = " << sqrt(d) << endl;

 return 0;
}



