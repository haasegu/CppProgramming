#pragma once
#include <cmath>         // hypot()
#include <iostream>

/**   Klasse fuer komplexe Zahlen zur Demonstration.
*/
class Komplex
{
public:
    /** Default constructor */
    Komplex();
    /** Parameter constructor
     * \param[in] re Realteil
     * \param[in] im Imaginaerteil (default value: 0.0)
     */
    //                         |-- Standardwert
    Komplex(double re, double im=0.0); // Parameterkonstruktor mit ein oder zwei Argumenten

   // See rule of five
   // https://en.cppreference.com/w/cpp/language/rule_of_three
   //
    Komplex(const Komplex&  org)            = default; // Copykonstruktor
    Komplex(      Komplex&& org)            = default; // Movekonstruktor
    Komplex& operator=(const Komplex&  rhs) = default; // Copy-Zuweisungsoperator
    Komplex& operator=(      Komplex&& rhs) = default; // Move-Zuweisungsoperator
    ~Komplex()                              = default; // Destruktor

    /** Abfrage des Realteils
     * \return Realteil
     */
    //               |--  Membervariablen werden durch die Methode nicht veraendert!
    double Get_re() const
    {
        return _re;
    }

    /** Setzen des Realteils
     * \param[in] val New value to set
     */
    void Set_re(double val)
    {
        _re = val;
    }

    /** Abfrage des Imaginaerteils
     * \return Imaginaerteil
     */
    //               |--  Membervariablen werden durch die Methode nicht veraendert!
    double Get_im() const
    {
        return _im;
    }

    /** Setzen des Imaginaerteils
     * \param[in] val New value to set
     */
    void Set_im(double val)
    {
        _im = val;
    }

    /**  Addiert zur aktuellen Instanz eine zweiten komplexen Zahl
    * \param[in] rhs zweite komplexe Zahl
    * \return    aktuelle Instanz
    */
    Komplex& operator+=(const Komplex& rhs);

    /**  Addiert die aktuelle Instanz mit einer zweiten komplexen Zahl
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this + \p rhs
    */
    //                                     |--  Membervariablen werden durch die Methode nicht veraendert!
    //Komplex operator+(const Komplex& rhs) const;

    /**  Vergleicht die aktuelle Instanz mit einer zweiten komplexen Zahl.
     *   Es werden nur die Realantele verglichen.
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this < \p rhs
    */
    //                                     |--  Membervariablen werden durch die Methode nicht veraendert!
    bool operator<(const Komplex& rhs) const
    {
        return _re < rhs._re;
    }

    /**  Berechnet den Betrag.
     *   Nutzt <a href="https://en.cppreference.com/w/cpp/numeric/math/hypot">hypot</a> aus cmath.
     *
    * \return  Betrag der komplexen Zahl
    */
    //              |--  Membervariablen werden durch die Methode nicht veraendert!
    double abs() const
    {
        return std::hypot(_re,_im);
    }

protected:
private:
    double _re; //!< Realteil
    double _im; //!< Imaginaerteil
};

// normale Funktionen

/** Ausgabeoperator fuer die Klasse Komplex.
 * \param[in] s  ein beliebiger Ausgabestrom
 * \param[in] rhs  die auszugebende Instanz der Klasse Komplex
 * \return Ausgabestrom
 */
std::ostream& operator<<(std::ostream& s, const Komplex& rhs);

/** Eingabeoperator fuer die Klasse Komplex.
 * \param[in] s  ein beliebiger Eingabestrom
 * \param[out] rhs  die einzulesende Instanz der Klasse Komplex
 * \return Eingabestrom
 */
std::istream& operator>>(std::istream& s, Komplex& rhs);


/**  Addiert zwei komplexe Zahlen
* \param[in] lhs komplexe ahl
* \param[in] rhs komplexe Zahl
* \return    \p lhs + \p rhs
*/
inline
Komplex operator+(const Komplex& lhs, const Komplex& rhs)
{
   Komplex tmp(lhs);
   return tmp+=rhs;
}


