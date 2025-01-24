//	Ex350.cpp

//	Sec. 3.5 of lecture
//	bitwise operators

#include <iostream>
using namespace std;

int main()
{
  short int l = 5;              //     0..000L0L
  short int k = 6;              //     0..000LL0
  short int   n1,n2,n3,n4,n5,n6,n7;

  n1 = ~k;      // Complement          L..LLL00L    = -7 = -6 - 1
  n2 = k & l;   // bit-AND             0..000L00    = 4
  n3 = k | l;   // bit-OR              0..000LLL    = 7
  n4 = k ^ l;   // bit-XOR             0..0000LL    = 3
  n5 = k << 2;  // shift  left by 2    0..0LL000    = 24 = 6 * 2^2
  n6 = k >> 1;  // shift right by 1    0..0000LL    = 3  = 6 / 2^1
  n7 = l >> 1;  // shift right by 1    0..0000L0    = 2  = 5 / 2^1

  cout << "\n   l      = " << l;
  cout << "\n   k      = " << k;
  cout << "\n   ~k     = " << n1;
  cout << "\n   k & l  = " << n2;
  cout << "\n   k | l  = " << n3;
  cout << "\n   k ^ l  = " << n4;
  cout << "\n   k << 2 = " << n5;
  cout << "\n   k >> 1 = " << n6;
  cout << "\n   l >> 1 = " << n7;
  cout << "\n\n";

  return 0;
}









