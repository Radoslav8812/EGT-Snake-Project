#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student
{
public:
    Student();
    virtual ~Student();
    Student(string name,string surname,int grade,int id);

        void setName(const string& name);
            const string & getName()const;
        void setSurname(const string& surname);
            const string& getSurname()const;
        void setGrade(int grade);
            int getGrade();
        void setId(int id);
            int getId();

        void showInfo();

protected:

private:
    string name;
    string surname;
    int grade;
    int id;

};

#endif // STUDENT_H
