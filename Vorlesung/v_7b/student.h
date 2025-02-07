#pragma once
#include <algorithm>  // find
#include <iostream>   // ostream
#include <string>
#include <vector>
//using namespace std;

/**  Class student that contains the family name, matricel number and the enrolled studies.
*/
class Student
{
public:
    /** \brief Default constructor
     */
    Student();

    /** \brief Parameter constructor
     *
     * \param[in]   fname       family name
     * \param[in]   matrikel    matricel number
     * \param[in]   studium     one study
     *
     */
    Student(const std::string& fname, const std::string& matrikel, const int studium);

    /** \brief Parameter constructor
     *
     * \param[in]   fname       family name
     * \param[in]   matrikel    matricel number
     * \param[in]   studium     vector of studies
     *
     */
    Student(const std::string& fname, const std::string& matrikel, const std::vector<int>& studium);  //  new

    // automatic generation of copy constructor and assignment operator by the compiler
    // in C++11: the Assignment operator (and any other method) can be explicitely deleted via:
    // Student& operator=(const Student& other) = delete;
    Student(const Student &orig) = default;

    Student& operator=(const Student &rhs) = default;


    /** Default destructor */
    // virtual
    ~Student() {}


    /**
     * \return name of student
     */
    std::string Getname() const
    {
        return _name;
    }
    /** Assigns a new name to the student
     * \param[in] val New name to set
     */

    void Setname(const std::string& val);
    /** Access matr_nr
     * \return The current value of matr_nr
     */

    /**
     * \return matricel number
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

    /** Accesses the vector of studies
      * \return vector of studies
      */
    const std::vector<int>& Get_SKZ() const
    {
        return _skz;
    }

    /** Determines number of studies for this student
     * \return number of studies
     */
    int Num_SKZ() const
    {
        return static_cast<int>(_skz.size());
    }

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

    /** \brief Compares two students wrt. the lexicographical ordering of names
     *
     * \param[in] rhs   student to compare with
     * \return name(*this) < name(rhs)
     *
     */
    bool operator<(const Student& rhs) const
    {
        return _name < rhs._name;
    }

    /** \brief Checks whether a student is enrolled in study @p cSKZ.
         *
         * \param[in] cSKZ   study under search
         * \return found? (true/false)
         *
         */
    bool Enrolled4Study(const int cSKZ) const
    {
        return _skz.end() != find(_skz.begin(), _skz.end(), cSKZ);  // find uses  operator==(int,int)
    }

protected:

private:
    std::string _name;    //!< Familienname der Studentin
    std::string _matr_nr; //!< Matrikelnummer (const had to be removed for sorting with vector<>, not needed for list<>)
    std::vector<int> _skz;//!< beliebig viele SKZs koennen gespeichert werden
};
