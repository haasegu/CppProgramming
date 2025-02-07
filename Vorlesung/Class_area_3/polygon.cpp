#include "form.h"
#include "polygon.h"

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;


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
    :  Form(0.0F, 0.0F), _v(n), _peri(-1.0F), _area(-1.0F)
{
    for (unsigned int k=0; k<_v.size(); ++k)
    {
        _v.at(k) = Point2D( cos(k*2*M_PI/n), sin(k*2*M_PI/n) );
    }

//    copy(_v.begin(),_v.end(), ostream_iterator<Point2D>(cout," "));
}

float Polygon::perimeter() const
{
    if ( _peri<0.0F )
    {
        _peri=dist( _v.front(),_v.back() );  // geschlossener Polygonzug
        for (unsigned int k=1; k<_v.size(); ++k)
        {
            _peri += dist( _v[k], _v[k-1] );
        }
    }

    return _peri;
}

float Polygon::area() const
{
    if ( _area<0.0F )
    {
        _area= crossZ(_v.back(),_v.front());  // geschlossener Polygonzug
        for (unsigned int k=1; k<_v.size(); ++k)
        {
            _area += crossZ( _v[k-1], _v[k] );
        }
        _area = _area/2;
    }

    return _area;
}

