#include "Studentt.h"
#include <iostream>
#include <string>

using namespace std;

Studentt::Studentt(string firstName,string lastName,string course,string speciality,string universty,string mail,int phone)
{
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> course = course;
    this -> speciality = speciality;
    this -> universty = universty;
    this -> mail = mail;
    this -> phone = phone;
}
void Studentt::print(){

    cout << getFirstName() <<" " <<getLastName() <<" "<<getCourse() <<
    " " << getSpeciality() <<" " <<getUniversity() <<" "<< getMail()<<" "<< getPhone() << endl;
}

void Studentt::setFirstName(string firstName)
{
    this -> firstName = firstName;
}
void Studentt::setLastName(string lastName)
{
    this -> lastName = lastName;
}
void Studentt::setCourse(string course)
{
    this -> course = course;
}
void Studentt::setSpeciality(string speciality)
{
    this -> speciality = speciality;
}
void Studentt::setUniversity(string universty)
{
    this -> universty = universty;
}
void Studentt::setMail(string mail)
{
    this -> mail = mail;
}
void Studentt::setPhone(int phone)
{
    this -> phone = phone;
}


string Studentt:: getFirstName()
{
    return this -> firstName;
}
string Studentt::getLastName()
{
    return this -> lastName;
}
string Studentt::getCourse()
{
    return this -> course;
}
string Studentt::getSpeciality()
{
    return this -> speciality;
}
string Studentt::getUniversity()
{
    return this -> universty;
}
string Studentt::getMail()
{
    return this -> mail;
}
int Studentt::getPhone()
{
    return this -> phone;
}








