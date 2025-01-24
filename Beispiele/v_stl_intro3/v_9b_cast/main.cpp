//     Vorlesung: 22.05.2015
//     Klassenhierarchie:
//                    Employee
//             Manager         Worker
//                             SalesPerson
#include <iostream>
#include <cassert>        // assert
#include <typeinfo>       // std::bad_cast
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "salesperson.h"
using namespace std;

//! @brief Shows polymorphism by calling methods via base class pointer (correct pointer upcasting) and VMT.
//!
//! @param[in] aSale Instance of the derived class
//!

void pointer_use_methods(salesPerson  aSale)
{
    cout << "  ***  Anwendung von Methoden via Basispointern der Klasse" << endl;
    cout << aSale << endl;
    salesPerson *salePtr (& aSale);	   // Pointer auf SalesPerson-Klasse
    Worker      *wagePtr (& aSale);    // Pointer auf Basisklasse

    // Benutzung von Methoden
    salePtr->setSales(20000);	// salesPerson :: setSales
//  wagePtr->setSales(20000);	// WagePerson  :: setSales  gibt es nicht !!

    cout << salePtr->payment() << endl;		// salePtr  --(VMT) --> salesPerson ::payment
    cout << wagePtr->payment() << endl;		// wagePtr  --(VMT) --> salesPerson::payment

    cout << *salePtr << endl;

    return;
}

//! @brief Shows correct downcast (C-style) from base class pointer to pointer of derived class.
//!
//! @param[in] aSale Instance of the derived class
//! @warning   no check for correctness in C-casting
//!
void pointer_correct_downcast_C(salesPerson  aSale)
{
    cout << "  ***  korrektes Pointer Downcasting: C-Style (DANGER !! kein Test)" << endl;
    Worker      *wagePtr (& aSale);    // Pointer auf Basisklasse

    // Mit Pointern geht jeder Quatsch
    salesPerson *salePtr;	            // Pointer auf SalesPerson-Klasse
    //salePtr = wagePrt;			    // geht nicht, da kein implizites Downcasting moeglich ist
    salePtr = (salesPerson *) wagePtr;	// expizite Typkonvertierung, gefaehrlich !!
    cout << salePtr->payment() << endl; // hier klappt diese aber, da hinter wagePtr ein Object der Klasse salesPerson steckt
    cout << *salePtr << endl;
    return;
}

//! @brief Shows correct downcast (C++-style) from base class pointer to pointer of derived class.
//!
//! @param[in] aSale Instance of the derived class
//! @warning   checks for correctness (null pointer?) and stops otherwise
//!
void pointer_correct_downcast_dynamic(salesPerson  aSale)
{
    cout << "  ***  korrektes Pointer Downcasting: C++-Style (Test zur Laufzeit)" << endl;
    Worker      *wagePtr (& aSale);    // Pointer auf Basisklasse

    salesPerson *salePtr;              // Pointer auf SalesPerson-Klasse
    salePtr = dynamic_cast<salesPerson *>(wagePtr);  // Korrekter Versuch des Downcasting des Pointers
    if ( salePtr==nullptr )                         // nullptr falls Downcasting nicht moeglich ist.
    {
        cout << "\nDowncasting ging schief. Panic Exit.\n" << endl;
        assert(salePtr!=nullptr);
    }
    cout << salePtr->payment() << endl;
    cout << *salePtr << endl;
    return;
}

//! @brief Shows incorrect downcast (C-style) from base class pointer to pointer of derived class.
//!
//! @param[in] simple Instance of base class
//! @warning   No check for correctness in C-casting. Sometimes the code crashes (and that's good).
//!
void pointer_wrong_downcast_C(Employee  simple)
{
    cout << "  ***  falsches Pointer Downcasting: C-Style (kein Test -> Code crashes or not)" << endl;
    Employee *empPtr (&simple);	// --> einfacher Employee

    salesPerson *sale_Ptr;
    sale_Ptr = (salesPerson *)empPtr;	// syntaktisch erlaubt, aber falsch da empPtr wirklich nur auf Basisklasse zeigt

    cout << endl << "         jetzt kracht es" << endl;
    sale_Ptr->setComission(0.06);		// nunmehr formal (ohne vorherige Zeile) machbar, aber katastrophal da diese Methode in Employee nicht existiert
    cout << sale_Ptr->payment() << endl;
    cout << *sale_Ptr << endl;
    return;
}

//! @brief Shows incorrect downcast (C++-style) from base class pointer to pointer of derived class.
//!
//! @param[in] simple Instance of base class
//! @warning   checks for correctness (null pointer?) and stops
//!
void pointer_wrong_downcast_dynamic(Employee  simple)
{
    cout << "  ***  falsches Pointer Downcasting: C++-Style (Test -> Fehler kann bemerkt werden)" << endl;
    Employee *empPtr (&simple);	// --> einfacher Employee

    salesPerson *salePtr;
    salePtr = dynamic_cast<salesPerson *>(empPtr);  // Korrekter Versuch des Downcasting des Pointers
    if ( salePtr==nullptr )                         // nullptr falls Downcasting nicht moeglich ist.
    {
        cout << "\nDowncasting ging schief. Panic Exit.\n" << endl;
        assert(salePtr!=nullptr);
    }
    cout << endl << "         jetzt kracht es" << endl;
    salePtr->setComission(0.06);		// nunmehr formal (ohne vorherige Zeile) machbar, aber katastrophal da diese Methode in Employee nicht existiert
    cout << salePtr->payment() << endl;
    cout << *salePtr << endl;
    return;
}


//! @brief Shows correct downcast (C++-style) from base class reference to derived class reference.
//!
//! @param[in] simple Instance of derived class
//! @exception <std::bad_cast>  in case downcasting was incorrect.
//!
void referenz_correct_downcast_dynamic(salesPerson  aSale)
{
    cout << "  ***  korrektes Referenz Downcasting: C++-Style (Test -> Fehler kann bemerkt werden)" << endl;
    Worker& wageRef (aSale);

    try
    {                         // Korrekter Versuch des Downcasting der Referenz
        salesPerson& saleRef = dynamic_cast<salesPerson&>(wageRef);

        saleRef.setComission(0.06f);
        cout << saleRef.payment() << endl;
        cout << saleRef << endl;
    }
    catch (std::bad_cast& bc)
    {
        std::cerr << "bad_cast caught: " << bc.what() << '\n';
        assert(false);        // and my panic exit
    }
    return;
}

//! @brief Shows incorrect downcast (C++-style) from base class reference to derived class reference.
//!
//! @param[in] simple Instance of base class
//! @exception <std::bad_cast>  downcasting is incorrect.
//!
void referenz_wrong_downcast_dynamic(Employee  simple)
{
    cout << "  ***  falsches Referenz Downcasting: C++-Style (Test -> Fehler kann bemerkt werden)" << endl;
    Employee& empRef (simple);	     // --> einfacher Employee

    try
    {                         // Korrekter Versuch des Downcasting der Referenz
        salesPerson& saleRef = dynamic_cast<salesPerson&>(empRef);

        saleRef.setComission(0.06f);
        cout << saleRef.payment() << endl;
        cout << saleRef << endl;
    }
    catch (std::bad_cast& bc)
    {
        std::cerr << "bad_cast caught: " << bc.what() << '\n';
        assert(false);        // and my panic exit
    }
    return;
}


int main()
{
    salesPerson  aSale("Buddy Holly", 80, 10.2f, 10000, 0.05f);
    cout << aSale << endl;

    pointer_use_methods(aSale);

    // korrektes DownCasting mit Pointern
    pointer_correct_downcast_C(aSale);
    pointer_correct_downcast_dynamic(aSale);

    // inkorrektes UpCasting mit Pointern
    Employee  simple("Josef Gruber");
    pointer_wrong_downcast_C(simple);
    //pointer_wrong_downcast_dynamic(simple);

    referenz_correct_downcast_dynamic(aSale);
    referenz_wrong_downcast_dynamic(simple);


    return 0;
}
