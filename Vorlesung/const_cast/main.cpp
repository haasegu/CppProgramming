#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class A{
    public:
    A(double x): _x(x), _n(1) {};
    
    A(A const & rhs) = default;
    A(A      && rhs) = default;
    A& operator=(A const & rhs) = delete;     // not available with const member
    A& operator=(A      && rhs) = default;
    ~A()                        = default;
    
    double pow() const
    {
        return std::pow(_x,_n);
    }
    
    void SetPower(int n)
    {        
        const_cast<int&>(_n) = n;            // trick
    }
    
    private:
    double _x;
    const int    _n;
};

int main()
{
    //--------------------  change const member   --------------
    A xa(1.2345);
    
    xa.SetPower(3);
    cout << xa.pow() << endl;
    
    // ----------
    A xb(xa);
    A xc(xa);
    xb.SetPower(4);
    //xc = xb;    // not available with const member
    
    
    return 0;
}

