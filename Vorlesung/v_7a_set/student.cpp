#include "student.h"
#include <algorithm>           // copy
#include <set>
#include <string>
#include <vector>
using namespace std;

Student::Student()
: _name(), _matr_nr(), _skz()
{
    //ctor
}

Student::Student(const string& name, const string& matrikel, int studium)
    : _name(name), _matr_nr(matrikel), _skz{studium}
{
    //ctor

}

Student::Student(const string & name, const string& matnr, const vector<int>& skz)
    : _name(name), _matr_nr(matnr),_skz()
{
    //ctor
    for (auto v:skz)
    {
        _skz.insert(v);
    }
}


void Student::Add_SKZ(int skz)
{
    _skz.insert(skz);
}

void Student::Del_SKZ(int skz)
{
    _skz.erase(skz);
}

vector<int> Student::Get_SKZ() const
{
    vector<int> vv(num_Studies());  // allocate memory
    copy(_skz.cbegin(),_skz.cend(),vv.begin());
    return vv;
}



ostream& operator<<(ostream& s, const Student& rhs)
{
    s << rhs._name << endl;
    //s << rhs.skz << endl;
    for (auto v: rhs._skz)
    {
        s << v  << " ";
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
