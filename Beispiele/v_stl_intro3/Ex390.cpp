#include <iostream>
#include <limits>                                //    numeric_limits
using namespace std;

int main()
{
 cout << "max(double)  " << numeric_limits<double>::max()     << endl;
 cout << "min(float)  "  << numeric_limits<float> ::min()     << endl;
 cout << "min(int)  "    << numeric_limits<int>   ::min()     << endl;
 cout << "eps(float)  "  << numeric_limits<float> ::epsilon() << endl;
 return 0;
}
