//	studenten4.h
#ifndef FILE_STUDENTEN
#define FILE_STUDENTEN

#include <iostream>
using namespace std;

class Studenten {
//			Data in Studenten are private now!!
private:
    long int matrikel;
    int skz;
    char *pname, *pvorname;

//			Methods in Studenten
public:

//				Default constructor (no argument)
    Studenten();

//				Constructor with 4 arguments
    Studenten(const char vorname[], const char name[],
              const long int  mat_nr = 0,   const int  skz_nr = 0);

//				Copy constructor
    Studenten(const Studenten &orig);

//				Destructor
    ~Studenten();

//				Assignment operator
    Studenten &operator=(const Studenten &orig);

//				Output operator
    friend ostream &operator<<(ostream   &s, const Studenten &orig);
//				Print method
    void Print(ostream   &s);

//		Methods to access the private data
//			Methods for data manipulation in Studenten

    void SetVorname(const char vorname[]);
    void SetName(const char name[]);
    void SetMatrikel(const long int  mat_nr) {
        matrikel = mat_nr;
    };			// inline function
    void SetSKZ(const int  skz_nr) {
        skz = skz_nr;
    };			// inline function

//			Methods that don't manipulate data in Studenten

    const long int &GetMatrikel() const {
        return matrikel;
    };
    const int &GetSKZ() const {
        return skz;
    };
    const char *GetVorname() const {
        return pvorname;
    };
    const char *GetName() const {
        return pname;
    };

};

#endif








