//	Ex540.cpp

//	Sec. 5.4 of lecture
//	enum

#include <iostream>
using namespace std;

enum tag {                              // day-of-the-week as enum type
    montag, dienstag, mittwoch, donnerstag, freitag, samstag, sonntag
};

int main()
{
    tag wochentag;                      // Variable of enum type

    wochentag = montag;                 // Data init
    wochentag = tag(wochentag + 1);     // next day; requires casting

    if ( wochentag == dienstag ) {
        cout << "Schlechte Laune " << wochentag << endl;
    }

    for (int i = montag; i <= sonntag; i = i + 1) {
        cout << "Tag " << i << endl;
    }

//		Klappt nicht
//  for (wochentag=montag; wochentag<=sonntag; wochentag = wochentag+1)
//    {
//      cout << "Tag " << wochentag << endl;
//    }

//		Klappt auch (falsch in [Capper,"Introducing C++",p.75])
//			    (richtig in http://courses.cs.vt.edu/~cs1044/spring01/cstruble/notes/15.types.pdf)
    for (wochentag = montag; wochentag <= sonntag; wochentag = tag(wochentag + 1)) {
        cout << "Tag " << wochentag << endl;
    }

    return 0;
}









