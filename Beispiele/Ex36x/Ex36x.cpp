#include <cmath>
#include <iomanip>      // std::setprecision
#include <iostream>
#include <limits>

//using namespace std;
using std::cout;
using std::endl;

int main()
{
    {
        float a{std::log(17.0f)};
        auto r_1 = std::exp(a);                // <cmath>, see https://en.cppreference.com/w/cpp/numeric/math/exp
        auto r_2 = exp(a);                     // <math.h>, see https://en.cppreference.com/w/c/numeric/math/exp

        cout << " std::exp(a) - exp(a)  :  ";
        cout << r_1-r_2;
        cout.precision(12);
        cout << " (" << r_1 << " , " << r_2 << ")"<< endl;
        cout.precision(6);
    }

    {
        float a{512.0};
        auto r_1 = std::cbrt(a);
        auto r_2 = std::pow(a,1.0f/3.0f);

        cout << " std::cbrt(a) - std::pow(a,1.0f/3.0f)  :  ";
        cout << r_1-r_2;
        cout.precision(12);
        cout << " (" << r_1 << " , " << r_2 << ")"<< endl;
        cout.precision(6);
    }

    {
        float a{512.0};
        auto r_1 = std::cbrt(-a);
        auto r_2 = std::pow(-a,1.0f/3.0f);

        cout << " std::cbrt(-a) - std::pow(-a,1.0f/3.0f)  :  ";
        cout << r_1-r_2;
        cout.precision(12);
        cout << " (" << r_1 << " , " << r_2 << ")"<< endl;
        cout.precision(6);
    }

    {
        //float a{0.1+std::numeric_limits<float>::epsilon()};
        float a{std::numeric_limits<float>::epsilon()};
        auto r_1 = std::sqrt(a);
        auto r_2 = std::pow(a,0.5f);

        cout << " std::sqrt(a) - std::pow(a,0.5f)  :  ";
        cout << r_1-r_2;
        cout.precision(12);
        cout << " (" << r_1 << " , " << r_2 << ")"<< endl;
        cout.precision(6);
    }

    //{
        //float hoch;
        //std::cin >> hoch;
        //for (float a=std::nextafter(0.0f,1.0f); a<1.0f; a = std::nextafter(a,1.0f))
        //{
            //auto aa = 1.0f/a;
            //auto r_1 = std::sqrt(aa);
            ////auto r_2 = std::pow(aa,0.5f);
            //auto r_2 = std::pow(aa,hoch);
            //if (r_1!=r_2)
            //{
                //cout.precision(20);
                //cout << aa << " (" << r_1 << " , " << r_2 << ")"<< endl;
                //cout.precision(6);
            //}
        //}
    //}

    {
        float a{3.0e20f}, b{1e-4f};              // overflow
        //float a{0.0f}, b{1e-30f};                // underflow
        //float a{1.0f}, b{1e-3f};                 // machine epsilon
        auto r_1 = std::hypot(a,b);
        auto r_2 = std::sqrt(a*a+b*b);

        cout << " std::hypot(a,b) - std::sqrt(a*a+b*b) :  ";
        cout << r_1-r_2;
        cout.precision(12);
        cout << " (" << r_1 << " , " << r_2 << ")"<< endl;
        cout.precision(6);
    }

   {
        float a{3.0f};
        auto r_1 = a*(7.0f/a);
        auto r_2 = a*7.0f/a;

        cout << " a*(1.0f/a) - a*1.0f/a  :  ";
        cout << r_1-r_2;
        cout.precision(12);
        cout << " (" << r_1 << " , " << r_2 << ")"<< endl;
        cout.precision(6);
    }



    return 0;
}
