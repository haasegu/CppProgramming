#include <iostream>
#include <string>
#include "employ.hpp"

using namespace std;
//##################################################################################
//		class Employee
//##################################################################################

Employee::Employee()
: name()
{ }

Employee::Employee(const string& inname)
	: name(inname)
{
}

const string & Employee::getname() const
{
  return name;
}

void Employee::info()  const {  cout << "\n Name : " << name; }

void Employee::payment()  const { info(); cout << " keine Angaben\n"; }

//##################################################################################
//		class WageEmployee
//##################################################################################

WageEmployee::WageEmployee()
 	: Employee(), wage(0.0), hours(0.0)
{
}

WageEmployee::WageEmployee(const string& nm)
	: Employee(nm), wage(0.0), hours(0.0)
{
}


void WageEmployee::setWage(const float lohn)
{ wage = lohn; }

void WageEmployee::setHours(const float std)
{ hours = std; }

float WageEmployee::computePay() const
 { return wage*hours; }

float WageEmployee::getWage() const
 { return wage; }

float WageEmployee::getHours() const
 { return hours; }

void WageEmployee::payment() const
 {
   info();
   cout << "\n Lohn : " << hours << " Std. * " << wage << " DM  =  ";
   cout << computePay() << " DM\n";
 }


//##################################################################################
//		class SalesPerson
//##################################################################################

SalesPerson::SalesPerson()
	: WageEmployee(), comission(0.0), SalesMade(0.0)
{
}

SalesPerson::SalesPerson(const string& nm)
	: WageEmployee(nm), comission(0.0), SalesMade(0.0)
{
}

void SalesPerson::setComission(const float comm)
{ comission = comm; }

void SalesPerson::setSales(const float sales)
{ SalesMade = sales; }

float SalesPerson::computePay() const
// { return computePay() + comission*SalesMade; }
{ return WageEmployee::computePay() + comission*SalesMade; }

void SalesPerson::payment() const
 {
   info();
   cout << "\n Lohn : " << getHours() << " Std. * " << getWage() << " DM  + " ;
   cout << 100*comission << "% * " << SalesMade << " DM  =  ";
   cout << computePay() << " DM\n";
 }


//##################################################################################
//		class Manager
//##################################################################################

Manager::Manager()
	: Employee(), weeklySalary(0.0)
{
}

Manager::Manager(const string& nm)
	: Employee(nm), weeklySalary(0.0)
{
}


void Manager::setSalary(const float salary)
{ weeklySalary = salary; }

float Manager::computePay() const
{ return weeklySalary; }

void Manager::payment() const
 {
   info();
   cout << "\n Gehalt : " << computePay() << " DM pro Woche\n";
 }



