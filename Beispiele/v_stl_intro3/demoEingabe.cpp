// Demonstration der sicheren Eingabe

//  http://www.cplusplus.com/articles/D9j2Nwbp/
//  g++ -std=c++11 -pedantic -Wall demoEingabe.cpp

#include <iostream>
#include <sstream>       // istringstream
using namespace std;

int save_input()
{
    string Text;         // string containing the number
    cin >> Text;

    int Result;          // integer number that will contain the result
    istringstream convert(Text);
//
// stringstream is used for the conversion constructed with the contents of 'Text'
// i.e.: the stream will start containing the characters of 'Text'
// 
// converts the value to 'Result' using the characters in the stream
    if ( !(convert >> Result) )
        Result = 0;      // if that fails set 'Result' to 0

    return Result;
}

int main()
{
    int n = save_input();
    cout << " n : " << n << endl;

    return 0;
}

