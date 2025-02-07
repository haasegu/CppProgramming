#include <iostream>
#include <string>
using namespace std;



class A
{
public:
    A(string const & name)
        : _ss(name)
    {
    }

    string Get_string() const
    {
        return _ss;
    }

//private:              // No access from outside this class.
protected:              // Allows access to members by derived classes.
    string _ss;

};

class B : public A        // IS-A  [derived class]; 'public' allows access to public/protected members/methods of class A
{
public:
    B(string const & name, int b)  // Has-A  [additional property wrt. A]
        : A(name), _b(b)
    {
//        cout << _ss << endl;
    }

    //string Get_string() const {return _ss;}  // overload, not needed here

    int fkt_B() const
    {
        return _b*_b;   // Has-A  [additional property wrt. A]
    }

private:
    int _b;             // Has-A [additional property wrt. A]
};



//------------------------

int main()
{
    A v("Freitag");
    cout << v.Get_string() <<  endl;  // A::Get_string

    B g("Samstag",7);

    cout << g.Get_string() << " ";    // B::Get_string --> A::Get_string
    cout << g.fkt_B() << endl;

    return 0;
}
