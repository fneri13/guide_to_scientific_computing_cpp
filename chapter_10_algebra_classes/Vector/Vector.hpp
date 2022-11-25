#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <iostream>
using namespace std;

class Vector{
    private:
        double* mData;
        int mSize;
    public:
        Vector(const Vector& otherVector);
        Vector(int size);
        ~Vector();
        int GetSize() const;
        double& operator[](int i); //zero based indexing
        double Read(int i) const;
        double& operator()(int i); //one based indexing
        Vector& operator=(const Vector& otherVector);
        Vector operator+() const;
        Vector operator-() const;
        Vector operator+(const Vector& v1) const;
        Vector operator-(const Vector& v1) const;
        Vector operator*(double a) const;
        double CalculateNorm(int p=2) const;
        friend int length(const Vector& v);
};

int length(const Vector& v);

#endif