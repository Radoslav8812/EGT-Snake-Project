#include <iostream>
#include "Bike.h"
#include "Chain.h"
#include "Tyres.h"
#include <string>

using namespace std;

int main()
{
    Chain Ch(10, 15);
    Tyres Ty("Michelin Pilot",255,295);

    Bike Bk("specialized",22300,Ch,Ty);
    Bk.showInfo();
    return 0;
}
