#include <iostream>
#include "ExMatrix.hpp"
using namespace std;
#include <cmath>
#include<cassert>

//default constructor
ExMatrix::ExMatrix(){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            A[i][j] = 0.0;
        }
    }
}

//copy constructor
ExMatrix::ExMatrix(double matrix[2][2]){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            A[i][j] = matrix[i][j];
        }
    }
}

//copy constructor version 2
ExMatrix::ExMatrix(double a00, double a01, double a10, double a11){
    A[0][0] = a00;
    A[0][1] = a01;
    A[1][0] = a10;
    A[1][1] = a11;
}



//print the matrix object on the terminal
void ExMatrix::PrintMatrix(){
    cout<<"["<<A[0][0]<<" "<<A[0][1]<<endl;
    cout<<A[1][0]<<" "<<A[1][1]<<"]"<<endl;
}

//return the determinant of the matrix
double ExMatrix::Determinant(){
    double det;
    det =  A[0][0]*A[1][1]-A[0][1]*A[1][0];
    return det;
}

//return the inverse of the matrix 2x2
ExMatrix ExMatrix::Inverse(){
    double det = Determinant();
    assert(abs(det)>0.00001);
    double a00 = A[1][1]/det;
    double a01 = -A[0][1]/det;
    double a10 = -A[1][0]/det;
    double a11 = A[0][0]/det;
    ExMatrix result(a00,a01,a10,a11);
    return result;
}

//multiply by a scalar 
ExMatrix ExMatrix::ScalarMultiply(double num){
    double a00 = A[0][0]*num;
    double a01 = A[0][1]*num;
    double a10 = A[1][0]*num;
    double a11 = A[1][1]*num;
    ExMatrix result(a00,a01,a10,a11);
    return result;
}
