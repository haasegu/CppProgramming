#include "file_io_bin.h"

#include <iostream>
#include <numeric>         // iota()
#include <string>
#include <vector>
using namespace std;

int main()
{
    {
        // generate binary file
        int    const N    = 100;
        double const SEED = -1.2345;
        vector<double> v(N);
        iota(begin(v), end(v), SEED);             // initialize data

        const string name2("data.bin");               // name of output file
        write_vector_to_binfile_C(name2, v);
        cout << "b i n ae r e s  File geschrieben." << endl;
    }

    {
        cout << "File  b i n ae r  einlesen." << endl;

        const string name("data.bin");              // name of input file
        vector<double> a;

        read_vector_from_binfile_C(name, a);

        for (size_t k = 0; k < a.size(); ++k) {
            cout << "  " << a.at(k);
        }
        cout << endl;
    }

    return 0;
}
