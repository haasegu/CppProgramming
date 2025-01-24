//	Ex751-old.cpp
//
//		Calling functions defined in print810.cpp
//		without using a header file for declarations
//
//	Compile and Link:
//		g++ -c -Wall -pedantic printvec.cpp
//		g++ -c -std=c++11 -Wall -pedantic -fmax-errors=2 Ex751-old.cpp
//		g++ Ex751-old.o printvec.o
#include <vector>
using namespace std;
//			declarations of functions from printvec.cpp
void PrintVec(const vector<double> &x);
void PrintMat(const int nrow, const int ncol, const vector<double> &a);

int main()
{
    const int N = 4, M = 3;                 	// local constant
    // temp. C-Arrays
    const double data[] = {4, -1, -0.5,  -1, 4, -1,  -0.5, -1, 4, 3, 0, -1 };
    // static matrix a
    const vector<double> a(data,data + sizeof(data) / sizeof(data[0]));
          vector<double> u(N);
    
    for (size_t k=0; k<u.size(); ++k)  u[k] = data[k];

    PrintMat(N, M, a);			// print matrix

    PrintVec(u);			    // print vector
    return 0;
}









