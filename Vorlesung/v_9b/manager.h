#pragma once

#include "employee.h"
#include <iostream>
#include <string>

/**      Manager einer Verkaufsstelle
*/
class manager : public Employee
{
    public:
        /** Parameter constructor
         @param[in]  name  Name des Angestellten
         @param[in]  wageWeek Wochengehalt
        */
        manager(const std::string& name, float wageWeek);
        /** Default destructor */
        virtual ~manager() override;

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(std::ostream& s) const override;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const override {return _wageWeek;}
    protected:
    private:
        float _wageWeek; //!< Wochengehalt
};

