
#include <iostream> 
#include <fstream>
#include <cmath>
using namespace std;
//recursive function to calculate determinant of a matrix of general

double normalDet(double** A);
double** adjointMatrix(double** A);

int main(int argc, char* argv[]) {
    int dim = 3;
    double** A;

    A = new double* [dim];
    
    for (int i=0; i<dim; i++){
        A[i] = new double [dim];
    }

    for (int i=0; i<dim; i++){
        for (int j=0; j<dim; j++){
            A[i][j] = (i+j)*3;
        }
    }

    cout<<"A Matrix is "<<endl<<"["<<A[0][0]<<" "<<A[0][1]<<endl;
    cout<<A[1][0]<<" "<<A[1][1]<<"]"<<endl;
    cout<<"A Matrix determinant is "<<normalDet(A)<<endl;

    double** adjA = adjointMatrix(A, 1, 1, dim)

    for (int i=0; i<dim; i++){
        delete[] A[i];
    }
    delete[] A;
return 0; 
}

double normalDet(double** A){
    return A[0][0]*A[1][1]-A[0][1]*A[1][0];
}

double** adjointMatrix(double** A, int row, int column, int size){
    double B[size-1][size-1];
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (i<row && j<column){
                B[i][j] = A[i][j];
            }
            else if (i<row && j>=column){
                B[i][j] = A[i][j-1];
            }
            else if (i>=row && j<column){
                B[i][j] = A[i-1][j];
            }
            else if (i>=row && j>=column){
                B[i][j] = A[i-1][j-1];
            }

        }

    }
    return B;
}
