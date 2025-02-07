#pragma once

#include "employee.h"
#include <iostream>
#include <string>

/**      Normaler Arbeiter (Packer) in einer Verkaufsstelle.
*/
class Worker : public Employee
{
    public:
        /** Parameter constructor
         @param[in]  name  Name des Angestellten
         @param[in]  hours Arbeitsstunden
         @param[in]  wageHours  Stundenlohn
        */
        Worker(const std::string& name, float hours, float wageHours);
        /** Default destructor */
        ~Worker() override;
        
        Worker(Worker const&) = default;
        Worker& operator=(Worker const&) = default;

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(std::ostream& s) const override;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const override 
            {return _hours*_wageHours ; }
    protected:
    private:
        float _hours; //!< Arbeitsstunden
        float _wageHours; //!< Member Stundenlohn
};
