#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <iostream>
using namespace std;

/**   Template Klasse fuer komplexe Zahlen zur Demonstration.
*   @warning Bei Templateklassen (und -funktionen) muss der Implementierungsteil,
*   hier im File komplex.tpp, im Headerfile inkludiert werden.
*   Das Implementierungsfile darf nicht noch einmal ueberstzt werden!
*/
template <class T>
class Komplex
{
public:
    /** Default constructor */
    Komplex();
    /** Parameter constructor */
    //                         |-- Standardwert
    Komplex(T re, T im=0.0); // Parameterkonstruktor mit ein oder zwei Argumenten
    /** Default destructor */
    virtual ~Komplex();
    /** Abfrage des Realteils
     * \return Realteil
     */
    //               |--  Membervariablen werden durch die Instanz nicht veraendert!
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
    //               |--  Membervariablen werden durch die Instanz nicht veraendert!
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
    Komplex<T>& operator+=(const Komplex<T>& rhs);

    /**  Addiert die aktuelle Instanz mit einer zweiten komplexen Zahl
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this + \p rhs
    */
    //                                     |--  Membervariablen werden durch die Instanz nicht veraendert!
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
ostream& operator<<(ostream& s, const Komplex<T>& rhs);

    /**  Addiert zu einer reellen Zahl eine komplexe Zahl
    * \param[in] lhs relle Zahl
    * \param[in] rhs komplexe Zahl
    * \return    \p lhs + \p rhs
    */
template <class T>
Komplex<T> operator+(T lhs, const Komplex<T>& rhs);

#include "komplex.tpp"

#endif // KOMPLEX_H
