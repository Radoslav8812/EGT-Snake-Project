#include "Operations.h"
#include "pugixml.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;

Operations::Operations()
{
    //ctor
}

Operations::~Operations()
{
    //dtor
}
vector<Student> Operations:: loadFromXml(const string& file)
{

    vector<Student> res;
    pugi:: xml_document doc;

    if (!doc.load_file(file.c_str()))
    {
        cerr << " can't open file !" << endl;
        exit(1);
    }
    else
    {
        cout << " file is rdy to be read !" << endl;
    }

    //Student obj1;

    pugi:: xml_node school = doc.first_child();
    for ( pugi::xml_node student = school.first_child(); student; student = student.next_sibling())
    {


        string name = student.child("name").text().as_string();
        pugi::xml_attribute idAttr = student.child("name").first_attribute(); int id = idAttr.as_int();


        string surname = student.child("surname").text().as_string();
        int grade = student.child("grade").text().as_int();

        Student obj1(name, surname, grade, id);
     //   obj1.showInfo();
        vec.push_back(obj1);
        res.push_back(obj1);
    }

    if (vec.empty())
    {
        cerr << " empty " << endl;
    }
    else
    {
        cout << " rdy " << endl;
    }
    return res;
}

void Operations:: searchByName(string searchByName)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (searchByName == vec[i].getName())
        {
            vec[i].showInfo();
        }
    }
}

void Operations:: searchByGrade(int searchByGrade)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (searchByGrade == vec[i].getGrade())
        {
            vec[i].showInfo();
        }
    }
}

void Operations:: searchById(int searchById)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (searchById == vec[i].getId())
        {
            vec[i].showInfo();
        }
    }
}




