#include <string>
#include "Students.hpp"
#include "GraduateStudents.hpp"
#include <iostream>
using namespace std;


int main(){
    cout<<"-----------------------TEST CASE------------------------"<<endl;
    Student case1;
    Student case2("Marco Berratti", 120.0, 200.0);
    GraduateStudent case3;
    GraduateStudent case4("Sofia la Monaca", 100, 231.0, "part time");
    case1.PrintInfo();
    case2.PrintInfo();
    case3.PrintInfo();
    case4.PrintInfo();
    cout<<"--------------------------------------------------------"<<endl;
    return 0;
}