//this command serves to define everything is inside if it's not been defined yet
#ifndef MATRIXEX
#define MATRIXEX

#include <iostream>
using namespace std;

class ExMatrix{
    private:
        double A[2][2];
    public:
        ExMatrix();
        ExMatrix(double matrix[2][2]);
        ExMatrix(double a00, double a01, double a10, double a11);
        void PrintMatrix();
        double Determinant();
        ExMatrix Inverse();
        ExMatrix ScalarMultiply(double num);

};

#endif