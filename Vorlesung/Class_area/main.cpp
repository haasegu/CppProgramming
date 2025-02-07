//     K5 -- Mathe
//  g++ -Wall -W -Wfloat-equal -Wshadow -Wredundant-decls -Weffc++ -pedantic k5.cpp
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Form        //  (nur Ergaenzen ist erlaubt)
{
 public:

    Form(float x, float y) : _x(x), _y(y) {}
    //   Zugriff auf Mittelpunktskoordinaten
    float GetX() const {return _x;}
    float GetY() const {return _y;}
    //   String mit Klasseninfo
    virtual string classname() const {return "geometrische Form";}      // virtual [1 Pkt]
    //   Berechnet die Flaeche des geometrischen Objektes
    virtual float area() const = 0;                                     // virtual [1 Pkt]
    virtual ~Form() {}

 private:
    float _x, _y;  // Mittelpunktskoordinaten
};

//  class Quadrat (definieren)
class Quadrat: public Form                                              // [1 Pkt]
{
public:
    Quadrat(float x, float y, float seite) : Form(x,y), _seite(seite) {}// [1 Pkt]
    string classname() const {return "Quadrat";}                        // [1 Pkt]
    float area() const {return _seite*_seite;}                          // [1 Pkt]

private:
    float _seite;                                                       // [1 Pkt]
};

//  class Kreis (definieren)
class Kreis: public Form                                                // [1 Pkt] ananlog wie andere Klasse
{
public:
    Kreis(float x, float y, float radius) : Form(x,y), _radius(radius) {}
    string classname() const {return "Kreis";}
    float area() const {return M_PI*_radius*_radius;}

private:
    float _radius;
};

//  weitere Funktionen/Operatoren  (was fehlt noch?)

bool operator<(const Form &a, const Form &b)                            // Referenz [1 Pkt]
{
    return a.area() < b.area();                                         // [1 Pkt]
}

//  Output-Operator (nicht veraendern!!)
ostream& operator<<(ostream& s, const Form &rhs)
{
  s << rhs.classname() << " mit Mittelpunkt ";
  s << "(" << rhs.GetX() << "," << rhs.GetY() <<")";
  s << " hat ein Flaeche von " << rhs.area();
  return s;
}

//----------    Hauptprogramm  (nicht veraendern!!)   ----------------------
int main()
{
 const Kreis   a( 0.0f, 1.0f, 1.1f);
       Quadrat b(-1.0f, 0.5f, 2.0f);

 cout << endl << a << endl << b << endl;

 if (a<b)
 {
     cout << "Flaeche von " << a.classname() << "  < als von " << b.classname() << endl;
 }
 else
 {
     cout << "Flaeche von " << b.classname() << " <= als von " << a.classname() << endl;
 }

 return 0;
}
