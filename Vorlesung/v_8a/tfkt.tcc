#pragma once
#include <cassert>
#include <vector>

template <class T>
T mymax (const T a, const T b)
{
    return  a > b  ?  a  : b;
}


template<class T>
T  max_elem(const std::vector<T>  &x)
{
    const int n = x.size();
    assert(n > 0);                // --> richtiges Exeption-handling muss rein

    T vmax = x[0];
    for (int i = 1; i < n; i++) {
        vmax = mymax(vmax, x[i]);  // Nutze die Funktion mymax
    }

    return vmax;
}
