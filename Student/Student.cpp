#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
    setName("");
    setSurname("");
    setGrade(0);
    setId(0);
}
Student:: Student(string name,string surname,int grade,int id)
{
    setName(name);
    setSurname(surname);
    setGrade(grade);
    setId(id);
}
Student::~Student()
{
    //dtor
}
void Student:: setName(const string& name)
{
    this -> name = name;
}
const string& Student:: getName()const
{
    return name;
}
void Student:: setSurname(const string& surname)
{
    this -> surname = surname;
}
const string& Student:: getSurname()const
{
    return surname;
}
void Student:: setGrade(int grade)
{
    this -> grade = grade;
}
int Student:: getGrade()
{
    return grade;
}
void Student:: setId(int id)
{
    this -> id = id;
}
int Student:: getId()
{
    return id;
}
void Student:: showInfo()
{
    cout << getName()<<" "<<getSurname()<<" "<<getGrade() <<" "<< getId() << endl;
}
