#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "pugixml.hpp"
#include "Operations.h"

using namespace std;

int main()
{
/*
    vector<Student>myVec;

    Student st1("iliq","iliev",6);
    Student st2("radi","bogdanov",5);
    Student st3("dimi","vulkova",6);

    myVec.push_back(st1);
    myVec.push_back(st2);
    myVec.push_back(st3);

    ofstream write ("students.txt",ios::out);
            if (write)
            {
                cout << " the file is creaded";
            }
            else
            {
                cout << " wrong input ";
            }
        write << "name:" << "surname:" << "grades:" <<endl;
        write << "________________" << endl;
    for ( int i = 0; i < myVec.size(); i++)
    {
        write <<myVec[i].getName()<<" "<<myVec[i].getSurname()<<" "<<myVec[i].getGrade() << endl;
    }
    double count = 0;
    double avarage;
        for (int i = 0; i < myVec.size(); i++)
        {
            count = count + myVec.at(i).getGrade();
        }
    avarage = count / myVec.size();

    write <<"Avarage sum from these grades is: " << avarage << endl;

    cout << avarage << endl;
*/



    Operations op1;

   vector<Student> stds = op1.loadFromXml("students.xml");

    for(int i = 0; i < (int)stds.size(); i++){
        stds[i].showInfo();
    }
   // op1.searchByName("Radi");

   // op1.searchByGrade(5);

   // op1.searchById(17);

return 0;
}

