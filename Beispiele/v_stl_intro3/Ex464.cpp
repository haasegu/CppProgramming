//	(Reihe.cpp) --> Ex464.cpp
//
//			Sum 1/k
//			limited accuracy

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    const float Eps = 1e-8f;	// sum only the first 10000 elements
    int n ;

    cout << endl << "Demo for precision of float and saving of arithmetics" << endl;
    cout << endl << " n =  ";
    cin >> n;
// n = 65000;
//			Exact result
    float s = 0.0f;
    for (int i = n; i >= 1; --i) {
        s += 1.0f / i / i;
    }

    const double s_korrekt = M_PI * M_PI / 6.0;
    cout << endl << "exact   s = " << s
         << "  Fehler:  "  << s_korrekt - static_cast<double>(s) << endl << endl;

//			Old appr. result 1

    float s1{0.0f};
    for (int i = 1; i <= n; ++i) {
        s1 += 1.0f / i / i;
    }

    cout << endl << "app.1   s = " << s1 << endl << endl;

//			Appr. result 2

    float s2{0.0f};
    for (int i = 1; i <= n; ++i) {
        float tmp = 1.0f / i / i;
        if (tmp > Eps)
            s2 += tmp;
    }

    cout << endl << "app.2   s = " << s2 << endl << endl;

//			Appr. result 2

    float s3{0.0f};
    int i  = 1;
    float tmp = 1.0f / i / i;
    while ( tmp > Eps  && i <= n  ) {
        s3 += tmp;
        ++i;
        tmp = 1.0f / i / i;
    }

    cout << endl << "app.3   s = " << s3 << endl << endl;
    return 0;
}









