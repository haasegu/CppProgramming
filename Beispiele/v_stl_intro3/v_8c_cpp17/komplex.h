#pragma once
#include <cassert>       // static_assert
#include <cmath>         // sqrt()
#include <iostream>
#include <type_traits>   // std::is_floating_point<T>()

//using namespace std;   // don't use in header

/**   Template Klasse fuer komplexe Zahlen zur Demonstration.
*   @warning Bei Templateklassen (und -funktionen) muss der Implementierungsteil,
*   hier im File komplex.tcc, im Headerfile inkludiert werden.
*   Das Implementierungsfile darf nicht noch einmal ueberstzt werden!
*/
template <class T>
class Komplex
{
    // check type of template at compile time
    static_assert(std::is_floating_point<T>(),
                  "Vector elements have to be floating point numbers.");  // C++11
public:
    /** Default constructor initializes both components by zero. */
    Komplex() : _re(T(0)), _im(T(0))
    { }
    
    /** Parameter constructor
     * \param[in] re Realteil
     * \param[in] im Imaginaerteil (default value: 0.0)
     */    //          |-- Standardwert
    Komplex(T re, T im=0.0) // Parameterkonstruktor mit ein oder zwei Argumenten
    : _re(re), _im(im)
    { }    
   // See rule of five: https://en.cppreference.com/w/cpp/language/rule_of_three
   //
    Komplex(const Komplex<T>&  org)               = default; // Copykonstruktor
    Komplex(      Komplex<T>&& org)               = default; // Movekonstruktor
    Komplex<T>& operator=(const Komplex<T>&  rhs) = default; // Copy-Zuweisungsoperator
    Komplex<T>& operator=(      Komplex<T>&& rhs) = default; // Move-Zuweisungsoperator
    ~Komplex()                                    = default; // Destruktor

    /** Abfrage des Realteils
     * \return Realteil
     */
    //            |--  Member der Instanz werden durch die Methode nicht veraendert!
    T Get_re() const
    {
        return _re;
    }
    /** Abfrage des Realteils
     * \param[in] val New value to set
     */
    void Set_re(T val)
    {
        _re = val;
    }
    /** Abfrage des Imaginaerteils
     * \return Imaginaerteil
     */
    //            |--  Member der Instanz werden durch die Methode nicht veraendert!
    T Get_im() const
    {
        return _im;
    }
    /** Setzen des Realteils
     * \param[in] val New value to set
     */
    void Set_im(T val)
    {
        _im = val;
    }

   /**  Addiert zur aktuellen Instanz eine zweite komplexe Zahl
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this += \p rhs
    */
    //
    Komplex<T>& operator+=(const Komplex<T>& rhs);

    /**  Addiert die aktuelle Instanz mit einer zweiten komplexen Zahl
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this + \p rhs
    */
    //                                             |--  Member der Instanz werden durch die Methode nicht veraendert!
    Komplex<T> operator+(const Komplex<T>& rhs) const;

    bool operator<(const Komplex<T>& rhs) const
    {
        return _re < rhs._re || ( _re == rhs._re && _im < rhs._im );
    }

    bool operator==(const Komplex<T>& rhs) const
    {
        return _re == rhs._re && _im == rhs._im ;
    }

    bool operator>(const Komplex<T>& rhs) const
    {
        return !( *this < rhs || *this== rhs ) ;
    }


protected:
private:
    T _re; //!< Realteil
    T _im; //!< Imaginaerteil
};

/** Ausgabeoperator fuer die Klasse.
 * \param[in] s  ein beliebiger Ausgabestrom
 * \param[in] rhs  die auszugebende Instanz
 */
template <class T>
std::ostream& operator<<(std::ostream& s, const Komplex<T>& rhs);


    /**  Addiert zu einer reellen Zahl eine komplexe Zahl
    * \param[in] lhs relle Zahl
    * \param[in] rhs komplexe Zahl
    * \return    \p lhs + \p rhs
    */
template <class T>
Komplex<T> operator+(T lhs, const Komplex<T>& rhs);


template <class T>
T abs(const Komplex<T>& rhs)
{
    return std::sqrt(rhs.Get_re()*rhs.Get_re()+rhs.Get_im()*rhs.Get_im());
}


#include "komplex.tcc"

