//	student.h
#ifndef FILE_STUDENT
#define FILE_STUDENT

#include <string>
#include <vector>
using namespace std;
//-----------------------  Student  ----------------------------
struct Student {
    Student(): matrikel(0), skz(0), name(), vorname() {}
    long long int matrikel;
    int skz;
    string name, vorname;
};
//---------------------  Student_Mult  -------------------------
struct Student_Mult {                   // new structure
    Student_Mult(): matrikel(0), skz(0), name(), vorname() {}    
    long long int matrikel;
    vector<int> skz;                    // dynamic vector
    string name, vorname;
};

//	Copy Student onto Student_Mult

void Copy_Student(Student_Mult &lhs, const Student &rhs);

#endif



