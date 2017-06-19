#ifndef STUDENTT_H
#define STUDENTT_H
#include <iostream>
#include <string>
using namespace std;

class Studentt
{
public:

    Studentt(string,string,string,string,string,string,int);

        void setFirstName(string firstName);
        string getFirstName();
        void setLastName(string lastName);
        string getLastName();
        void setCourse(string course);
        string getCourse();
        void setSpeciality(string speciality);
        string getSpeciality();
        void setUniversity(string universty);
        string getUniversity();
        void setMail(string mail);
        string getMail();
        void setPhone(int phone);
        int getPhone();

        void print();

private:
    string firstName;
    string lastName;
    string course;
    string speciality;
    string universty;
    string mail;
    int phone;

};

#endif // STUDENTT_H
