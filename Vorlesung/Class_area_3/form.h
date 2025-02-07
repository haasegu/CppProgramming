#pragma once


#include <iostream>
#include <string>
#include <cmath>


/// @brief Class containing a point in 2D
///
class Point2D
{
  public:
      /// @brief Constructor without parameters.
      ///  Defines the point to the origin (0.0).
      ///
    Point2D() : _x(0.0F), _y(0.0F) {}

    /// @brief Constructor
    ///
    /// @param[in]  x coordinate in x direction
    /// @param[in]  y coordinate in y direction
    ///
    Point2D(float x, float y) : _x(x), _y(y) {}

    /// @brief Getter
    /// @return x coordinate
    float GetX() const {return _x;}

    /// @brief Getter
    /// @return y coordinate
    float GetY() const {return _y;}

private:
    float _x; //!< x coordinate of point
    float _y; //!< y coordinate of point
};

/// @brief Output operator for class @p Point2D
///
/// @param[in,out]  s    output stream
/// @param[in]      rhs  class instance
/// @return output stream
///
std::ostream& operator<<(std::ostream& s, const Point2D& rhs);

/// @brief Calculates the Euclidian distance between two points in 2D
///
/// @param[in] a  first point
/// @param[in] b  second point
/// @return Euclidian distance
///
inline float dist(const Point2D& a, const Point2D& b)
{
    return  std::sqrt( std::pow(a.GetX()-b.GetX(),2.0F) + std::pow(a.GetY()-b.GetY(),2.0F) );
}

/// @brief Calculates z-component of the cross product of two points in 2D
///
/// @param[in] a  first point
/// @param[in] b  second point
/// @return z-component of the cross product
///
/// @warning Incorrect result for <a href="https://imsc.uni-graz.at/haasegu/Lectures/Kurs-C/Download/doxy_help.html">self-intersection polygons</a>.
///
inline float crossZ(const Point2D& a, const Point2D& b)
{
    return  a.GetX()*b.GetY() - a.GetY()*b.GetX() ;
}


class Form        //  (nur Ergaenzen ist erlaubt)
{
public:

    Form(float x, float y) : _p(x,y) {}
    Form(Form const&) = default; 
    
    //   Zugriff auf Mittelpunktskoordinaten
    float GetX() const
    {
        return _p.GetX();
    }
    float GetY() const
    {
        return _p.GetY();
    }
    //   String mit Klasseninfo
    virtual std::string classname() const
    {
        return "geometrische Form";
    }
    //   Berechnet die Flaeche des geometrischen Objektes
    virtual float area() const = 0;

    virtual ~Form();
    
private:
    Point2D _p;  // Mittelpunktskoordinaten
};

//  class Quadrat (definieren)
class Quadrat: public Form
{
public:
    Quadrat(float x, float y, float seite) : Form(x,y), _seite(seite) {}
    Quadrat(Quadrat const&) = default; 

    std:: string classname() const override
    {
        return "Quadrat";
    }
    float area() const override
    {
        return _seite*_seite;
    }

    ~Quadrat() override;

private:
    float _seite;
};

//  class Kreis (definieren)
class Kreis: public Form
{
public:
    Kreis(float x, float y, float radius) : Form(x,y), _radius(radius) {}
    Kreis(Kreis const&) = default; 

    
    std::string classname() const override
    {
        return "Kreis";
    }
    float area() const override
    {
        return M_PI*_radius*_radius;
    }

    ~Kreis() override;

private:
    float _radius;
};

//  weitere Funktionen/Operatoren  (was fehlt noch?)

bool operator<(const Form &a, const Form &b);

inline
float euclid_dist(const Form &a, const Form &b)
{
    return std::sqrt( (b.GetX()-a.GetX())*(b.GetX()-a.GetX()) + (b.GetY()-a.GetY())*(b.GetY()-a.GetY()) );
}

// via pointer arguments
bool kleiner(const Form *a, const Form *b);

inline
float euclid_dist(const Form *a, const Form *b)  // distance(iterator, iterator) exists already in STL !!
{
    std::cout << "###";
    return euclid_dist(*a, *b);
}


std::ostream& operator<<(std::ostream& s, const Form& rhs);
