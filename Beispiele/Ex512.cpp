//	Ex512.cpp

//	Sec. 5.1 of lecture
//	Array: L_2 norm

#include <iostream>
#include <cmath>                 // sqrt()
using namespace std;

int main()
{
    const int N = 10;
    double x[N];
//                               Initialize x
    for (int i = 0; i < N ; ++i) {
        x[i] = sqrt(i + 1.0);
    }
//                               L_2 norm calculation
    double norm = 0.0;
    for (int i = 0; i < N; ++i) {
        norm += x[i] * x[i];
    }
    norm = sqrt(norm);

    cout << endl;
    cout << "  L2-norm : " << norm << endl;
    cout << endl;

    return 0;
}









