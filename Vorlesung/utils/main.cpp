#include "timing.h"             // tic(), toc()
#include "info.h"             
#include "std_lib_facilities.h" // overload [] : by Stroustrup
#include <iostream>
using namespace std;

int main(int argc , char const *argv[])
{
    cout << "Check my own headers\n" << endl;

    tic();                    // start timer
    check_env(argc, argv);         // info on compiler
    printGPUInfo();                // info on GPU. Only in NVCC_
    double tt(toc());         // end timer
    cout << "\n\nSeconds: " << tt << endl;

    vector<double> aa(5,-1.2345);
    try
    {
        cout << "\nThe next line should result in an exception\n";
        cout << aa[5] << endl;// Stroustrups overloading should check the index range
    }
    catch (Range_error &re)
    {
        cout << "Index out of range!!!\n";
    }
    
    return 0;
}

