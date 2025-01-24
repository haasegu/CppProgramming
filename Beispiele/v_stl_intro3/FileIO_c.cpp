//   g++ -std=c++11 -Wall -Wextra -pedantic FileIO_c.cpp

//	Switch between Standard-IO (terminal) and
//		Input from a file
//		Output  to a file
// 	via command line argument

// 	command line:
//	a.out -fo -fi

#include <cstdlib>		// needed for exit
#include <cstring>            // needed for strcmp
#include <fstream>		// needed for ifstream and ofstream
#include <iostream>
using namespace std;

void CheckOptions(const int argc, const char *argv[], bool &bin, bool &bout);

int main(const int argc, const char *argv[])
{
//			variables for IO streams
    istream  *myin;
    ostream  *myout;
//			input file
    istream *infile  = new ifstream("in.txt");
//			output file
    ostream *outfile = new ofstream("out.txt");

//	Still standard IO
//	Decide whether terminal-IO or file-IO should be used

    bool bin, bout;
    CheckOptions(argc, argv, bin, bout);

    if (bin) {
        // Remaining Input via file
        myin  = infile;
    }
    else {
        // Remaining Input via terminal
        myin  = &cin;
    }

    if (bout) {
        // Remaining Output via file
        myout = outfile;
    }
    else {
        // Remaining Output via terminal
        myout = &cout;
    }

    int  n;
    (*myout) << "Input: ";
    (*myin)  >> n;

    (*myout) << endl;  // check
    (*myout) << "Input was " << n << endl;
    (*myout) << endl;



    (*myout) << "This is an additional output" << endl;

    delete  outfile;
    delete  infile;

    return 0;
}


void CheckOptions(const int argc, const char *argv[], bool &bin, bool &bout)
{
    const char FIN[]  = "-fin",
               FOUT[] = "-fout";
    bool bb[3];

    if (argc == 1 || argc >= 4) {
        cout << "Wrong number of arguments in " << argv[0] << endl << endl;
        cout << "command:  " << argv[0] << " [-fin] -fout " << endl;
        exit(-10);					// Abort programm
    }

    bin = bout = false;
    for (int i = 1; i <= argc - 1; ++i) {
        bin  = bin  || strcmp(argv[i], FIN) == 0;
        bout = bout || strcmp(argv[i], FOUT) == 0;
        bb[i] = strcmp(argv[i], FIN) == 0 || strcmp(argv[i], FOUT) == 0;
        if (! bb[i]) {
            cout << " Option  " << argv[i] << "  is not valid" << endl;
            cout << " Use Options  " << FIN << "  or/and  " << FOUT << endl;
            exit(-i);
        }
    }

    return;
}









