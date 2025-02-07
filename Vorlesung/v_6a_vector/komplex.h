#pragma once
#include <iostream>
//using namespace std;

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

   /** Copy constructor
     * \param[in] org Instance to copy from
     */
    //
    Komplex(const Komplex& org); // Kopierkonstruktor

    /** Default destructor */
    virtual ~Komplex();

    /** \brief Assignment operator
     *
     * \param[in]   rhs  Instance that is assigned to the members.
     * \return reference to the current instance.
     *
     */
    Komplex& operator=(const Komplex& rhs);       // Zuweisungsoperator


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
    Komplex operator+(const Komplex& rhs) const;

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


/**  Addiert zu einer reellen Zahl eine komplexe Zahl
* \param[in] lhs relle Zahl
* \param[in] rhs komplexe Zahl
* \return    \p lhs + \p rhs
*/
Komplex operator+(double lhs, const Komplex& rhs);
