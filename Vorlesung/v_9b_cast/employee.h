#pragma once

#include <iostream>
#include <string>

/**  Abstrakte Basisklasse eines allgemeinen Angestellten einer Verkaufsstelle
*/
class Employee
{
    public:
        /** Parameter constructor
         @param[in]  name  Name des Angestellten
        */
        explicit Employee(const std::string& name); // explicit suggested by Intel compiler for a on-element parameter list in constructor
        /** Default destructor */
        virtual ~Employee();
        
        Employee(Employee const&) = default;
        Employee& operator=(Employee const&) = delete;
        

        /**  Gibt die Daten der aktuellen Instanz aus.
           @param[in,out] s  Ausgabestrom
        */
        virtual void print(std::ostream& s) const;

        /**  Berechnet das Gehalt.
           @return  Gehalt.
        */
        virtual float payment() const // = 0;   // rein virtuell
            {return 0.0f; }                // da war die Methode nur virtuell

        /**  Rueckgabe der Anzahlt der Instanzen von Employee und abgleiteten Klassen.
           @return  Anzahl.
        */
        int get_Counter() const {return _counter;}

    protected:
    private:
        std::string _name;        //!< Name der Person
        static int _counter; //!<  e i n   Zaehler fuer alle Instanzen
};

std::ostream& operator<<(std::ostream &s, const Employee& org);     // Deklaration

