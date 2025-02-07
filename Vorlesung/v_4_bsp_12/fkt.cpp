#include <vector>
using namespace std;
#include "fkt.h"

//-------------------------------------------------------------------------------

int* fibo_dangerous()
{
    int temp = 0;
    int last = 1;
    int fib  = 1;

    // the indices of fib 1 and fib 2 is 1
    // so we have already 2 fib numbers
    int index = 2;

    while((fib + last) > fib)
    {
        temp = fib;
        fib += last;
        last = temp;

        index++;
    }

    int* result = new int[2];
    result[0] = index;
    result[1] = fib;

    return result;     // pointer to an object in heap memory
}

//-------------------------------------------------------------------------------

vector<int> fibo_vector()
{
    int temp = 0;
    int last = 1;
    int fib  = 1;

    // the indices of fib 1 and fib 2 is 1
    // so we have already 2 fib numbers
    int index = 2;

    while((fib + last) > fib)
    {
        temp = fib;
        fib += last;
        last = temp;

        index++;
    }

    vector<int> result(2);
    result[0] = index;
    result[1] = fib;

    return result;     // pointer to an object in heap memory
}

//-------------------------------------------------------------------------------

vec2 fibo_struct()
{
    int temp = 0;
    int last = 1;
    int fib  = 1;

    // the indices of fib 1 and fib 2 is 1
    // so we have already 2 fib numbers
    int index = 2;

    while((fib + last) > fib)
    {
        temp = fib;
        fib += last;
        last = temp;

        index++;
    }

    vec2 result;
    result.idx   = index;
    result.fibon = fib;

    return result;     // pointer to an object in heap memory
}
