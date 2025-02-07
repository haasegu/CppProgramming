//   Democode um einige Fehler aufzuzeigen
//   g++ -pedantic -std=c++11 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized main.cpp
//   cppcheck --enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem main.cpp
//   clang++ -std=c++11 -fsyntax-only -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic main.cpp
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

//gives a string backward out
void backward(const string &name)
{
    for(int cnt = name.length()-1; cnt >= 0; cnt--) //-1 because of nullbyte
    {
        // cout << name[cnt] << endl;
        cout << name.at(cnt) << endl;
    }
}

//return a string with the length of the name
//if the description field is to short for a string it gives the user an information
void length(const string &name)
{
    if((name.length()-1) > 20)            // that is original from the student: no "-1" needed
    {
        cout << "Name ist für das Textfeld zu lang." << endl;
    }
    cout << "length of the name: " << name.length()-1 << endl; //-1 because of the space; no "-1" needed
}

//set all letters to lower case
//this is needed to calculate the position of a word
string case_sensitive(const string &lastname)
{
    string lower_case = lastname;
    for(unsigned int c = 0; c < lastname.size(); c++)
    {
        if((lower_case.at(c) >= 65) && (lower_case.at(c) <= 90)) //wenn großbuchstabe, dann +32
        {
            lower_case.at(c) += 32;
        }
    }
    return lower_case;
}

//calculate the position of the lastname
// GH: several returns; one case: all "==" not considered
// GH: no documentation
bool position(const string &lower_case, const string &compare, const string &lastname)
//                                                            GH:  wozu lastname !?
{
    bool last = false;
    for(unsigned int x = 0; x < lower_case.length(); x++) //.size without nullbyte
    {
        if(lower_case.at(x) > compare.at(x))
        {
            return last = true; //after Kranach
        }
        else if(lower_case.at(x) < compare.at(x))
        {
            return last = false;
        }
    }
}

/** \brief Determines whether string @p a is lexicographically larger than string @p b.
 *
 *  The different size of the two strings has to be taken into account.
 *
 * \param[in]   a   string
 * \param[in]   b   string
 * \return  Boolean for  @p a > @p b
 *
 */
bool gh_position(const string &a, const string &b)
{
    unsigned int i(0);
    unsigned int lmin = min(a.size(),b.size());  // size of the shortest string
    // continue as long as both strings are equal
    while ( i<lmin && a[i]==b[i])
    {
        i++;
    }
    // index  i  points either to the first non-equal position or at the very end of the string
    //       strings equal?    compare first non-equal character
    bool bb;
    if (i==lmin)                     // all compared characters have been equal
        bb =  a.size() > b.size();   // is string "a" longer than string "b"?
    else
        bb = a[i] > b[i];            // compare the first different character
    // this alternative is equivalent to
    //  bb = (l==lmin && a.size() > b.size()) || (l!=lmin && a[i] > b[i]);

    return bb;
}



int main()
{
    string firstname = "";
    string lastname = "";
    string name = ""; //gesamtname
    string space = " ";
    string lower_case = "";
    string compare = "kranach";

    cout << "Enter your firstname and lastname: " << endl;
    cin >> firstname; //cin liest nur bis zum ersten leerzeichen ein
    cin >> lastname;

    name = firstname + space + lastname;
    cout << "Gesamtname: " << name << endl;

    lower_case = case_sensitive(lastname);

    if(lower_case == compare)
    {
        cout << "the two strings are equal" << endl;
    }
    else
    {
        // if(position(lower_case, compare, lastname))
        if(gh_position(lower_case, compare))
        {
            cout << "lastname: " << lastname << " is after 'Kranach'." << endl;
        }
        else
        {
            cout << "lastname: " << lastname << " is before 'Kranach'." << endl;
        }
    }

    length(name);

    backward(name);

    return 0;
}
