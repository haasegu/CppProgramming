#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

/**  Abstrakte Basisklasse eines allgemeinen Angestellten einer Verkaufsstelle
*/
class Employee
{
    public:
        /** Parameter constructor
         @param[in]  name  Name des Angestellten
        */
        explicit Employee(const string& name);
        /** Default destructor */
        virtual ~Employee();

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        virtual void print(ostream& s) const;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        virtual float payment() const = 0;   // rein virtuell
//            {return 0.0f; };               // da war die Methode nur virtuell

        /**  Zugriff auf Name des Angestellten.
           @return  Name.
        */
        string getname() const {return _name;}

        /**  Rueckgabe der Anzahlt der Instanzen von Employee und abgleiteten Klassen.
           @return  Anzahl.
        */
        static int get_Counter()  {return _counter;}

    protected:
    private:
        string _name;        //!< Name der Person
        static int _counter; //!<  e i n   Zaehler fuer alle Instanzen
};

#endif // EMPLOYEE_H
