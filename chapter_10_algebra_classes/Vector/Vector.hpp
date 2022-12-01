#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <iostream>
using namespace std;

/*
* Class of vectors. data are stores in the pointer *mData, and the size in the int mSize
*/
class Vector{
    private:
        double* mData; //data stored in the vector
        int mSize; //size of vector
    public:
        Vector(const Vector& otherVector); //constructor by copy
        Vector(int size); //constructor by size
        ~Vector(); //default destructor
        int GetSize() const; //get size of the vector
        double& operator[](int i); //zero based indexing. return a reference 
        double Read(int i) const; //read only zero-based indexing (since it returns by copy, not reference)
        double& operator()(int i); //one based indexing, return a reference
        Vector& operator=(const Vector& otherVector); //assignment operator
        Vector operator+() const; //unary, needed for binary operations
        Vector operator-() const; //unary, needed for binary operations
        Vector operator+(const Vector& v1) const; //binary operation +
        Vector operator-(const Vector& v1) const; //binary operation -
        Vector operator*(double a) const; //binary operation *
        double CalculateNorm(int p=2) const; //calculate p-norm. 2-norm is default
        void PrintVector();
        friend int length(const Vector& v); //friend function for vector length of a vector
};

int length(const Vector& v); //prototype signature of the friend function length

#endif