#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Patient.h"

using namespace std;

class Doctor
{
public:
    Doctor(string, string, string, Patient&);

        const string& getFirstName() const;
            void setFirstName(const string& firstName);
        const string& getLastName() const;
            void setLastName(const string& lastName);
        const string& getSpeciality() const;
            void setSpeciality(const string& speciality);
        Patient& getPat();
            void setPat(Patient&);

        void print();

        vector<Patient>vecPatient;
        void addVector(Patient&);

private:
    string firstName;
    string lastName;
    string speciality;
    Patient Pat;
};

#endif // DOCTOR_H
