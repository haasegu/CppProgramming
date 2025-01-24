//   Input from a file
//   Output  to a file
//   g++ -std=c++11 -Wall -Wextra -pedantic FileIO_a.cpp

#include <fstream>                // needed for ifstream and ofstream
#include <iostream>
using namespace std;

int main()
{
    int n_t, n_f;
//        input file
    ifstream infile("in.txt");

    cout << "Input from terminal: ";
    cin  >> n_t;

    cout << "Input from file " << endl;
    infile >> n_f;
//        check

    cout << endl;
    cout << "Input  from terminal was " << n_t << endl;
    cout << "Output from     file was " << n_f << endl;
    cout << endl;

//        output file
    ofstream outfile("out.txt");

    cout << "This is an output to the terminal" << endl;

    outfile << "This is an output to the file" << endl;

    return 0;
}










