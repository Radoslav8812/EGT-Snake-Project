#include <iostream>
#include <string>
#include <vector>
#include "Doctor.h"
#include "Patient.h"
using namespace std;

int main()
{
    Patient Pat2("Radoslav","Bogdanov",29,"male");
    Patient Pat3("Dimitrina","Valkova",42,"female");
    Patient Pat4("Blagovest","Kirilov",39,"male");

    Doctor Doc1("Snejana","Bogdanova","Dentist",Pat2);
    Doctor Doc2("Snejana","Bogdanova","Dentist",Pat4);
    Doctor Doc3("Snejana","Bogdanova","Dentist",Pat3);

    Doc1.addVector(Pat4);
    Doc1.addVector(Pat2);
    Doc1.addVector(Pat3);

    Doc1.print();

    return 0;
}
