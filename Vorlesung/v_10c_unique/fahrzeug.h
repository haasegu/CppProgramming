#pragma once
#include <string>


class Fahrzeug
{
public:
    /** Default constructor
    *  \param[in]  kg dead weight in kg
    */
    explicit Fahrzeug(int kg);

    /** Default destructor */
    virtual ~Fahrzeug();

    /** Access dead weight
     * \return dead weight of vehicle in kg
     */
    int Get_kg() const
    {
        return _kg;
    }

    //! @brief Class name
    //! @return name of that class
    //!
    virtual std::string classname() const
    {
        return "Fahrzeug";
    }

    /** Fuel consumption
     * \return fuel consumption liter per 100 km
     */
    virtual float verbrauch() const = 0;         // besser: pure virtual ==> abstract class

private:
    const int _kg; //!< weight of vehicle in kg
};

//-----------------------------------------------------------------
class LKW: public Fahrzeug
{
public:
    /** Default constructor
        *  \param[in]   eigengewicht  dead weight in kg
        *  \param[in]   ladung      load weight in kg
        */
    LKW(int eigengewicht, int ladung);
    ~LKW() override;

    //! @brief Load weight
    //! @return Load weight in kg
    //!
    int Get_load() const
    {
        return _ladung;
    }

    //! @brief Class name
    //! @return name of that class
    //!
    std::string classname() const override
    {
        return "LKW";
    }

private:
    int _ladung;    //!< weight of load in kg
};

class PKW: public Fahrzeug
{
public:
    /** Default constructor
        *  \param[in]   eigengewicht  dead weight in kg
        *  \param[in]   passagiere    people in car
        */
    PKW(int eigengewicht, int passagiere);
    ~PKW() override;

    //! @brief Number of passengers
    //! @return Number of passengers
    //!
    int Get_pass() const
    {
        return _passagiere;
    }

    //! @brief Class name
    //! @return name of that class
    //!
    std::string classname() const override
    {
        return "PKW";
    }


private:
    int _passagiere;    //!< number of people in car
};
//-----------------------------------------------------------------

class MAN: public LKW
{
public:
    MAN(int eigengewicht, int ladung)
        : LKW(eigengewicht,ladung) { }
    ~MAN() override;

    //! @brief Class name
    //! @return name of that class
    //!
    std::string classname() const override
    {
        return "MAN";
    }

    //! @brief fuel consumption
    //! @return fuel consumption in liter
    //!
    float  verbrauch() const override
    {
        return 15.1f + Get_load()*0.3f/1000;
    }
};

//-----------------------------------------------------------------
class Raba: public LKW
{
public:
    Raba(int eigengewicht, int ladung)
        : LKW(eigengewicht,ladung) { }
    ~Raba() override;

    //! @brief Class name
    //! @return name of that class
    //!
    std::string classname() const override
    {
        return "Raba";
    }

    //! @brief fuel consumption
    //! @return fuel consumption in liter
    //!
    float  verbrauch() const override
    {
        return 12.1f + Get_load()*0.4f/1000;
    }

};

//-----------------------------------------------------------------
class Opel: public PKW
{
public:
    explicit Opel(int eigengewicht)
        : PKW(eigengewicht,4) { }
    ~Opel() override;

    //! @brief Class name
    //! @return name of that class
    //!
    std::string classname() const override
    {
        return "Opel";
    }

    //! @brief fuel consumption
    //! @return fuel consumption in liter
    //!
    float  verbrauch() const override
    {
        return 4.5f + Get_pass()*0.2f;
    }

};


//-----------------------------------------------------------------
class Smart: public PKW
{
public:
    explicit Smart(int eigengewicht)
        : PKW(eigengewicht,2) { }
    ~Smart() override;

    //! @brief Class name
    //! @return name of that class
    //!
    std::string classname() const override
    {
        return "Smart";
    }

    //! @brief fuel consumption
    //! @return fuel consumption in liter
    //!
    float  verbrauch() const override
    {
        return 3.1f + Get_pass()*0.4f;
    }

};


//-----------------------------------------------------------------

