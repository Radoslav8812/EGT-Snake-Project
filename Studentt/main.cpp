///Define class Student that holds information about
///students: full name, course, specialty, university,
///email, phone.

#include <iostream>
#include "Studentt.h"
#include <string>

using namespace std;

int main()
{
    Studentt std1("Radoslav","Bogdanov","fourth","Dentistry","MK Filaretova","radoslav8812",878);
    std1.print();

    return 0;
}
