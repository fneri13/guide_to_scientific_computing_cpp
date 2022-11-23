#include "ComplexNumber.hpp"
#include <cmath>

ComplexNumber::ComplexNumber(){
    mRealPart = 0.0;
    mImagPart = 0.0;
}

ComplexNumber::ComplexNumber(double x, double y){
    mRealPart = x;
    mImagPart = y;
}

double ComplexNumber::CalculateModulus() const {
    return sqrt(mRealPart*mRealPart + mImagPart*mImagPart);
}

double ComplexNumber::CalculateArgument() const {
    return atan2(mImagPart, mRealPart);
}

double ComplexNumber::GetRealPart() const {
    return mRealPart;
}

double RealPart(const ComplexNumber z) {
    return z.GetRealPart();
}

double ComplexNumber::GetImagPart() const {
    return mImagPart;
}

double ImagPart(const ComplexNumber z) {
    return z.GetImagPart();
}

ComplexNumber ComplexNumber::CalculatePower(double n) const {
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

ComplexNumber ComplexNumber::CalculateConjugate() const {
    ComplexNumber w;
    w.mRealPart = mRealPart;
    w.mImagPart = -mImagPart;
    return w;
}

//overloading the binary operator = for complex numbers 
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z){
    mRealPart = z.mRealPart;
    mImagPart = z.mImagPart;
    return *this; //the content of this memory address
}

//overloading the unary -z operator for complex numbers 
ComplexNumber ComplexNumber::operator-() const{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImagPart = -mImagPart;
    return w; 
}

//overloading the binary operator - for complex numbers 
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImagPart = mImagPart - z.mImagPart;
    return w; 
}

//overloading the binary operator + for complex numbers 
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImagPart = mImagPart + z.mImagPart;
    return w; 
}

//overloading the insertion operator << for complex numbers 
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z){
    if (z.mImagPart >=0.0){
        output << "("<< z.mRealPart << "+" <<z.mImagPart<<"i) ";
    }
    else{
        output << "("<< z.mRealPart << "-" <<-z.mImagPart<<"i) ";
    }
    return output;
}
