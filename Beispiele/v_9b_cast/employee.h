#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

/**  Abstrakte Basisklasse eines allgemeinen Angestellten */
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
//        virtual float payment() const = 0;   // rein virtuell
      virtual float payment() const {return 0.0f; }; // nur virtuell

        /**  Zugriff auf den Namen.
           @return  Name
        */
        string getname() const
         { return _name; }

        /**  Rueckgabe der Anzahlt der Instanzen von Employee und abgleiteten Klassen.
           @return  Anzahl.
        */
        static int get_Counter()  {return _counter;};

    protected:
    private:
        string _name;        //!< Name der Person
        static int _counter; //!<  e i n   Zaehler fuer alle Instanzen
};

ostream& operator<<(ostream &s, const Employee& org);



#endif // EMPLOYEE_H
