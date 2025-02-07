#include "fahrzeug.h"

Fahrzeug::Fahrzeug(int kg)
: _kg(kg)
{
    //ctor
}

Fahrzeug::~Fahrzeug()
{
    //dtor
}


LKW::LKW(int eigengewicht, int ladung)
: Fahrzeug(eigengewicht), _ladung(ladung)
{
    //ctor
}

LKW::~LKW()
{
    //dtor
}

MAN::~MAN()
{
    //dtor
}

Raba::~Raba()
{
    //dtor
}


PKW::PKW(int eigengewicht, int passagiere)
: Fahrzeug(eigengewicht), _passagiere(passagiere)
{
    //ctor
}

PKW::~PKW()
{
    //dtor
}

Opel::~Opel()
{
    //dtor
}

Smart::~Smart()
{
    //dtor
}


