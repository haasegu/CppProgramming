#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <cmath>
#include <iostream>
using namespace std;

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
     * \param[in]   rhs  Instance that is assigned to the members.
     * \return reference to the current instance.
     */
    Komplex& operator=(const Komplex& rhs);       // Zuweisungsoperator


    /** Abfrage des Realteils
     * \return Realteil
     */
    //               |--  Membervariablen dieser Instanz werden nicht veraendert!
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
    //               |--  Membervariablen dieser Instanz werden nicht veraendert!
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

    /**  Addiert die aktuelle Instanz mit einer zweiten komplexen Zahl
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this + \p rhs
    */
    //                                     |--  Membervariablen dieser Instanz werden nicht veraendert!
    Komplex operator+(const Komplex& rhs) const;

    /**  Vergleicht, ob die aktuelle Instanz kleiner als eine zweite komplexe Zahl ist
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this < \p rhs
    */
    //                                     |--  Membervariablen dieser Instanz werden nicht veraendert!
    bool operator<(const Komplex& rhs) const;

    /**  Vergleicht, ob die aktuelle Instanz gleich einer zweiten komplexe Zahl ist
    * \param[in] rhs zweite komplexe Zahl
    * \return    \p *this == \p rhs
    */
    //                                     |--  Membervariablen dieser Instanz werden nicht veraendert!
    bool operator==(const Komplex& rhs) const;

protected:
private:
    double _re; //!< Realteil
    double _im; //!< Imaginaerteil
};

// normale Funktionen

/** Ausgabeoperator fuer die Klasse Komplex.
 * \param[in] s  ein beliebiger Ausgabestrom
 * \param[in] rhs  die auszugebende Instanz der Klasse Komplex
 */
ostream& operator<<(ostream& s, const Komplex& rhs);

/**  Addiert zu einer reellen Zahl eine komplexe Zahl
* \param[in] lhs relle Zahl
* \param[in] rhs komplexe Zahl
* \return    \p lhs + \p rhs
*/
Komplex operator+(double lhs, const Komplex& rhs);


/**  Berechnet den Betrag einert komplexen Zahl
* \param[in] rhs komplexe Zahl
* \return    |\p rhs|
*/
inline double abs(const Komplex& rhs)
{
    return sqrt(rhs.Get_im()*rhs.Get_im()+rhs.Get_re()*rhs.Get_re());
}

#endif // KOMPLEX_H
