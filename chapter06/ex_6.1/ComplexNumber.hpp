//this command serves to define everything is inside if it's not been defined yet
#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>
using namespace std;

class ComplexNumber{
    private:
        double mRealPart;
        double mImagPart;
    public:
        ComplexNumber();
        ComplexNumber(double x, double y);
        double CalculateModulus() const;
        double CalculateArgument() const; 
        double GetRealPart() const;
        double GetImagPart() const;
        ComplexNumber CalculatePower(double n) const;
        ComplexNumber CalculateConjugate() const;
        ComplexNumber& operator=(const ComplexNumber& z);
        ComplexNumber operator-() const;
        ComplexNumber operator+(const ComplexNumber& z) const;
        ComplexNumber operator-(const ComplexNumber& z) const;
        friend std::ostream& operator<<(std::ostream& ouput, const ComplexNumber& z);
        friend double RealPart(const ComplexNumber z);
        friend double ImagPart(const ComplexNumber z);
};

#endif