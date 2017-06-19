#include <iostream>
#include <string>
#include "Motocycle.h"
#include "Bicycle.h"
using namespace std;

int main()
{
    Bicycle Bc("Trek","Schvable");
    Motocycle Mtr1("CBR","ToYo","Honda");

    Bc.print();
    Mtr1.print();

    return 0;
}
