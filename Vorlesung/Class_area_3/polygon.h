#pragma once

#include "form.h"
#include <cmath>
#include <iostream>
#include <vector>

//------------------------------------------

class Polygon_old
{
  public:
    Polygon_old(int n);
    void append(const Point2D& a) { _v.push_back(a); }
    int number() const { return static_cast<int>(_v.size()); }
    float perimeter() const;
    bool operator<(const Polygon_old& rhs) const { return perimeter() < rhs.perimeter(); }

  private:
    std::vector<Point2D> _v;
};

//------------------------------------------
/// \brief   Contains the description of a polygon, now with mutable.
///          The traverse is stored.
///
class Polygon : public Form
{
  public:
      /// @brief Constructs a regular polygon with vertices on the unit circle.
      ///
      /// @param[in]  n  number of vertices in the polygon
      /// @warning We use a mutable member @p _peri which should be defined -1 whenever the class instance has been changed.
      ///
    Polygon(int n);
    Polygon(Polygon const&) = default; 
    
    
    std::string classname() const override
    {
        return "Polygon of with "+std::to_string(number())+" vertices";
    }

/// @brief Adds a vertex to the end of the polygon traverse.
///
/// @param[in] a  2d point to add.
///
    void append(const Point2D& a) { _v.push_back(a); _peri=-1.0F; _area=-1.0F; }

    /// @brief Number of vertices in polygon
    ///
    /// @return Number of vertices of the open polygon
    ///
    int number() const { return static_cast<int>(_v.size()); }
    

    /// @brief Computes the perimeter of the closed polygon
    ///
    /// @return Perimeter of the closed polygon
    /// @warning Uses a mutable variable
    ///
    float perimeter() const;
    
    /// @brief Computes the area of the closed polygon
    ///
    /// @return Area of the closed polygon
    /// @warning Uses a mutable variable
    ///
    float area() const override;

    /// @brief Less operator regarding the perimeter.
    ///
    /// @param[in] rhs  second polygon.
    /// @return True iff perimeter of recent instance is less than the perimeter of the second instance.
    ///
    bool operator<(const Polygon& rhs) const { return perimeter() < rhs.perimeter(); }

  private:
    std::vector<Point2D> _v;     //!< ordered vertices of the polygon
    mutable float   _peri;  //!< stores the perimeter once it is (re-)calculated
    mutable float   _area;  //!< stores the area once it is (re-)calculated
};
