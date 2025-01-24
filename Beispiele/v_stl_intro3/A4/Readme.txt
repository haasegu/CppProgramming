Klassenhierarchien
==================

nach "Richtig einsteigen in C++": Kap.7

employ.*	: virtual [p.158-169]
employ2.*	: pure virtual method [p.158-160]


a4_1.cpp		: virtual methods [p.158-160]
a4_2.cpp		: pure virtual method[p.158-160]


Demonstration, da� mit virtuellen Funktionen ein �bersetzter
Programmteil nachtr�glich ver�ndert werden kann.
============================================================

von a4_2.cpp eine Funktion PrintListe separieren
--> a4_3.cpp liste.cpp liste.hpp
--> a4_3.cpp liste.cpp kompilieren und mit employ2.o linken

Neue Klasse BoxPromoter von Manager ableiten
--> bestech.hpp bestech.cpp
--> (ge�ndertes) a4_3.cpp bestech.cpp kompilieren und mit employ2.o liste.o linken
!! PrintListe ruft die Methode payment() von BoxPromoter auf, obwohl
   diese Methode zur Kompilierungszeit unbekannt war !!

ACHTUNG: Sobald liste.cpp benutzt wird sieht man, dass die 
	Methoden in employ.hpp/cc nicht sauber deklariert/definiert wurden.
	Viele Methoden ben�tigen das const-Attribut.
 
