#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#include <string>
using namespace std;

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
        int Get_kg() const { return _kg; }

        virtual string classname() const {return "Fahrzeug";}

        /** Fuel consumption
         * \return fuel consumption liter per 100 km
         */
        virtual float verbrauch() const {return 0;}         // virtual ==> abstract virtual
                                                            // besser mit " = 0 " als  rein virtuell

    protected:
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
        virtual ~LKW();

        int Get_load() const { return _ladung; }
        string classname() const {return "LKW";}

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
        virtual ~PKW();

        int Get_pass() const { return _passagiere; }
        string classname() const {return "PKW";}


private:
    int _passagiere;    //!< number of people in car
};
//-----------------------------------------------------------------

class MAN: public LKW
{
public:
        MAN(int eigengewicht, int ladung)
              : LKW(eigengewicht,ladung) { }
        virtual ~MAN() {}

        string classname() const {return "MAN";}
        float  verbrauch() const {return 15.1f + Get_load()*0.3f/1000;}
};

//-----------------------------------------------------------------
class Raba: public LKW
{
public:
        Raba(int eigengewicht, int ladung)
              : LKW(eigengewicht,ladung) { }
        virtual ~Raba() {}

        string classname() const {return "Raba";}
        float  verbrauch() const {return 12.1f + Get_load()*0.4f/1000;}

};

//-----------------------------------------------------------------
class Opel: public PKW
{
public:
        explicit Opel(int eigengewicht)
              : PKW(eigengewicht,4) { }
        virtual ~Opel() {}

        string classname() const {return "Opel";}
        float  verbrauch() const {return 4.5f + Get_pass()*0.2f;}

};


//-----------------------------------------------------------------
class Smart: public PKW
{
public:
        explicit Smart(int eigengewicht)
              : PKW(eigengewicht,2) { }
        virtual ~Smart() {}

        string classname() const {return "Smart";}
        float  verbrauch() const {return 3.1f + Get_pass()*0.4f;}

};


//-----------------------------------------------------------------




#endif // FAHRZEUG_H