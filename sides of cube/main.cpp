#include <iostream>

using namespace std;

double cube( const double side )
 {
return side * side * side;
 }

 int main()
 {
 double sideValue;

 cout << "Enter the side length of your cube: ";
 cin >> sideValue;

 cout << "Volume of cube with side " << sideValue << " is " << cube( sideValue ) << endl;

 return 0;
 }
