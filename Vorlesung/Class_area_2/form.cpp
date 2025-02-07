#include "form.h"

#include <iostream>
using namespace std;

bool operator<(const Form &a, const Form &b)
{
    return a.area() < b.area();
}

bool kleiner (const Form *a, const Form *b)
{
    return a->area() < b->area();                      // uses  operator<(const Form &a, const Form &b)
}

//  Output-Operator : Here we benefit from polymorphism
ostream& operator<<(ostream& s, const Form& rhs)
{
  s << rhs.classname() << " mit Mittelpunkt ";
  s << "(" << rhs.GetX() << "," << rhs.GetY() <<")";
  s << " hat ein Flaeche von " << rhs.area();
  return s;
}
