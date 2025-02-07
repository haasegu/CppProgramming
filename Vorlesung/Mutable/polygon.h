#pragma once

#include <iostream>
#include <vector>
#include <cmath>

/// @brief Class containing a point in 2D
///
class Point2D
{
  public:
      /// @brief Constructor without parameters.
      ///  Defines the point to the origin (0.0).
      ///
    Point2D() : _x(0.0f), _y(0.0f) {}

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
// float dist(const Point2D& a, const Point2D& b);
inline float dist(const Point2D& a, const Point2D& b)
{
    return  std::sqrt( std::pow(a.GetX()-b.GetX(),2) + std::pow(a.GetY()-b.GetY(),2) );
}

//------------------------------------------

class Polygon_old
{
  public:
    Polygon_old(int n);
    void append(const Point2D& a) { _v.push_back(a); }
    int number() const { return _v.size(); }
    float perimeter() const;
    bool operator<(const Polygon_old& rhs) const { return perimeter() < rhs.perimeter(); }

  private:
    std::vector<Point2D> _v;
};

//------------------------------------------
/// \brief   Contains the description of a polygon, now with mutable.
///          The traverse is stored.
///
class Polygon
{
  public:
      /// @brief Constructs a regular polygon with vertices on the unit circle.
      ///
      /// @param[in]  n  number of vertices in the polygon
      /// @warning We use a mutable member @p _peri which should be defined -1 whenever the class instance has been changed.
      ///
    Polygon(int n);

/// @brief Adds a vertex to the end of the polygon traverse.
///
/// @param[in] a  2d point to add.
///
    void append(const Point2D& a) { _v.push_back(a); _peri=-1.0f; }

    /// @brief Number of vertices in polygon
    ///
    /// @return Number of vertices of the open polygon
    ///
    int number() const { return _v.size(); }

    /// @brief Computes the perimeter of the closed polygon
    ///
    /// @return Perimeter of the closed polygon
    /// @warning Uses a mutable variable
    ///
    float perimeter() const;

    /// @brief Less operator regarding the perimeter.
    ///
    /// @param[in] rhs  second polygon.
    /// @return True iff perimeter of recent instance is less than the perimeter of the second instance.
    ///
    bool operator<(const Polygon& rhs) const { return perimeter() < rhs.perimeter(); }

  private:
    std::vector<Point2D> _v;     //!< ordered vertices of the polygon
    mutable float   _peri;  //!< stores the perimeter once it is (re-)calculated
};
