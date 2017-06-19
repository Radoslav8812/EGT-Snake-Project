#include <iostream>
#include <iomanip>
#include <math.h>
/// write a function to calculate distance between two points(x1,y1) and (x2,y2).values must be ot type " double " !
using namespace std;

double distance(double x1,double y1,double x2,double y2);

int main()
{
    double x1,x2,y1,y2;

    cout << " enter value for x1 :" << endl;
    cin >> x1;
    cout << " enter value for x2 :" << endl;
    cin >> x2;
    cout << " enter value for y1 :" << endl;
    cin >> y1;
    cout << " enter value for y2 :" << endl;
    cin >> y2;

    cout << " the distance between these two points is : " << distance(x1,y1,x2,y2) << endl;

    return 0;
}
double distance(double x1,double y1,double x2,double y2)
{
    double distance;
    double distance_x = (x2 - x1);
    double distance_y = (y2 - y1);

    distance = sqrt((distance_x * distance_x)+(distance_y * distance_y));
    return distance;
}
