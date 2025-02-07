//   Klasse Student
//      Output-Operator (friend); Mehrere Studien
//      Nutzung der STL
#include "student.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


/** \brief binary boolean function: Compares the number of studies of two students
 *
 * \param[in] lhs   student
 * \param[in] rhs   student
 * \return lexigraphically @p lhs < @p rhs
 *
 */
bool num_studs(const Student& lhs, const Student& rhs);


/** \brief Functor for passing a parameter @p cSKZ to an comparison operator.
 *
 * \param[in] cSKZ   comparison parameter
 * \return lexigraphically @p rhs.
 *
 */
struct Check_SKZ
{
   private:
     int _cSKZ; //!< stores the comparison parameter
   public:
     //!< Constructor for functor
     Check_SKZ(int cSKZ): _cSKZ(cSKZ){}
     //!< The comparison operator
     bool operator()(const Student &lhs) const {return lhs.Enrolled4Study(_cSKZ);}
} ;

int main()
{
    cout << "Hello world!" << endl;

    vector<Student> gg{ {"Tyson", "8956256215",  421            }, // uses Student(..., int)
                        {"Strude","0771871827", {865, 421, 666} }, // uses Student(..., vector<int>)
                        {"Neuner", "997216726", {732, 865}      }  // uses Student(..., vector<int>)
                      } ;   // C++-11 initialization list

//    cout << "  --  at -- " << endl;
//    for (unsigned int i=0; i<gg.size(); ++i)
//    {
//        cout << gg.at(i) << endl;
//    }
//
//    cout << "  --  iterator -- " << endl;
//    for (auto pi=gg.begin(); pi!=gg.end(); ++pi)
//    {
//        cout << *pi << endl;
//    }

    cout << "  --  C++11 range-for  -- " << endl;
    for (auto pi: gg)
    {
        cout << pi << endl;
    }

    // sort with respect to names lexicographically
    sort(gg.begin(),gg.end());   // requires method  Student::operator<(const Student&) that compares the names lexicographically

    cout << "  --  nach name sort  -- " << endl;
    for (auto pi: gg) { cout << pi << endl; }

    sort(gg.begin(),gg.end(), num_studs); // uses the compare function  bool num_studs(const Student&,const Student&)
    //sort(gg.begin(),gg.end(), [](const Student &lhs, const Student &rhs) {return lhs.Num_SKZ() < rhs.Num_SKZ();} ); // via Lambda-Funktion
    cout << "  --  nach SKZ sort  -- " << endl;
    for (auto pi: gg) { cout << pi << endl; }

    // find first student with study 865
    const int cSKZ=865;
    auto it = find_if(gg.cbegin(),gg.cend(),Check_SKZ(cSKZ));    // requires unary function (via functor)
    cout << endl << " ## first student with SKZ " << cSKZ << " : " << *it << endl;
//
    // count the number students of study 865
    int ns = count_if(gg.cbegin(),gg.cend(),                     // requires unary function (via lambda function)
                   [cSKZ] (Student const& a) {return a.Enrolled4Study(cSKZ);}
                     );
    cout << endl << ns << " students have SKZ " <<  cSKZ << endl;

    return 0;
}


bool num_studs(const Student& lhs, const Student& rhs)
{
    return lhs.Num_SKZ() < rhs.Num_SKZ(); // compares the number of studies
}
