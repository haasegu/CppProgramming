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
        
        salesPerson(salesPerson const&) = default;
        salesPerson& operator=(salesPerson const&) = delete;

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(std::ostream& s) const override;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const override
         {return Worker::payment() + _commission*_percent;}
         
        /**  Neuangabe des Umsatzes
           @param[in]  umsatz  Umsatz der Woche in EUR
        */
        void setSales(const float umsatz) { _commission=umsatz;}

        /**  Neuangabe der Umsatzbeteiligung
           @param[in]  percent  neue Umsatzbeteiligung in %
        */
        void setComission(const float percent) { _percent=percent;}

    protected:
    private:
        float _commission; //!< Umsatz
        float _percent; //!< Umsatzbeteiligung in Prozent
};

