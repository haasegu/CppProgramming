//	Ex643-warning.cpp

//	Sec. 6.4 of lecture
//		Dynamic arrays in structures

//	Demonstration of   w r o n g   code 
//		wrt. copying a structure with pointers

#include <iostream>
#include <iomanip>			// setw
#include <cstring>			// strcpy, strlen
using namespace std;

//		Let's use a tool to detect memory bugs
//		~/progs/lib/rmalloc
//		g++  -Wno-deprecated Ex643-warning-test.cpp rmalloc.o
#define MALLOC_DEBUG
#include "rmalloc.h"

struct Student2
  {
    long long int matrikel;
              int skz;
              char *pname, *pvorname;	// Pointers in structure
  };

int main()
{
 Student2 arni, robbi;
 char     tmp[20];			// temp. input string

//	---------------------------------------------------------------
//		Input pvorname

 cout << endl << " Vorname : ";
 
//		setw guarantes that not more than 20 characters are read
//			see Schader/Kuhlin, p.96

 cin  >> setw(sizeof(tmp)) >> tmp;
 
//		Allocate memory for arni.pvorname

 arni.pvorname = new char[strlen(tmp)+1];// Don't forget "+1
 strcpy(arni.pvorname,tmp);		// and copy input on it

//	---------------------------------------------------------------
//		Input pname

 cout << endl << " Familienname : ";
 cin  >> setw(sizeof(tmp)) >> tmp;

//		Allocate memory for arni.pname

 arni.pname = new char[strlen(tmp)+1];	// Don't forget "+1"
 strcpy(arni.pname,tmp);		// and copy input on it

//	---------------------------------------------------------------
//		Input skz

 cout << endl << " Studentenkennzahl : ";
 cin >> arni.skz;

//	---------------------------------------------------------------
//		Input matrikel

 cout << endl << " Matrikelnummer    : ";
 cin >> arni.matrikel;

//	---------------------------------------------------------------
//	rough and  w r o n g  copying

 robbi = arni;	// copies int, long long int, int*
 		// but pvorname, pname point on dynamical data are posessed by arni

//	---------------------------------------------------------------
//				output robbi

 cout << endl << "-------- This output is still correct -----------" << endl;
 cout << robbi.pvorname << " "   << robbi.pname    << ", SKZ: ";
 cout << robbi.skz      << "   " << robbi.matrikel << endl << endl; 

//	---------------------------------------------------------------
//		Now, we deallocate dynamical data in arni

 delete [] arni.pvorname;
 delete [] arni.pname;
 
//	---------------------------------------------------------------
//				output robbi

 cout << endl << "-------- Even this output may be correct -----------" << endl;
 cout << robbi.pvorname << " "   << robbi.pname    << ", SKZ: ";
 cout << robbi.skz      << "   " << robbi.matrikel << endl << endl; 

//	---------------------------------------------------------------
//				Let us allocate some tiny dynamical array
 char *tiny;
 tiny = new char [5];
 strcpy(tiny,"tiny");

//	---------------------------------------------------------------
//				output robbi
//	Suddenly, robbi.pname == "tiny"

 cout << endl << "-------- Hey, what happend to my output!! -----------" << endl;
 cout << robbi.pvorname << " "   << robbi.pname    << ", SKZ: ";
 cout << robbi.skz      << "   " << robbi.matrikel << endl << endl; 

//	---------------------------------------------------------------
//		Now, we deallocate dynamical data in robbi

 delete [] robbi.pvorname;
 delete [] robbi.pname;
 
}
 
 
 
 
 
 
 
 
 
