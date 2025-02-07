#include "fkt.h"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


double sgn(const double x)
{
    cout << " in double" << endl;
    double t=0.0;
    if (x>0.0)
    {
        t = 1.0;
    }
    else if (x <0.0)
    {
        t = -1.0;
    }
    else
    {
        t = 0.0;
    }
    return t;
}

float sgn(const float x)
{
    cout << " in float" << endl;
    float t(0.0f);
    if (x>0.0f)
    {
        t = 1.0f;
    }
    else if (x <0.0f)
    {
        t = -1.0f;
    }
    else
    {
        t = 0.0f;
    }
    return t;
}

size_t sgn(const string x)
{
    cout << " in string" << endl;
    return x.size();
}

// Kopieren eines Vektors
// a ist input
// b ist output
void copy_vek(const vector<int>& a, vector<int>& b)
{
    b.resize(a.size());
    for (unsigned int k=0; k<a.size(); ++k)  b[k] = a[k];
    return;
}

void set_value(int& a)
{
    a = -1;
}

//  Rekursive Funktion
float mypow(const float x, const int k)     // Definition
{
    assert(k>=0);
    float tmp(1.0f);
    if (k>=1)
    {
        tmp = x*mypow(x,k-1);
    }
//    else             // abbruchbedingung
//    {
//        tmp =  1;
//    }
    return tmp;
}



