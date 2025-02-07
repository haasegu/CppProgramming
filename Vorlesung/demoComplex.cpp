//				Komplexe Zahlen
#include <iostream>
#include <complex>	//	complexe Zahlen [Prinz, p677ff]
using namespace std;

int main()
{
 const complex<double>  IMAG(0.0,1.0);    // Definition der imaginaeren Einheit
 complex<double> a, b(3.0,-1.0);
 complex<float>  c(-0.876, 2.765), d(c);

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



