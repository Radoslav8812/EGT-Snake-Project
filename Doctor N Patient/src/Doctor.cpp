#include "Doctor.h"
#include "Patient.h"
#include <iostream>
#include <string>

using namespace std;

Doctor::Doctor(string firstName, string lastName, string speciality, Patient& Pat) : Pat(Pat)
{
    setFirstName(firstName);
    setLastName(lastName);
    setSpeciality(speciality);
    addVector(Pat);
}
///
void Doctor:: addVector(Patient& Pat)
{
    vecPatient.push_back(Pat);
}
void Doctor:: print()
{
    cout <<"Doctor : "<< endl;
    cout << getFirstName() <<" "<< getLastName()<<" "<< getSpeciality() <<" "<< endl;

    cout <<"Patient : "<< endl;
    for (int i = 0; i < vecPatient.size(); i++)
    {
        vecPatient[i].print();
    }
}
///
const string & Doctor:: getFirstName() const
{
    return firstName;
}
void Doctor:: setFirstName(const string& firstName)
{
    this -> firstName = firstName;
}
const string& Doctor:: getLastName() const
{
    return lastName;
}
void Doctor:: setLastName(const string& lastName)
{
    this -> lastName = lastName;
}
const string& Doctor:: getSpeciality() const
{
    return speciality;
}
void Doctor:: setSpeciality(const string& speciality)
{
    this -> speciality = speciality;
}
Patient& Doctor:: getPat()
{
    return this -> Pat;
}
void Doctor:: setPat(Patient& Pat)
{
    this -> Pat = Pat;
}
