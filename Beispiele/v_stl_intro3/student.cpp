//	student.cpp
//  g++ -c -std=c++11 -Wall -pedantic student.cpp

#include "student.h"
#include <string>
#include <vector>
using namespace std;

void Copy_Student(Student_Mult &lhs, const Student &rhs)
{
    lhs.matrikel = rhs.matrikel;
    lhs.name     = rhs.name;
    lhs.vorname  = rhs.vorname;
    lhs.skz.clear();                  //  deletes all elements from vector
    lhs.skz.push_back(rhs.skz);       //  adds the skz from rhs to the (empty) vector

    return;
}









