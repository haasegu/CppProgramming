
#include <iostream>
#include <string>
using namespace std;

class Studenten
{
//			Methods in Studenten
public:
//				Default constructor (no argument)
 Studenten();

//				Constructor with 4 arguments
 Studenten(const string& vorname, const string& name,
           const long int  matrikel = 0,   const int  skz = 0);

//				Copy constructor (automatic by compiler)
//				Destructor (automatic by compiler)
//				Assignment operator (automatic by compiler)

//				Output operator is friend
 friend ostream & operator<<(ostream  & s, const Studenten & orig);

//				Print method
 void Print(ostream  & s) const;

//		Methods to access the private data
//			Methods for data manipulation in Studenten

 void SetVorname(const string& vorname) { _vorname=vorname; };
 void SetName(const string& name) {_name=name; };
 void SetMatrikel(const long int  matrikel) { _matrikel=matrikel; };
 void SetSKZ(const int  skz) { _skz = skz; };

//			Methods that don't manipulate data in Studenten

 long int GetMatrikel() const { return _matrikel; };
 int GetSKZ() const { return _skz; };
 const string& GetVorname() const { return _vorname; };
 const string& GetName() const { return _name; };
//			Data in Studenten
public:
  long int _matrikel;          //!< student ID
       int _skz;               //!< study ID
    string _name, _vorname;    //!< family name and first name
};









