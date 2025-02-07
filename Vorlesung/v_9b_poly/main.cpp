//     Vorlesung: 08.06.2018
//     Klassenhierarchie:
//                    Employee
//             Manager         Worker
//                             SalesPerson

#include "employee.h"
#include "manager.h"
#include "salesperson.h"
#include "worker.h"

#include <algorithm>          // sort
#include <iostream>
#include <memory>             // shared_ptr
#include <numeric>            //  accumulate
#include <vector>

using namespace std;

// needed for sorting of base class pointers
inline bool kleiner(const Employee* lhs, const Employee* rhs)
{
    return lhs->payment() < rhs->payment();
}


int main()
{
    cout << "Hello world!" << endl;

    //Employee aa("Angestellter");       // rein virtuelle Methode payment()
    // ==> abstrakte Basisklasse Employee
    // ==> keine Instanz von Employee mehr moeglich
    Worker bb("Hugo", 160, 15.50f);
    salesPerson cc("Wanda", 80, 10.2f, 10000, 0.05f);
    manager dd("Brenda", 2000);
    cout << "----------------\n" << cc << "----------------\n" << endl;

//  -------------------------  Only one class type   ----------------------:
    {

        cout << "\n---  vector with one class type ---\n";
        vector<manager>  vm { manager("Wendolin",1000000), dd, manager("Jogi",61500), manager("Oliva", 90000) };

        cout << "##   vor Sortierung:" << endl;
        for (const auto &it: vm) cout << it << endl;

        sort(vm.begin(),vm.end());         // requires  bool operator<(const Employee& lhs, const Employee& rhs)

        cout << "##   nach Sortierung:" << endl;
        for (const auto &it: vm) cout << it << endl;

        // Search for a Name: use lambda function
        //    http://en.cppreference.com/w/cpp/language/lambda
        const string cmp("Brenda");
        const auto ip = find_if(vm.begin(),vm.end(),
                                [cmp](const Employee& a) -> bool {return a.Get_name() == cmp; }
                               );
        if ( ip!=vm.cend() ) cout << "I found " << cmp << "  !!" << endl << *ip << endl;


        // Add the payments: accumulate
        const float sal = accumulate(vm.cbegin(), vm.cend(), 0.0f,
                                     [](float x, const Employee& rhs) -> float {return x+rhs.payment();}
                                     );
        cout << "Sum of saleries: " << sal << endl;

    }

    //  -------------------------  Now: with vector of basis class pointers   ----------------------:
    {

        cout << "\n---  vector with base class pointers ---\n";
        vector<Employee*>  vm{ new manager("Wendolin",1000000), new Worker("Hugo", 160, 15.50f) ,
                               new salesPerson("Wanda", 80, 10.2f, 10000, 0.05f), new manager("Oliva", 90000) };

        cout << "##   vor Sortierung:" << endl;
        for (const auto &it: vm) cout << *it << endl;         // Dereferencing the base class pointer

        //sort(vm.begin(),vm.end());         // requires  bool operator<(const Employee* lhs, const Employee* rhs): cannot be provided
        //sort(vm.begin(),vm.end(),kleiner);
        sort(vm.begin(),vm.end(),
//             [](const Employee* a, const Employee* b) -> bool {return a->payment() < b->payment(); }
             [](const Employee* a, const Employee* b) -> bool {return *a < *b; }
             );

        cout << "##   nach Sortierung:" << endl;
        for (const auto &it: vm) cout << *it << endl;

        // Search for a Name: use lambda function
        //    http://en.cppreference.com/w/cpp/language/lambda
        const string cmp("Hugo");
        const auto ip = find_if(vm.begin(),vm.end(),
                                [cmp](const Employee* a) -> bool {return a->Get_name() == cmp; }
                               );
        if ( ip!=vm.cend() ) cout << "I found " << cmp << "  !!" << endl << **ip << endl;


        // Add the payments: accumulate
        const float sal = accumulate(vm.cbegin(), vm.cend(), 0.0f,
                                     [](float x, const Employee* rhs) -> float {return x+rhs->payment();}
                                     );
        cout << "Sum of saleries: " << sal << endl;

        // Do not forget to free the memory
        for (auto &it: vm) delete it;
    }

    //  -------------------------  Now: with vector of basis class shared pointers   ----------------------:
    {

        cout << "\n---  vector with base class shared pointers ---\n";
        vector<shared_ptr<Employee>>
            vm{ make_shared<manager>("Wendolin",1000000), make_shared<Worker>("Hugo", 160, 15.50f) ,
                make_shared<salesPerson>("Wanda", 80, 10.2f, 10000, 0.05f), make_shared<manager>("Oliva", 90000) };

        cout << "##   vor Sortierung:" << endl;
        for (const auto &it: vm) cout << *it << endl;         // Dereferencing the base class pointer

        //sort(vm.begin(),vm.end());         // requires  bool operator<(const Employee* lhs, const Employee* rhs): cannot be provided
        //sort(vm.begin(),vm.end(),kleiner);
        sort(vm.begin(),vm.end(),
             //[](const Employee* a, const Employee* b) -> bool {return a->payment() < b->payment(); }
//             [](const shared_ptr<Employee> &a, const shared_ptr<Employee> &b) -> bool {return *a < *b; }
             [](const auto &a, auto &b) -> bool {return *a < *b; }
             );

        cout << "##   nach Sortierung:" << endl;
        for (const auto &it: vm) cout << *it << endl;

        // Search for a Name: use lambda function
        //    http://en.cppreference.com/w/cpp/language/lambda
        const string cmp("Hugo");
        const auto ip = find_if(vm.begin(),vm.end(),
                                [cmp](const auto &a) -> bool {return a->Get_name() == cmp; }
                               );
        if ( ip!=vm.cend() ) cout << "I found " << cmp << "  !!" << endl << **ip << endl;


        // Add the payments: accumulate
        const float sal = accumulate(vm.cbegin(), vm.cend(), 0.0f,
                                     [](float x, const auto &rhs) -> float {return x+rhs->payment();}
                                     );
        cout << "Sum of saleries: " << sal << endl;

        // Do not forget to free the memory
        //for (auto &it: vm) delete it;            // not needed with shared_ptr
    }   //                                            now, shared_ptr will be deallocated

    return 0;
}
