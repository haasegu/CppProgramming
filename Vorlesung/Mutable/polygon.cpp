#include "polygon.h"

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

ostream& operator<<(ostream& s, const Point2D& rhs)
{
    s << "(" << rhs.GetX() << "," << rhs.GetY() <<")";
    return s;
}

//float dist(const Point2D& a, const Point2D& b)
//{
//    return  sqrt( pow(a.GetX()-b.GetX(),2) + pow(a.GetY()-b.GetY(),2) );
//}

//---------------------------------------------------------------------------------
Polygon_old::Polygon_old(int n)
    :  _v(n)
{
    for (unsigned int k=0; k<_v.size(); ++k)
    {
        _v.at(k) = Point2D( cos(k*2*M_PI/n), sin(k*2*M_PI/n) );
    }

//    copy(_v.begin(),_v.end(), ostream_iterator<Point2D>(cout," "));
}

float Polygon_old::perimeter() const
{
    float sum=dist( _v.front(),_v.back() );  // geschlossener Polygonzug
    for (unsigned int k=1; k<_v.size(); ++k)
    {
        sum += dist( _v[k], _v[k-1] );
    }
    return sum;
}

//---------------------------------------------------------------------------------
Polygon::Polygon(int n)
    :  _v(n), _peri(-1.0f)
{
    for (unsigned int k=0; k<_v.size(); ++k)
    {
        _v.at(k) = Point2D( cos(k*2*M_PI/n), sin(k*2*M_PI/n) );
    }

//    copy(_v.begin(),_v.end(), ostream_iterator<Point2D>(cout," "));
}

float Polygon::perimeter() const
{
    if ( _peri<0.0f )
    {
        _peri=dist( _v.front(),_v.back() );  // geschlossener Polygonzug
        for (unsigned int k=1; k<_v.size(); ++k)
        {
            _peri += dist( _v[k], _v[k-1] );
        }
    }

    return _peri;
}
