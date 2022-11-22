
#include <iostream> 
#include <fstream>
#include <cmath>
using namespace std;
//dynamic memory allocation for matrices. tested in a loop to see if memory is correctly deallocated

int main(int argc, char* argv[]) {
    for (int kk = 0; kk<10000; kk++){
        int dim = 2;
        double** A;
        double** B;
        double** C;

        A = new double* [dim];
        B = new double* [dim];
        C = new double* [dim];
        
        for (int i=0; i<dim; i++){
            A[i] = new double [dim];
            B[i] = new double [dim];
            C[i] = new double [dim];
        }

        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                A[i][j] = i+j;
                B[i][j] = 2*(i+j);
                C[i][j] = A[i][j] + B[i][j];
            }
        }

        cout<<"--------------------------LOOP "<<kk<<"--------------------------"<<endl;
        cout<<"A Matrix is "<<endl<<"["<<A[0][0]<<" "<<A[0][1]<<endl;
        cout<<A[1][0]<<" "<<A[1][1]<<"]"<<endl;
        cout<<"B Matrix is "<<endl<<"["<<B[0][0]<<" "<<B[0][1]<<endl;
        cout<<B[1][0]<<" "<<B[1][1]<<"]"<<endl;
        cout<<"C Matrix is "<<endl<<"["<<C[0][0]<<" "<<C[0][1]<<endl;
        cout<<C[1][0]<<" "<<C[1][1]<<"]"<<endl;

        for (int i=0; i<dim; i++){
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }
    return 0; 
}