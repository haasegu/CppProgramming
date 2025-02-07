#pragma once

#include "myexceptions.h"		// Exeption handlers and classes
#include <iostream>

//! \brief My own vector class.
//!
//!   The macro DEBUG switches the range check on/off.
//!
class MyVector
{
public:
    //! \brief Allocates a vector with @p n elements on the heap.
    //!
    //! \param[in] n vector length
    //! \warning Throws an exception in case of insufficient memory on the heap.
    //!

    MyVector(const long long int n = 0);		// Standard-, Parameterkonstruktor

#ifndef WRONG_CODE
    //! \brief Allocates a vector with the same elements as vector @p orig and copies its elements.
    //!
    //! \param[in] orig original vector
    //! \warning Throws an exception in case of insufficient memory.
    //!
    MyVector(const MyVector& orig);	            // Copykonstruktor
#endif
    //! \brief Deallocates the heap memory.
    //!
    virtual ~MyVector();				        // Destruktor

#ifndef WRONG_CODE
    //! \brief Reallocates the vector with the same elements as vector @p orig and copies its elements.
    //!
    //! \param[in] orig original vector
    //! \warning Throws an exception in case of insufficient memory.
    //!
    MyVector& operator=(MyVector const &orig);	// Zuweisungsoperator
#endif 
    //! \brief Output of the vector @p orig.
    //!
    //! \param[in] s     output stream
    //! \param[in] orig  vector
    //! \warning Throws an exception in case of insufficient memory.
    //!
    friend std::ostream & operator<<(std::ostream & s, MyVector const & orig);

    //! \brief Returns the number of elements.
    //!
    //! \return Number of elements
    //!
    const long long int& size() const
    {
        return length_;
    }

    //! \brief Returns the value of element @p i.
    //!
    //! \param[in] i     index
    //! \return          value
    //! \warning Throws an exception "OutOfRange" in case an invalid index @p i.
    //!
    double& operator[](const long long int i)
    {
#ifndef NDEBUG
#pragma message(" ##########  Debug mode  ###############")
        IndexCheck(i);
#endif
        return val_[i];
    }

    //! \brief Returns the value of element @p i.
    //!
    //! \param[in] i     index
    //! \return          value
    //! \warning Throws an exception "OutOfRange" in case an invalid index @p i.
    //!
    const double& operator[](const long long int i) const		// const notw. fuer const. Instanzen von MyVektor
    {
#ifndef NDEBUG
#pragma message(" ##########  Debug mode  ###############")
        IndexCheck(i);
#endif
        return val_[i];
    }


private:
    //! \brief Checks whether @p i is an valid index, i.e.,@f$ i \in [0, length_ -1]@f$ .
    //!
    //! \param[in] i     index
    //! \warning Throws an exception "OutOfRange" in case of an invalid index @p i.
    //!
    void IndexCheck(const long long int &i) const
    {
        if ( i<0 || i>=size() )
            {throw OutOfRange(i,size()-1);}		// Indexfehler
    }

protected:		// private Members von MyVector duerfen in abgeleiteter Klasse benutzt werden
    long long int      length_;     //!< number of elements
    double * val_;                  //!< pointer to allocated memory
};




