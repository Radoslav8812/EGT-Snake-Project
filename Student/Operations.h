#ifndef OPERATIONS_H
#define OPERATIONS_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Student.h"
#include "pugixml.hpp"

using namespace std;

class Operations
{
public:
    Operations();
    virtual ~Operations();

    vector<Student> loadFromXml(const string& file);

    void searchByName(string searchByName);
    void searchByGrade(int searchByGrade);
    void searchById(int searchById);



private:
    vector <Student> vec;
};

#endif // OPERATIONS_H
