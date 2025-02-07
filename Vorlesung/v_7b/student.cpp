#include "student.h"
#include <algorithm>           // erase
#include <string>
#include <vector>
using namespace std;

Student::Student()
: _name(), _matr_nr(), _skz()
{
    //ctor
}

Student::Student(const string& fname, const string& matrikel, const int studium)
: _name(fname), _matr_nr(matrikel), _skz(1,studium)
{
    //ctor

}

Student::Student(const string& fname, const string& matrikel, const vector<int>& studium)
: _name(fname), _matr_nr(matrikel), _skz(studium)
{
    //ctor

}

void Student::Setname(const string& val) { _name = val; }

void Student::Add_SKZ(const int skz)
{
    vector<int>::iterator it;
    it = find(_skz.begin(),_skz.end(), skz);
    if ( it == _skz.end())  _skz.push_back(skz);
}

void Student::Del_SKZ(const int skz_in)
{
    //vector<int>::iterator it;
    auto it = std::find(_skz.begin(),_skz.end(),skz_in);
    if ( it != _skz.end() )  _skz.erase(it);
    return;
}


ostream& operator<<(ostream& s, const Student& rhs)
{
    s << rhs._name << "  :  ";
    //s << rhs.skz << endl;
    for (unsigned int k=0; k<rhs._skz.size(); ++k)
    {
        s << rhs._skz.at(k)  << " ";
    }
    return s;
}

istream& operator>>(istream& s, Student& rhs)
{
    s >> rhs._name;
    int tmp;
    s >> tmp;
    rhs.Add_SKZ(tmp);
    return s;
}
