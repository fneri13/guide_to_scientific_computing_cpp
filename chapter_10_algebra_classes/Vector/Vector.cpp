#include <iostream>
using namespace std;
#include "Vector.hpp"
#include <cmath>
#include <cassert>

//constructor of a vector, copying info from the other one. notice that the
//the default constructor would not work properly, because it wouldn't how much memory
//it needs to allocate dynamically with the new stament. We therefore avoid default 
//constructors that take no argument
Vector::Vector(const Vector& otherVector){
    mSize = otherVector.GetSize();
    mData = new double [mSize]; //allocate new memory
    for(int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i]; //attributes can access private members
    }
}

//constructor for a vector of a given size, elements initialized at zero. default constructor
//is therefore overridden now, to prevent memory leakage
Vector::Vector(int size){
    mSize = size;
    mData = new double [mSize]; //new memory allocated
    for(int i=0; i<mSize; i++){
        mData[i] = 0.0; //elements initialized to zero
    }
}

//destructor to free memory that had been allocated before. Otherwise memory leak
Vector::~Vector(){
    delete[] mData;
}

//method to get the size from a vector
int Vector::GetSize() const{
    return mSize;
}

//overloading of the square bracket operator
//returning by reference gives the possibility to modify it!
//it gives the possibility to be put at the left of the = assignment
double& Vector::operator[](int i){
    assert(i>-1 && i<mSize); //check that index is in the exact range
    return mData[i];
}

//read-only variant with zero based indexing
//this is read-only because it is returned by value only
double Vector::Read(int i) const{
    assert(i>-1 && i<mSize);
    return mData[i];
}

//overloading of the round brackets in matlab style. 1 based indexing (useless usually)
double& Vector::operator()(int i){
    assert(i>0 && i<mSize+1);
    return mData[i-1];
}

//overloading of the assignment operator
Vector& Vector::operator=(const Vector& otherVector){
    assert(mSize==otherVector.mSize); //check of the correct size of two vectors
    for(int i=0; i<mSize; i++){
        mData[i] = otherVector.mData[i];
    }
    return *this; //return the vector itself (it modifies the vector elements at the left side of =)
}

Vector Vector::operator+() const{
    Vector v(mSize);
    for(int i=0; i<mSize; i++){
        v[i] = mData[i];
    }
    return v; //return the same vector
}

Vector Vector::operator-() const{
    Vector v(mSize);
    for(int i=0; i<mSize; i++){
        v[i] = -mData[i];
    }
    return v; //return the opposite vector
}

Vector Vector::operator+(const Vector& v1) const{
    assert(mSize==v1.mSize);
    Vector v(mSize);
    for(int i=0; i<mSize; i++){
        v[i] = mData[i]+v1.mData[i];
    }
    return v;
}

Vector Vector::operator-(const Vector& v1) const{
    assert(mSize==v1.mSize);
    Vector v(mSize);
    for(int i=0; i<mSize; i++){
        v[i] = mData[i]-v1.mData[i];
    }
    return v;
}

Vector Vector::operator*(double a) const{
    Vector v(mSize);
    for(int i=0; i<mSize; i++){
        v[i] = mData[i]*a;
    }
    return v;
}

//calculate the p-norm of a vector. The default value is p=2, which is the euclidean norm
double Vector::CalculateNorm(int p) const{
    double norm_val, sum = 0.0;
    for (int i=0; i<mSize; i++){
        sum += pow(fabs(mData[i]),p);
    }
    norm_val = pow(sum,1.0/((double)(p)));
    return norm_val;
}

//matlab style friend function to get the size of a vector
int length(const Vector& v){
    return v.mSize;
}

void Vector::PrintVector(){
    for (int i=0; i<mSize; i++){
        cout << "[";
        cout << mData[i];
        cout << "]" << endl;
    }
}
