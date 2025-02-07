#include "myvector.h"
#include <cassert>		//	NEW: assert()
#include <iostream>
#include <new>			//	NEW: new(nothrow)

using namespace std;

MyVector :: MyVector(const long long int n )		// Standard-, Parameterkonstruktor
    : length_( n>0 ? n : 0), val_(nullptr)
{
    //
    //                        Restrict available memory in the shell  by:
    //				ulimit
    //
    cout << "--> " << length_ << endl;
    if ( length_>0 )
    {
//        val_    = new(nothrow) double [length_];  // no exception is thrown
        val_    = new double [length_];	     // throws "bad_alloc" in case of insufficient memory
//        assert(val_ != nullptr);
        cout << "##  " << val_ << endl;
    }
}

// ToDo: Add copy constructor
//       use constructor delegation
#ifndef WRONG_CODE
MyVector :: MyVector(MyVector const &orig)
 : MyVector(orig.length_)
  {
      for (long long int i=0; i<length_; i++)
        {
            val_[i] = orig.val_[i];
        }
  }
#endif

MyVector :: ~MyVector()				// Destruktor
{
    delete [] val_;
}

// ToDo: Add assignment operator
#ifndef WRONG_CODE
MyVector& MyVector :: operator=(MyVector const &orig)	// copy assignment
{
    if (this != &orig)
    {
        delete [] val_;
        length_ = orig.length_;
        if (length_>0)
        {
            val_ = new double [length_];
            for (long long int i=0; i<length_; i++)
            {
                val_[i] = orig.val_[i];
            }
        }
        else
        {
            val_ = nullptr;
        }
    }
    return *this;
}
#endif

ostream & operator<<(ostream & s, MyVector const &orig)
{
    long long int i;

    s << endl << "MyVector has " << orig.size() << " components" << endl;
    for (i=0; i<orig.size(); i++)
    {
        s << orig[i]<< "  ";
    }
    s << endl;

    return s;
}

