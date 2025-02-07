#include <cmath>
#include <iostream>
using namespace std;

int main()
{
  int ib;
  cin >> ib;
  double db(ib);
  
  auto i1 = std::pow(ib,3);        // result is double
  auto i2 = std::pow(ib,3.0);      // result is double
  auto i3 = ib*ib*ib;
  
  auto d1 = std::pow(db,3);
  auto d2 = std::pow(db,3.0);
  auto d3 = db*db*db;
  
  cout << ib << " : " << i1 << "  " << i2 << "  " << i3 << endl;
  cout << db << " : " << d1 << "  " << d2 << "  " << d3 << endl;

  
  return 0;
}
