//	Ex511.cpp

//	Sec. 5.1 of lecture
//                   String variables
#include <cstring>                  // strcpy
#include <iostream>
using namespace std;

int main()
{
    const  int L = 11;              // 10+1
    char word2[L] = "Mathematik";
    char word3[]  = "Mathematik";
    char word[L];

    strcpy(word, "Mathematik");    // initialization of variable 'word'

    for (int i = 0; i < L; ++i) {
        cout << word[i] << " " ;
    }
    cout << endl;
    cout << endl << word  << endl;
    cout << endl << word2 << endl;
    cout << endl << word3 << endl;
    cout << endl;

//		Let's crash
//		(works on LINUX with g++, other compilers or OS act
//		 differently)
//		input of "mathematik123" overwrites word3
//		Data alignmenton 4 Byte

    cout << " word = " ;
    cin >> word;
    cout << word  << endl;
    cout << word2 << endl;
    cout << word3 << endl;
    cout << endl;

    return 0;
}









