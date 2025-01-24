//		employ.hpp
#ifndef FILE_EMPLOY
#define FILE_EMPLOY

#include <string>
using namespace std;		// std::string


//		Richtig einsteigen in C++: p. 145-153

/**
  Employee is a simple class that contains only the name of the employee.
*/

class Employee
{
 public:
  Employee();
  explicit Employee(const string& name);
  const string& getname() const;
  void info() const;				// Namen ausgeben
  virtual void payment() const;	//  N E W,  virtuell
  virtual ~Employee()		//  N E W,  jetzt notwendig
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
   float getWage() const;			// Stundenlohn
   float getHours() const;			// geleistete Arbeitsstunden
   float computePay() const;			// Lohnberechnung
   void payment() const;			// Ausgabe Lohnberechnung  : N E W,  implizit virtuell
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
   float computePay() const;			// Lohnberechnung
   void payment() const;			// Ausgabe Lohnberechnung : N E W,  implizit virtuell
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
   float computePay() const;			// Lohnberechnung : N E W,  implizit virtuell
   void payment() const;
  private:
   float weeklySalary;			// Wochengehalt
};

#endif


