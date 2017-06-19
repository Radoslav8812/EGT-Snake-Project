#include "Patient.h"

Patient::Patient(string firstNamePat, string lastNamePat, int age, string gender)
{
    setFirstNamePat(firstNamePat);
    setLastNamePat(lastNamePat);
    setAge(age);
    setGender(gender);
}
///
void Patient:: print()
{
    cout << getFirstNamePat() <<" "<< getLastNamePat() <<" "<< getAge() <<" "<< getGender() << endl;
}
///
const string& Patient :: getFirstNamePat() const
{
    return firstNamePat;
}
void Patient:: setFirstNamePat(const string& firstNamePat)
{
    this -> firstNamePat = firstNamePat;
}
const string& Patient:: getLastNamePat() const
{
    return lastNamePat;
}
void Patient:: setLastNamePat(const string& lastNamePat)
{
    this -> lastNamePat = lastNamePat;
}
int Patient:: getAge() const
{
    return age;
}
void Patient:: setAge(int age)
{
    this -> age = age;
}
const string& Patient:: getGender() const
{
    return gender;
}
void Patient:: setGender(const string& gender)
{
    this -> gender = gender;
}
