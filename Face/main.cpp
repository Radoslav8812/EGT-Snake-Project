#include <iostream>
#include "Eyes.h"
#include "Nose.h"
#include "Face.h"
using namespace std;

int main()
{
    cout << " the face contain : eyes , nose and color of skin !"<< endl;
    Eyes e1("blue");
    Nose n1("small", 2);
    Face face1("white",n1,e1);

    face1.print();




    return 0;
}
