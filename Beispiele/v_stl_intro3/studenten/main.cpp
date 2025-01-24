#include <iostream>
#include "studenten.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Studenten arni("Arnold","Schwarzenegger",1378965453,851);
    cout << "arni: " << arni << endl;

    Studenten robbi;
    robbi = arni;
    cout << "robbi: " << robbi << endl;

    Studenten craig(robbi);
    cout << "craig: " << craig << endl;

    return 0;
}
