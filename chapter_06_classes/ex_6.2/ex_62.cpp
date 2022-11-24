#include <iostream> 
#include <cmath>
#include "ExMatrix.hpp"
using namespace std;
//send address of an integer to a function that prints out the value. Comprehensive of exercise 5.2 request


int main(int argc, char* argv[]) {
    ExMatrix A;
    double C[2][2];
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            C[i][j] = i+j+1.0;
        }
    }

    ExMatrix B(C);
    ExMatrix D(1.0, 4.21, 9.0, 8.81);

    A.PrintMatrix();
    B.PrintMatrix();
    D.PrintMatrix();


    //check the determinants
    cout<<"Determinant(A) = "<< A.Determinant() << endl;
    cout<<"Determinant(B) = "<< B.Determinant() << endl;
    cout<<"Determinant(D) = "<< D.Determinant() << endl;

    //check the inverse
    ExMatrix E;
    E = B.Inverse();
    E.PrintMatrix();
    
    ExMatrix F;
    F = D.Inverse();
    F.PrintMatrix();
    
    /* ExMatrix G;
    G = A.Inverse();
    G.PrintMatrix(); */

    //check scalar multiplication
    ExMatrix H;
    H = B.ScalarMultiply(2.5);
    H.PrintMatrix();

    return 0;
}

