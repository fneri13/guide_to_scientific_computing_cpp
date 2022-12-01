#include <iostream>
using namespace std;
#include "Matrix.hpp"
#include "../Vector/Vector.hpp"
#include <cmath>
#include <cassert>

Matrix::Matrix(const Matrix& otherMatrix){
    mNumRows = otherMatrix.getNumRows();
    mNumCols = otherMatrix.getNumCols();
    mData = new double* [mNumRows];
    for (int i = 0; i<mNumRows; i++){
        mData[i] = new double [mNumCols];
    }
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

Matrix::Matrix(int Rows, int Cols){
    mNumRows = Rows;
    mNumCols = Cols;
    mData = new double* [mNumRows];
    for (int i = 0; i<mNumRows; i++){
        mData[i] = new double [mNumCols];
    }
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mData[i][j] = 0.0;
        }
    }
}

int Matrix::getNumRows() const{
    return mNumRows;
}

int Matrix::getNumCols() const{
    return mNumCols;
}

Matrix::~Matrix(){
    for (int i=0; i<mNumRows; i++){
            delete[] mData[i];
        }
        delete[] mData;
}

void Matrix::printMatrix(){
    for (int i=0; i<mNumRows; i++){
        cout << "[";
        for (int j=0; j<mNumCols; j++){
            cout << mData[i][j];
        }
        cout << "]" << endl;
    }
}

void Matrix::SetElementValue(int i, int j, double elem){
    mData[i][j] = elem;
}

Matrix& Matrix::operator=(const Matrix& otherMatrix){
    assert(mNumRows==otherMatrix.getNumRows() && mNumCols==otherMatrix.getNumCols());
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+() const{
    Matrix M(mNumRows,mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            M.SetElementValue(i,j,mData[i][j]);
        }
    }
    return M; //return the matrix
}

Matrix Matrix::operator-() const{
    Matrix M(mNumRows,mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            M.SetElementValue(i,j,-mData[i][j]);
        }
    }
    return M; //return the matrix
}

Matrix Matrix::operator+(const Matrix& otherMatrix) const{
    Matrix M(mNumRows,mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            M.SetElementValue(i,j,mData[i][j]+otherMatrix.mData[i][j]);
        }
    }
    return M; //return the matrix
}

Matrix Matrix::operator-(const Matrix& otherMatrix) const{
    Matrix M(mNumRows,mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            M.SetElementValue(i,j,mData[i][j]-otherMatrix.mData[i][j]);
        }
    }
    return M; //return the matrix
}

Matrix Matrix::operator*(double a) const{
    Matrix M(mNumRows,mNumCols);
    for (int i=0; i<mNumRows; i++){
        for (int j=0; j<mNumCols; j++){
            M.SetElementValue(i,j,mData[i][j]*a);
        }
    }
    return M; //return the matrix
}

//something related to memory is not working properly
Vector Matrix::operator*(Vector vec) const{
    assert(mNumCols == vec.GetSize());
    Vector v(vec.GetSize());
    double sum;
    for (int i=0; i<mNumCols; i++){
        sum = 0.0;
        for (int j=0; j<mNumCols; j++){
            sum = sum + mData[i][j]*vec[i];
        }
        v[i] = sum;
    }
    return v; //return the resulting vector
}


