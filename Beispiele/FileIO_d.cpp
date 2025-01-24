//   g++ -std=c++11 -Wall -Wextra -pedantic FileIO_d.cpp

//	Switch between Standard-IO (terminal) and
//		Input from a file
//		Output  to a file
// 	via command line argument : version2

// 	command line:
//	a.out -fo -fi

//#include <stdlib.h>		// needed for exit
#include <cstdlib>		// needed for exit
#include <cstring>              // needed for strcmp
#include <fstream>		// needed for ifstream and ofstream
#include <iostream>
#include <string>
using namespace std;

void CheckOptions(const int argc, const char *argv[], bool &bin, bool &bout);
void GetIOStreams(const int argc, const char *argv[],
                  istream *&myin, ostream *&myout);

int main(const int argc, const char *argv[])
{
    int  n;
//			variables for IO streams
    istream  *myin  = 0;
    ostream  *myout = 0;

//	Decide whether terminal-IO or file-IO should be used
    GetIOStreams(argc, argv, myin, myout);

    (*myout) << "Input: ";
    (*myin)  >> n;
//			check
    (*myout) << endl;
    (*myout) << "Input was " << n << endl;
    (*myout) << endl;
    (*myout) << "This is an additional output" << endl;

    return 0;
}

// ----------------------------------------------------------------
void CheckOptions(const int argc, const char *argv[], bool &bin, bool &bout)
{
    const char FIN[]  = "-fin",
               FOUT[] = "-fout";
    bool bb[3];

    if (argc >= 4) {
        cout << "Wrong number of arguments in " << argv[0] << endl << endl;
        cout << "command:  " << argv[0]
             << " [" << FIN << "] [" << FOUT << " ]" << endl;
        exit(-10);				// Abort programm
    }

    bin = bout = false;
    for (int i=1; i <= argc - 1; ++i) {
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

// ----------------------------------------------------------------
void GetIOStreams(const int argc, const char *argv[],
                  istream *&myin, ostream *&myout)
{
    const string  infilename("in.txt"), outfilename("out.txt");
    bool bin, bout;

    CheckOptions(argc, argv, bin, bout);

//			input file
    istream *infile  = new ifstream(infilename);

    if (bin) {
        if ( infile->bad()) {	// Does input file exist ?
            cout << "File " << infilename
                 << " nicht vorhanden" << endl;
            exit(-1);
        }
    }
//			output file
    ostream *outfile = new ofstream(outfilename);

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

    return;
}












