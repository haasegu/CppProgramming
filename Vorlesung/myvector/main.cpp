//      Restrict the available memory in a bash-shell by
//      ulimit -m 1024
//                                   see also  ulimit -a
//      g++ -Wall -Weffc++ main.cpp myvector.cpp myexceptions.cpp provocate.cpp

// GH: uncomment next line to demonstrate incorrect class setup with pointers
//#define WRONG_CODE

#include "myexceptions.h"
#include "myvector.h"
#include "provocate.h"
#include <cstdio>             // sprintf
#include <cstdlib>            // system
#include <iostream>


using namespace std;


int main()
{
    long long int n;
    long long int i;

//			Neuen New-Handler setzen
//set_new_handler( my_new_handler );

    cout << " n = ";
    cin >> n;
    //n = 2ll<<34;

    try
    {
        MyVector AA(n);
    }
    catch (bad_alloc&)
    {
        cout << "Jetzt hab ich Dich ################" << endl;
    }
    catch (...)
    {
        cout << "noch einer" << endl;
    }
    cout << "------------"<< n <<"-----------------------------\n";
    MyVector aa(n);
    for (i=0; i<n; i++)
    {
        aa[i] = static_cast<double>(i+1)*3.14;
    }
//cout << aa << endl;
    cout << "##############" << aa.size()<< "###################\n";
    try
    {

        aa[3] = 4.5 + aa[2];
        cout << aa[3] << endl;

//        const MyVector bb( aa );
//        Provocate(bb,13);
        Provocate(aa,13);
    }
    catch (bad_alloc&)
    {
        cout << "##########  Hey bad allocation ################" << endl;
    }
    catch (OutOfRange &err)
    {
        cerr << endl << "---------------------------------------------------\n";
        cerr << "Indexerror: " << err.Index() << "   " << err.Interval_End() << endl;
        cerr << __FILE__ << ":line " << __LINE__ << "   from " << __DATE__ << "  " << __TIME__<<endl;
//   system("echo ""Du hast Mist gebaut."" | mail -s ""Indexerror"" gundolf.haase@uni-graz.at");

//		Provide more information
        string serr(__FILE__);
        serr += ":line ";
        char tmp[10];
        sprintf(tmp, "%d", __LINE__);
        serr += tmp;
        serr += "   from  ";
        serr += __DATE__;
        serr += "  ";
        serr += __TIME__;
        serr += ".";
//   cerr << serr << endl;
        string serr2 = string("echo ") + serr +  " | mail -s \"Indexerror\" gundolf.haase@uni-graz.at";
        cout << serr2 << endl;
        int ecode = system(serr2.c_str());
        if (ecode!=0)
        {
            cerr << "Error in system call\n";
        }
        cerr << "---------------------------------------------------\n";
    }
    catch (...)
    {
        cerr << "Alle restlichen Exceptions" << endl;
    }

    MyVector b(aa);         // Copy constructur needed for deep copy
    MyVector c;
    c = b;                  //  assignment operator needed for deep copy


    return 0;
}


