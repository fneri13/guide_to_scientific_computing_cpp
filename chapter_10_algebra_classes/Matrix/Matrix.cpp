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

double &Matrix::operator()(int i, int j)             // One-based indexing
{
    assert(i > 0);
    assert(i < mNumRows + 1);
    assert(j > 0);
    assert(j < mNumCols + 1);
    return mData[i-1][j-1];
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

// Overloading matrix multiplied by a vector
Vector operator*(const Matrix &m, const Vector &v)
{
    int original_vector_size = v.GetSize();
    assert(m.getNumCols() == original_vector_size);
    int new_vector_length = m.getNumRows();
    Vector new_vector(new_vector_length);

    for (int i = 0; i < new_vector_length; i++)
    {
        for (int j = 0; j < original_vector_size; j++)
        {
            new_vector[i] += m.mData[i][j] * v.Read(j);
        }
    }
    return new_vector;
}

double Matrix::GetDeterminant()
{
    assert(mNumRows == mNumCols);
    double determinant = 0.0;

    if (mNumRows == 1)
    {
        determinant = mData[0][0];
    }
    else
    {
        // More than one entry of matrix
        for (int i_outer = 0; i_outer < mNumRows; i_outer++)
        {
            Matrix sub_matrix(mNumRows - 1, mNumRows - 1);
            for (int i = 0; i < mNumRows - 1; i++)
            {
                for (int j = 0; j < i_outer; j++)
                {
                    sub_matrix(i + 1, j + 1) = mData[i + 1][j];
                }
                for (int j = i_outer; j < mNumRows - 1; j++)
                {
                    sub_matrix(i + 1, j + 1) = mData[i + 1][j + 1];
                }
            }
            double sub_matrix_determinant = sub_matrix.GetDeterminant();
            determinant += pow(-1.0, i_outer) * mData[0][i_outer] * sub_matrix_determinant;
        }
    }
    return determinant;
}
