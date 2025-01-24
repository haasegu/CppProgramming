#pragma once
#include <chrono>                  // timing

using Clock = std::chrono::system_clock;   //!< The wall clock timer chosen
//using Clock = std::chrono::high_resolution_clock;

static std::chrono::time_point<Clock> MyStopWatch; //!< starting time of stopwatch

/** Starts stopwatch timer.
 * Use as @code tic(); myfunction(...) ; double tsec = toc();  @endcode
 * 
 *  @return recent time point
 *  @see toc
 */
inline
auto tic()
{
    MyStopWatch = Clock::now();
    return MyStopWatch;
}
 
/** Returns the elapsed time from stopwatch. 
 * 
 * The time point from the last call tic() is used 
 * if time point @p t_b is not passed as input parameter.
 * Use as @code tic(); myfunction(...) ; double tsec = toc();  @endcode
 * or as @code auto t_b = tic(); myfunction(...) ; double tsec = toc(t_b);  @endcode
 * The last option is to be used in the case of nested time measurements, 
 * e.g., if myfunction() calls tic() internally.
 * 
 * @param[in]  t_b start time of some stop watch
 * @return elapsed time in seconds.
 *
*/ 
inline
double toc( std::chrono::time_point<Clock> const &t_b = MyStopWatch)
{
    // https://en.cppreference.com/w/cpp/chrono/treat_as_floating_point
    using Unit      = std::chrono::seconds;
    using FpSeconds = std::chrono::duration<double, Unit::period>;        
    auto t_e = Clock::now();
    return FpSeconds(t_e-t_b).count();
}
