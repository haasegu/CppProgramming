#include "student.h"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

Student::Student()
: _name(), _matr_nr(), _skz()
{
    //ctor
}

Student::Student(const string& name, const string& matrikel, int studium)
    : _name(name), _matr_nr(matrikel), _skz(1,studium)
{
    //ctor

}

Student::Student(const string & name, const string& matnr, const vector<int>& skz)
    : _name(name), _matr_nr(matnr),_skz(skz)
{
    //ctor
}


void Student::Add_SKZ(int skz)
{
    vector<int>::iterator it;
    it = find(_skz.begin(),_skz.end(), skz);
    if ( it == _skz.end()) {_skz.push_back(skz);}
}

void Student::Del_SKZ(int skz)
{
    auto it = find(_skz.begin(),_skz.end(), skz);
    if ( it != _skz.end()) {_skz.erase(it);}
}


ostream& operator<<(ostream& s, const Student& rhs)
{
    s << rhs._name << endl;
    //s << rhs.skz << endl;   // oder operator<< für vector<int> implementieren
    for (unsigned int k=0; k<rhs._skz.size(); ++k)
    {
        s << rhs._skz.at(k)  << " ";
    }
    s << endl;
    return s;
}

istream& operator>>(istream& s, Student& rhs)
{
    s >> rhs._name;
    int tmp;
    s >> tmp;
//    rhs._skz.push_back(tmp);
    rhs.Add_SKZ(tmp);
    return s;
}
