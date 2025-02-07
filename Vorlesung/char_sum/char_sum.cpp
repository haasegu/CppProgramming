/*
Add the char Variables to a number

magic=96:
   hardwork
   knowledge
   attitude

magic=0:
   BILLGATES          (the third!)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string term;
  const int magic=96;
//  const int magic=0;

  cout << endl;
  cout << " How to get 103% performance? " << endl << endl;
  cout << "  Try it with :  ";
  cin  >> term;

  int sum = 0;
  for (unsigned int i=0; i<term.size(); ++i)
   {
     sum += term[i] - magic;
   }

  cout << endl << endl;
  cout << "  " << term << "  sums to  " << sum << endl << endl;















// magic=96:

//   cout << endl;
//   cout << " How to get 103% performance? " << endl << endl;
//
//   cout << " by :  H A R D W O R K     = " <<  H+A+R+D+W+O+R+K   << " %" << endl;
//
// //	Similarly,
//   cout << " by :  K N O W L E D G E   = " <<  K+N+O+W+L+E+D+G+E << " %" << endl;
//
// //	But interesting (and as you'd expect),
//   cout << " by :  A T T I T U D E     = " <<  A+T+T+I+T+U+D+E   << " %" << endl;
//
// //	But EVEN MORE IMPORTANT TO NOTE (or REALIZE), is
//   cout << " by :  B U L L S H I T     = " <<  B+U+L+L+S+H+I+T   << " %" << endl;
//
//   cout << endl;

/* Webster' definition of bullshit
   usually vulgar : NONSENSE; especially : foolish insolent talk
   				(unsensibles, anmaszendes Gequatsche)
*/

/*
 So now you know what all those high-priced consultants, upper management, and
 motivational speakers really mean when they want to exceed 100%!
*/

//  magic =0;
//  BILLGATES --> 663   (the third!!) ==> 666

 return 0;
}









