#ifndef FILE_EMPLOY2
#define FILE_EMPLOY2

#include <string>
using namespace std;		// std::string


//		Richtig einsteigen in C++: p. 158-160 : rein virtuelle methoden

class Employee
{
 public:
  Employee();
  explicit Employee(const string& name);
  const string& getname() const;
  void info() const;
  virtual void payment() const = 0;		//  N E W,  r e i n   virtuell
  virtual ~Employee()
  		{};
 private:
  string name;
};


/**
	WageEmployee   IS An   Employee and  IT HAS An additional wage per hour and
	working hours
*/

class WageEmployee : public Employee
{ public:
   WageEmployee();
   explicit WageEmployee(const string& nm);	// Konstructor
   void setWage(const float lohn);	// Uebergabe Stundenlohn
   void setHours(const float std);	// Uebergabe geleisteter Arbeitsstunden
   float getWage() const;		// Stundenlohn
   float getHours() const;		// geleistete Arbeitsstunden
   float computePay() const;		// Lohnberechnung
   void payment() const;		// Ausgabe Lohnberechnung  : N E W,  implizit virtuell
  private:
   float wage;				// Stundenlohn
   float hours;				// Arbeitszeit in Stunden
};


/**
	SalesPerson IS A   WageEmployee  and IT HAS An additional income from sales
*/

class SalesPerson : public WageEmployee
{
  public:
   SalesPerson();
   explicit SalesPerson(const string& nm);		// Konstructor
   void setComission(const float comm);	// Uebergabe Umsatzbeteiligung
   void setSales(const float sales);	// Uebergabe des Umsatzes
   float computePay() const;		// Lohnberechnung
   void payment() const;		// Ausgabe Lohnberechnung : N E W,  implizit virtuell
  private:
   float comission;		// Umsatzbeteiligung
   float SalesMade;		// Umsatz
};


/**
	Manager  IS An  Employee  and HAS A  weekly salery
*/

class Manager : public Employee
{
  public:
   Manager();
   explicit Manager(const string& nm);		// Konstructor
   void setSalary(const float salary);	// Uebergabe Wochengehalt
   float computePay() const;		// Lohnberechnung : N E W,  implizit virtuell
   void payment() const;
  private:
   float weeklySalary;			// Wochengehalt
};


#endif


