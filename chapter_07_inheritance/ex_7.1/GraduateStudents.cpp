#include <iostream>
#include <string>
#include "GraduateStudents.hpp"
using namespace std;

GraduateStudent::GraduateStudent(){
    name = "N/A";
    libraryFines = 0.0;
    tuitionFees = 0.0;
    timeType = "N/A";
}

GraduateStudent::GraduateStudent(string x, double y, double z, string t){
    assert(y>=0);
    name = x;
    libraryFines = y;
    assert(t=="full time" || t=="part time");
    timeType = t;
    tuitionFees = z;
}

void GraduateStudent::PrintInfo(){
    cout<<"The graduate student name is "<<name<<", and he/she works "<<timeType<<". The library fines are "<<libraryFines<<
        " and the tuition fee is "<<tuitionFees<<endl;
}
