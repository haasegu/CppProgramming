#pragma once
#include <iostream>   // ostream
#include <string>
#include <vector>
//using namespace std;

/**  Klasse Student, welche nun mehrere SKZ speichert.
*/
class Student
{
public:
    /** Default constructor */
    Student();

//! Constructor for a student with a single study ID
//!
//! @param[in] name     name of student
//! @param[in] matrikel student ID
//! @param[in] studium  study ID
//!
    Student(const std::string& name, const std::string& matrikel, const int studium);

//! Constructor for a student with a single study ID
//!
//! @param[in] name     name of student
//! @param[in] matnr    student ID
//! @param[in] skz      vector of study IDs
//!
    Student(const std::string & name, const std::string& matnr, const std::vector<int>& skz);

    // automatic generation of copy constructor and assignment operator by the compiler
    // in C++11: the Assignment operator (and any other method) can be explicitely deleted via:
    // Student& operator=(const Student& other) = delete;
    Student(const Student  &orig) = default;
    Student(      Student &&orig) = default;
    // const member '_matr_nr' ==> kein Zuweisungsoperator moeglich!    
    Student& operator=(const Student  &rhs) = delete;
    Student& operator=(      Student &&rhs) = delete;


    /** destructor */
    //virtual
     ~Student() { }

    /** Access name
     * \return The current value of name
     */
    std::string Getname() const
    {
        return _name;
    }

    /** Set name
     * \param val New value to set
     */
    void Setname(const std::string &val) { _name = val; }

    /** Access student ID
     * \return The current value of matr_nr
     */

    std::string Getmatr_nr() const
    {
        return _matr_nr;
    }

    /** Fuegt eine Studienkennzahl (SKZ) hinzu.
     * \param[in] skz_in  zusaetzliche SKZ
     * \warning  Es wird nicht ueberprueft, ob diese SKZ bereits gespeichert ist.
     *           Dies wuerde ein  find  oder ein unique  erfordern.
     */
    void Add_SKZ(const int skz_in);

    /** Enfernt eine Studienkennzahl (SKZ).
     * \param[in] skz_in  zu entfernende SKZ
     * \warning  Es wird nicht ueberprueft, ob diese SKZ mehrfach gespeichert ist.
     */
    void Del_SKZ(const int skz_in);

//! Asks for the number of enrolled studies
//!
//! @return number of enrolled studies
//!
    int num_Studies() const
    {
        return static_cast<int>(_skz.size());
    }

//! Gets the vector of all study IDs
//!
//! @return vector of all study IDs
//!
    const std::vector<int>& Get_SKZ() const {return _skz;}

    /** Ausgabeoperator fuer die Klasse.
     * \param[in] s  ein beliebiger Ausgabestrom
     * \param[in] rhs  die auszugebende Instanz
     */
    friend std::ostream& operator<<(std::ostream& s, const Student& rhs);

    /** Eingabeoperator fuer die Klasse.
     * \param[in] s  ein beliebiger Eingabestrom
     * \param[in] rhs  die einzugebende Instanz
     * \warning Hier wird nur eine SKZ eingegeben.
     */
    friend std::istream& operator>>(std::istream& s, Student& rhs);
protected:

private:
          std::string _name;    //!< Familienname der Studentin
    // const member ==> kein Zuweisungsoperator moeglich!
    const std::string _matr_nr; //!< Matrikelnummer
          std::vector<int> _skz;//!< neu: beliebig viele SKZs koennen gespeichert werden
};
