#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <iostream>
using namespace std;

/**   Klasse fuer komplexe Zahlen zur Demonstration.
*/
class Komplex
{
public:
    /** Default constructor */
    Komplex();
    /** Parameter constructor */
    //                         |-- Standardwert
    Komplex(double re, double im=0.0); // Parameterkonstruktor mit ein oder zwei Argumenten
    /** Default destructor */
    virtual ~Komplex();
    /** Abfrage des Realteils
     * \return Realteil
     */
    //               |--  Membervariablen werden durch die Instanz nicht veraendert!
    double Get_re() const
    {
        return _re;
    }
    /** Abfrage des Realteils
     * \param[in] val New value to set
     */
    void Set_re(double val)
    {
        _re = val;
    }
    /** Abfrage des Imaginaerteils
     * \return Imaginaerteil
     */
    //               |--  Membervariablen werden durch die Instanz nicht veraendert!
    double Get_im() const
    {
        return _im;
    }
    /** Setzen des Realteils
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
    //                                     |--  Membervariablen werden durch die Instanz nicht veraendert!
    Komplex operator+(const Komplex& rhs) const;

    bool operator<(const Komplex& rhs) const
        {
            return (_re < rhs._re || (_re == rhs._re && _im < rhs._im ));
        };
    bool operator==(const Komplex& rhs) const
        {
            return (_re == rhs._re && _im == rhs._im );
        };

protected:
private:
    double _re; //!< Realteil
    double _im; //!< Imaginaerteil
};

/** Ausgabeoperator fuer die Klasse.
 * \param[in] s  ein beliebiger Ausgabestrom
 * \param[in] rhs  die auszugebende Instanz
 */
ostream& operator<<(ostream& s, const Komplex& rhs);

    /**  Addiert zu einer reellen Zahl eine komplexe Zahl
    * \param[in] lhs relle Zahl
    * \param[in] rhs komplexe Zahl
    * \return    \p lhs + \p rhs
    */
Komplex operator+(double lhs, const Komplex& rhs);

#endif // KOMPLEX_H