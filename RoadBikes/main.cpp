#include <iostream>
#include "RoadBikes.h"
#include <string>
using namespace std;

int main()
{
    RoadBikes bike1("Drag","Master",950,3,10.4);
    bike1.print();
    RoadBikes bike2("Specialized","Tarmac",4000,5,7.2);
    bike2.print();
    RoadBikes bike3("Trek","Madone",4500,2,7.78);
    bike3.print();
}
