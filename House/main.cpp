#include <iostream>
#include <string>
#include "Doors.h"
#include "Windows.h"
#include "House.h"

using namespace std;

int main()
{
    Doors Dr("brown",250);
    Windows Wd("White", 150);

    House Hs1("sofiaCity",52.200,Dr,Wd);
    Hs1.print();

    return 0;
}
