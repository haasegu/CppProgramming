#include <iostream>
#include "bestech.hpp"


BoxPromoter::BoxPromoter() : Manager(), bestechung_(0.0)
{
}

BoxPromoter::BoxPromoter(const string& nm) : Manager(nm), bestechung_(0.0)
{
}

//	Manager :: setSalary von
//void BoxPromoter::setSalary(const float salary)
//{ weeklySalary = salary; }

void BoxPromoter::setBestechung(const float bestechung)
{ bestechung_ = bestechung; }


float BoxPromoter::computePay() const
{ return Manager::computePay() + bestechung_; }

void BoxPromoter::payment() const
 {
   info();
   std::cout << "\n Gehalt : " << computePay() << " DM pro Woche\n";
 }


 
