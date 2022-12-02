#include <iostream>
using namespace std;
#include <cmath>
#include <cassert>
#include "../Matrix/Matrix.hpp"
#include "../Vector/Vector.hpp"
#include "LinearSystem.hpp"

int main(int argc, char* argv[]){
    cout << "/*++++++++++++++++++++++++++++++ Test Matrix Class +++++++++++++++++++++++++++++++++*/"<<endl;
    int rows = 2;
    int cols = 2;
    cout<<"Number of rows and colunms of matrix = ("<<rows<<","<<cols<<")"<<endl;
    Matrix A(rows,cols);
    Matrix C(rows, cols);
    C = A;
    cout<<"Number of rows: "<<A.getNumRows()<<endl;
    cout<<"Number of cols: "<<A.getNumCols()<<endl;
    cout<<"A ="<<endl;
    for (int i=0; i<A.getNumRows(); i++){
        for (int j=0; j<A.getNumCols(); j++){
            A.SetElementValue(i,j,(i+j)*2+1);
        }
    }
    A.printMatrix();

    Matrix B(A);

    cout<<"B ="<<endl;
    B.printMatrix();

    cout<<"C ="<<endl;
    C.printMatrix();

    Matrix D(rows,cols);
    D = A + B;
    cout<<"A + B ="<<endl;
    D.printMatrix();
    D = A - C;
    cout<<"A - C ="<<endl;
    D.printMatrix();

    double c = 2.0;
    D = A * c;
    cout<<"A * 2 ="<<endl;
    D.printMatrix();

    Vector v(cols);
    double a=3.0;
    v[1] = 1.1;    
    cout<<"Vector v size = "<<v.GetSize()<<endl;
    cout<<"Vector v = "<<endl;
    v.PrintVector();

    v = A*v;
    cout<<"A*v = "<<endl;
    v.PrintVector(); 

    //test determinant method
    cout<<endl;
    cout << "------------TEST OF DETERMINANT------------" << endl;
    cout<<"A ="<<endl;
    A.printMatrix();
    cout << "determinant of A = " << A.GetDeterminant() << endl;

    cout << "------------TEST OF LINEAR SYSTEM------------" << endl;
    LinearSystem syst(A,v);
    cout<<"A ="<<endl;
    A.printMatrix();
    cout<<"Vector v = "<<endl;
    v.PrintVector();
    Vector solution(rows);
    solution = syst.Solve();
    cout<<"solution vector Ax = v --> x="<<endl;
    solution.PrintVector();
    
    return 0;
}