// g++ -std=c++11 main.cpp

#include <iostream>
#include <sstream>           // ostringstream  : 2nd method
#include <string>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    //
    string base="out_p_";
    for (int k=0; k<5; ++k)
    {
        string filename = base + to_string(k)+".txt";
        cout << filename << endl;
    }

    //  other opportunity: 2nd method
    //  http://www.cplusplus.com/reference/sstream/ostringstream/?kw=ostringstream
    //  http://www.cplusplus.com/reference/sstream/ostringstream/ostringstream/
    const int PLZ=8020;
    ostringstream instr;
    instr << PLZ;                    // number into stream

    const string sPLZ = instr.str(); // get string from stream

    cout << "check string : " << sPLZ << endl;

    return 0;
}
