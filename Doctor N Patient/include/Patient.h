#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>

using namespace std;

class Patient
{
public:
    Patient(string, string, int, string);

    const string& getFirstNamePat() const;
        void setFirstNamePat(const string& firstNamePat);
    const string& getLastNamePat() const;
        void setLastNamePat(const string& lastNamePat);
    int getAge() const;
        void setAge(int age);
    const string& getGender() const;
        void setGender(const string& gender);

        void print();

private:
    string firstNamePat;
    string lastNamePat;
    int age;
    string gender;
};

#endif // PATIENT_H
