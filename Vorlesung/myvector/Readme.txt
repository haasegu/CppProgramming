Exeption-Handling am Bsp. der Klasse MyVector


myvector.hpp
myvector.cpp	- einfache Vektorklasse mit mit
        * optionalem Index-Check beim operator[]   (-DNEBUG um diesen Check zu deaktivieren)
        * Demonstration einer inkorrekten Klasse mit Pointer (-DWRONG_CODE zum Aktivieren)

Variante a)	mit new(nothrow) und anschlieﬂendem assert(), da weiﬂ man
			wenigstens, wo der Speicher nicht mehr ausreicht.

         b)	mit execption handling [Prinz/Prinz p.151]

main.cpp


myexeptions.*	- Error-handling

provocate.*	- Demofkt., in welcher ein Error provoziert wird

 
