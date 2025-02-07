#pragma once

#include <functional>             // function; C++11

/** \brief Returns one solution for the equation @f$ func(x) = 0 @f$ with
 *    @f$ x \in [a,b] @f$.
 * 
 *   The requirement @f$ func(a) > 0 > func(b)  @f$ has to be fulfilled.
 *
 *   The solution is determined by bisection.
 *
 *   The input function @p func t has to be declared:
 *   <b>double pp(double x);</b>
 *   i.e., <b>pp</b> could be used as first argument in the parameter list when calling @p Bisect.
 *
 * \param[in]   func  function with one @p double input parameter that returns a  @p double value
 * \param[in]   a     interval begin
 * \param[in]   b     interval end
 * \param[in]   eps   accuracy @f$ \varepsilon @f$
 * \return solution @f$ x^\ast@f$ such that  @f$ |func(x^\ast)| < \varepsilon @f$
 * \warning  The function values @f$ func(a) @f$ and @f$ func(b) @f$ musst have different signs.
 *
 */
 double Bisect(const std::function<double(double)>& func,
               const double a, const double b, const double eps);
