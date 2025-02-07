#pragma once

#include <iostream>
class Komplex
{
    public:
        /** Default constructor */
        Komplex(float re, float im);
        /** Default destructor */
        virtual ~Komplex();

        /** Access _re
         * \return The current value of _re
         */
        float Get_re() const { return _re; }
        /** Set _re
         * \param val New value to set
         */
        void Set_re(float val) { _re = val; }
        /** Access _im
         * \return The current value of _im
         */
        float Get_im() const { return _im; }
        /** Set _im
         * \param val New value to set
         */
        void Set_im(float val) { _im = val; }

        float abs() const;

        /** \brief Add complex number @p rhs to current instance
         *
         * \param[in] rhs
         * \return *this + @p rhs
         *
         */
        Komplex add(Komplex const &rhs) const;

        /** \brief Add complex number @p rhs to current instance
         *
         * \param[in] rhs
         * \return *this + @p rhs
         *
         */
        Komplex operator+(Komplex const &rhs) const;

        // Ausgabeoperator ist keine Methode der Klasse

    protected:

    private:
        float _re; //!< Member variable "_re"
        float _im; //!< Member variable "_im"
};

// Ausgabeoperator
std::ostream& operator<<(std::ostream& s, Komplex const &rhs);
