/* Definition of a student class */
#ifndef STUDENTCLASS
#define STUDENTCLASS
#include <string>

class Student{
    protected:
        double libraryFines; 
    public:
        std::string name; //in time for example
        double tuitionFees; 
    public:
        Student();
        Student(std::string x, double y, double z);
        double MoneyOwed();  
        void PrintInfo();
        double GetLibraryFines();
};
#endif