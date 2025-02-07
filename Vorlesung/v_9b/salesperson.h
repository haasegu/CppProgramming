#pragma once

#include "worker.h"
#include <iostream>
#include <string>

/**      Verkaeufer in einer Verkaufsstelle
*/
class salesPerson : public Worker
{
    public:
        /** Parameter constructor
         @param[in]  name  Name des Angestellten
         @param[in]  hours Arbeitsstunden
         @param[in]  wageHour  Stundenlohn
         @param[in]  commission Umsatz
         @param[in]  percent  Umsatzbeteiligung in Prozent
        */
        salesPerson(const std::string& name, float hours, float wageHour,
                    float commission, float percent);
        /** Default destructor */
        virtual ~salesPerson() override;

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(std::ostream& s) const override;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const override
         {return Worker::payment() + _commission*_percent;}

    protected:
    private:
        float _commission; //!< Umsatz
        float _percent; //!< Umsatzbeteiligung in Prozent
};

