#include <algorithm>     // sort
#include <iomanip>       // setw
#include <iostream>
#include <numeric>       // iota
#include <vector>
using namespace std;

//! @brief Determines the permutation vector for ascending order of a vector.
//!
//! @param[in] v  vector to determine sorting indices
//! @return permutation order
//! @see Ideas in <a href="http://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes">Stack Overflow</a>
//!
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v);

vector<size_t> inverse_indexes(const vector<size_t> &v);

template <class T>
ostream& operator<<(ostream &s, const vector<T> &idx);


int main()
{
    cout << "Hello world!" << endl;

    //const vector<double> v {1.23, -4.56, -6.7, 2.3, 1.1};        // initial
    const vector<double> v {3.1,2.1,12.1,9.1,8.1,3.1,7.1,6.1};
    cout << "   Orig. vector: " << v << endl;
    const vector<size_t>  idx =  sort_indexes(v);

    cout << "   Sort   index: " << idx << endl;

// -----------  Permute the original vector using the index vector ---------
    vector<double> sv(v.size());
                             // Version a)  via Loop
//    for (size_t k=0; k<idx.size(); ++k)
//    {
//        sv[k] = v[ idx[k] ];
//    }
                             // Version b)  via "transform" and Lambda
    transform(idx.begin(),idx.end(), sv.begin(),
              [&v](size_t k) { return v[k]; }
              );
    cout << "Permuted vector: " << sv << endl;
    
    //
    auto inv_idx = inverse_indexes(idx);
    cout << endl << "inv. sort index: " << inv_idx << endl;


    return 0;
}



template <typename T>
vector<size_t> sort_indexes(const vector<T> &v)
{
    // initialize original index locations
    vector<size_t> idx(v.size());
    //for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;  // per loop
    iota(begin(idx),end(idx),0);

    // sort indexes based on comparing values in v
    sort(idx.begin(), idx.end(),
           [&v](size_t i1, size_t i2) -> bool
            { return v[i1] < v[i2]; }
        );

    return idx;
}

vector<size_t> inverse_indexes(const vector<size_t> &idx)
{
    return sort_indexes(idx);
}


template <class T>
ostream& operator<<(ostream &s, const vector<T> &v)
{
    for (auto it: v) { cout << "  " << setw(5) << it; }
    return s;
}
