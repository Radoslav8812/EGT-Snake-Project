#ifndef EYES_H
#define EYES_H
#include <string>
using namespace std;
class Eyes
{
public:
    Eyes(string);
    void setColor(string color);
    string getColor();

    void print();
private:
    string color;

};

#endif // EYES_H
