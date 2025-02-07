#pragma once 
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Form        //  (nur Ergaenzen ist erlaubt)
{
public:

    Form(float x, float y) : _x(x), _y(y) {}
    //   Zugriff auf Mittelpunktskoordinaten
    float GetX() const
    {
        return _x;
    }
    float GetY() const
    {
        return _y;
    }
    //   String mit Klasseninfo
    virtual string classname() const
    {
        return "geometrische Form";
    }   
    //   Berechnet die Flaeche des geometrischen Objektes
    virtual float area() const = 0;

    virtual ~Form() {}

private:
    float _x, _y;  // Mittelpunktskoordinaten
};

//  class Quadrat (definieren)
class Quadrat: public Form
{
public:
    Quadrat(float x, float y, float seite) : Form(x,y), _seite(seite) {}
    string classname() const
    {
        return "Quadrat";
    }
    float area() const
    {
        return _seite*_seite;
    }

    ~Quadrat() {}

private:
    float _seite;
};

//  class Kreis (definieren)
class Kreis: public Form
{
public:
    Kreis(float x, float y, float radius) : Form(x,y), _radius(radius) {}
    string classname() const
    {
        return "Kreis";
    }
    float area() const
    {
        return M_PI*_radius*_radius;
    }

    ~Kreis() {}

private:
    float _radius;
};

//  weitere Funktionen/Operatoren  (was fehlt noch?)

bool operator<(const Form &a, const Form &b);

inline
float euclid_dist(const Form &a, const Form &b)
{
    return sqrt( (b.GetX()-a.GetX())*(b.GetX()-a.GetX()) + (b.GetY()-a.GetY())*(b.GetY()-a.GetY()) );
}

// via pointer arguments
bool kleiner(const Form *a, const Form *b);

inline
float euclid_dist(const Form *a, const Form *b)  // distance(iterator, iterator) exists already in STL !!
{
    cout << "###";
    return euclid_dist(*a, *b);
}


ostream& operator<<(ostream& s, const Form& rhs);
