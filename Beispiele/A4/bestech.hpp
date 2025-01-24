//			bestech.hpp
// Demonstration, damit bei virtuellen Funktionen ein uebersetzter
// Programmteil nachtraelich veraedert werden kann.

#include "employ2.hpp"

class BoxPromoter : public Manager
{
  public:
   BoxPromoter();
   explicit BoxPromoter(const string& nm);			// Konstructor
   //void setSalary(const float salary);	// --> Manager::setSalery
   float computePay() const;			// virtuell
   void payment() const;			//  (auch virtual loesbar)
   void setBestechung(const float bestechung);	// N E W
  private:
   float bestechung_;				// Bestechungsgeld
};

