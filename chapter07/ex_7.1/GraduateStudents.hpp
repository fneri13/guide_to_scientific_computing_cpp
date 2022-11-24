/* Definition of a student class */
#ifndef GRADUATESTUDENTCLASS
#define GRADUATESTUDENTCLASS
#include <string>
#include "Students.hpp"

class GraduateStudent: public Student{
    public:
        std::string timeType;
        GraduateStudent();
        GraduateStudent(std::string x, double y, double z, std::string t);
        void PrintInfo();
};
#endif