#ifndef SALESPERSON_H
#define SALESPERSON_H

#include "worker.h"

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
        salesPerson(const string& name, int hours, float wageHour,
                    float commission, float percent);
        /** Default destructor */
        virtual ~salesPerson();

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(ostream& s) const;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const
         {return Worker::payment() + _commission*_percent;};

    protected:
    private:
        float _commission; //!< Umsatz
        float _percent; //!< Umsatzbeteiligung in Prozent
};

#endif // SALESPERSON_H
