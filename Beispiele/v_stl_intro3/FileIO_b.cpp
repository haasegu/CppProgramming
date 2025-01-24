//	Switch between Standard-IO (terminal) and
//		Input from a file
//		Output  to a file
//   g++ -std=c++11 -Wall -Wextra -pedantic FileIO_b.cpp


#include <fstream>		// needed for ifstream and ofstream
#include <iostream>
using namespace std;

int main()
{
//          variables for IO streams: pointers !!
    istream  *myin;
    ostream  *myout;
//          input file
    istream *infile  = new ifstream("in.txt");
//          output file
    ostream *outfile = new ofstream("out.txt");

//	Still standard IO
//	Decide whether terminal-IO or file-IO should be used
    int tf;
    cout << "Input from terminal/file - Press 0/1 : ";
    cin  >> tf;
    bool bf = (tf == 1);

    if (bf) {                 // Remaining IO via file
        myin  = infile;
        myout = outfile;
    }
    else {                    // Remaining IO via terminal
        myin  = &cin;
        myout = &cout;
    }


    int n;
    (*myout) << "Input: ";
    (*myin)  >> n;

    (*myout) << endl;         // check
    (*myout) << "Input was " << n << endl;
    (*myout) << endl;



    (*myout) << "This is an additional output" << endl;

    delete  outfile;          // don't forget to deallocate
    delete  infile;

    return 0;
}










