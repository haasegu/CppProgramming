//#include "tfkt.tcc"                                     // Use templates

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

//---------------                                      // no templates
     int    mymax (const int a, const int b)
     {
        return  a > b  ?  a  : b;
     }

     float  mymax (const float a, const float b)
     {
        return  a > b  ?  a  : b;
     }

     double mymax (const double a, const double b)
     {
        return  a > b  ?  a  : b;
     }


     int  max_elem(const vector<int>&  x)
     {
      const int n=x.size();
      assert(n>0);                  // --> richtiges Exeption-handling muss rein

      int vmax= x[0];
      for (int i=1; i<n; i++)
       {
         vmax = mymax(vmax,x[i]);   // Nutze die Funktion mymax
       }

      return vmax;
     }

     float  max_elem(const vector<float>&  x)
     {
      const int n=x.size();
      assert(n>0);                  // --> richtiges Exeption-handling muss rein

      float vmax = x[0];
      for (int i=1; i<n; i++)
       {
         vmax = mymax(vmax,x[i]);   // Nutze die Funktion mymax
       }

      return vmax;
     }

     double  max_elem(const vector<double>&  x)
     {
      const int n=x.size();
      assert(n>0);                  // --> richtiges Exeption-handling muss rein

      double vmax = x[0];
      for (int i=1; i<n; i++)
       {
         vmax = mymax(vmax,x[i]);   // Nutze die Funktion mymax
       }

      return vmax;
     }
//---------------

int main()
{
    cout << "Templates  " << endl;

    int ia{-2}, ib{3};
    int ir = mymax(ia,ib);
    cout << "int    : " << ir << endl;

    float fa{-2.0f}, fb{3.0f};
    float fr = mymax(fa,fb);
    cout << "float  : " << fr << endl;

    double da{-2.0}, db{3.0};
    double dr = mymax(da,db);
    cout << "double : " << dr << endl;

    // ---------------------------------
    {
        vector<int> v{2,6,-2,4,9,-1,4};
        auto vm = max_elem(v);
        cout << "v-int   : " << vm << endl;
    }
    {
        vector<float> v{2.0f,6.0f,-2.0f,4.0f,9.0f,-1.0f,4.0f};
        auto vm = max_elem(v);
        cout << "v-float : " << vm << endl;
    }
    {
        vector<double> v{2.0,6.0,-2.0,4.0,9.0,-1.0,4.0};
        auto vm = max_elem(v);
        cout << "v-double: " << vm << endl;
    }

    return 0;
}
