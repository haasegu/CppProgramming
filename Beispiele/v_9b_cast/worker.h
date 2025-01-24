#ifndef WORKER_H
#define WORKER_H

#include "employee.h"

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
        Worker(const string& name, float hours, float wageHours);
        /** Default destructor */
        virtual ~Worker();

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        void print(ostream& s) const;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        float payment() const
            {return _hours*_wageHours ; };
    protected:
    private:
        float _hours; //!< Arbeitsstunden
        float _wageHours; //!< Member Stundenlohn
};

#endif // WORKER_H
