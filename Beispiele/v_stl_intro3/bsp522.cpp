//	Ex650.cpp

//	Sec. 6.5 of lecture
//	Dynamic array of type student
//	Input: a.out < input.522

#include <iostream>
#include <string>                       // class string
#include <vector>                       //       vector
using namespace std;

struct Student {
    Student(): matrikel(0), skz(0), name(), vorname() {}
    long long int matrikel;
    int skz;
    string name, vorname;
};

int main()
{
    vector<Student> gruppe;              // Vector of Student

    cout << "\n How many Students : ";
    unsigned int n;
    cin >> n;		                     // input #students
    gruppe.resize(n);                    // 4 students (dynamic vector!)

    for (size_t i = 0; i < gruppe.size(); ++i) {
        cout << endl << "Student nr. " << i << " : " << endl;
        cout << "Familenname : ";
        cin  >> gruppe[i].name;          // [i]     no range check for index
        cout << "Vorname     : ";
        cin  >> gruppe.at(i).vorname;    // at(i) with range check for index
        cout << "Matrikelnummer : ";
        cin  >> gruppe[i].matrikel;
        cout << "SKZ            : ";
        cin  >> gruppe[i].skz;
    }
    cout << endl;

    unsigned int idx = 3;
    cout << endl;
    cout << "Student nr. " << idx << " : ";
    cout << gruppe[idx].vorname << " " << gruppe[idx].name << " , ";
    cout << gruppe[idx].matrikel << " , " << gruppe[idx].skz << endl;
    return 0;
}









