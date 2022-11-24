#include <iostream>
#include <string>
#include "Students.hpp"
using namespace std;

Student::Student(){
    name = "N/A";
    libraryFines = 0.0;
    tuitionFees = 0.0;
}

Student::Student(string x, double y, double z){
    assert(y>=0);
    name = x;
    libraryFines = y;
    tuitionFees = z;
}

double Student::MoneyOwed(){
    return libraryFines + tuitionFees;
}

void Student::PrintInfo(){
    cout<<"The student name is "<<name<<". The library fines are "<<libraryFines<<
        " and the tuition fee is "<<tuitionFees<<endl;
}

double Student::GetLibraryFines(){
    return libraryFines;
}
