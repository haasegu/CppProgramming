//	Demo of Union and interpretation od memory areas
//	Union
//  consexpr is needed for compilation

#include <cstddef>            // byte
#include <iostream>           // cout, endl, boolalpha
using namespace std;

union MischMasch {
    char       c[sizeof(int)];
    bool      bl[sizeof(int)];   
    byte      by[sizeof(int)];   
    int8_t    ic[sizeof(int)];
    short int si[sizeof(int)/2];
    int        i;
    float      f;
};

ostream& operator<<(ostream& s, MischMasch const & mm);

template <typename T>
ostream& printCvector(ostream& s, const T cv[], int N);

int main()
{
    MischMasch u{"abc"};      // Variable of union type: char[4]
    cout << "init with:  " << u.c << "   " << u << endl;
    
    u.i = 1234567;            //   int32
    cout << "init with:  " << u.i << "   " << u << endl;
    
    u.f = 3.4f;             //   float     
    cout << "init with:  " << u.f << "   " << u << endl;
    
    return 0;
}


ostream& operator<<(ostream& s, MischMasch const & mm)
{
    int const NMM=sizeof(mm);  // #Bytes for storage
    s << "--- MischMasch with " << NMM << " Bytes ---" << endl;
    s << "address:  " << &mm.i << "  (int   )  " << mm.i << endl;
    s << "address:  " << &mm.f << "  (float )  " << mm.f << endl;
    s << "address:  " << &mm.c << "  (char[])  |" << mm.c << "|" << endl;
    s << "address:  " << &mm.c << "  (char[])  |";
    printCvector(cout,mm.c,NMM) << "|" << endl;
    
    s << "address:  " << &mm.ic << "  (int8[])  |";
    printCvector(cout,mm.ic,NMM) << "|" << endl;
 
    s << "address:  " << &mm.si << "  (int16[]) |";
    printCvector(cout,mm.si,NMM/2) << "|" << endl;
    
    std::cout.setf(std::ios::boolalpha);       // output {false/true)
    s << "address:  " << &mm.bl << "  (bool[])  |";
    printCvector(cout,mm.bl,NMM) << "|" << endl;  
    std::cout.unsetf(std::ios::boolalpha);     // reset {false/true)
    
    s << "address:  " << &mm.by << "  (byte[])  |";
    printCvector(cout,mm.by,NMM) << "|" << endl;  
  
    return s;
} 

//https://en.cppreference.com/w/cpp/types/byte
#include <bitset>  // bitset
#include <cstddef> // byte, to_integer()
#include <type_traits>        // is_same
std::ostream& operator<<(std::ostream& os, std::byte b);
std::ostream& operator<<(std::ostream& os, std::byte b)
{
    return os << std::bitset<8>(std::to_integer<int>(b));
}

template <typename T>
ostream& printCvector(ostream& s, const T cv[], int N)
{
    for (int k=0; k<N; ++k)
    {
        if constexpr (is_same_v<T,bool>)
        {
            s << boolalpha << cv[k] << "  ";  // bool
        }
        else if constexpr (is_same_v<T,signed char> || is_same_v<T,unsigned char>)
        {
            s << +cv[k] << "  ";              // signed char
        }
        else
        {
            s << cv[k] << "  ";               // all other types
        }
    }
    return s;
}



