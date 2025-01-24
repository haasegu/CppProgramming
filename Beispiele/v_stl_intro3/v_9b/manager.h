#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"

/**      Manager einer Verkaufsstelle
*/
class manager : public Employee
{
    public:
        /** Parameter constructor
         @param[in]  name  Name des Angestellten
         @param[in]  wageWeek Wochengehalt
        */
        manager(const string& name, float wageWeek);
        /** Default destructor */
        virtual ~manager();

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(ostream& s) const;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const {return _wageWeek;};
    protected:
    private:
        float _wageWeek; //!< Wochengehalt
};

#endif // MANAGER_H
