/* 
code on how to use function pointers in order to compute netwon raphson algorithm
*/
#include <iostream>
using namespace std;
#include <cassert>
#include <cmath>
#include <fstream>

//Newton Raphson iteration using pointers to functions
double SolveNewtonRaphson(double (*pFunc)(double), double (*pFuncPrime)(double), double x, int &its){
    double step;
    do{
        step = (*pFunc)(x) / (*pFuncPrime)(x);
        x = x - step;
        its++;
    } while (fabs(step) > 1.0e-6);
    return x;
}

//function that calculate sqrt(x)-10=0
double Sqrt10(double x){
    return sqrt(x)-10;
}

//derivative of the function to solve for 1/2sqrt(x)
double Sqrt10prime(double x){
    return 1.0/(2.0*sqrt(x));
}

//function that calculates x such that x cube = 10
double Cube10(double x){
    return x*x*x-10;
}

//derivative of the function that calculates x such that x cube = 10
double Cube10prime(double x){
    return 3*x*x;
}

int main(int argc, char* argv[])
{
    int its = 0;
    cout<< "Root of sqrt(x)-10=0, with initial guess of 1.0 is "<<SolveNewtonRaphson(Sqrt10,Sqrt10prime,1.0,its)
        <<" obtained in "<<its<<" iterations"<<endl;
    cout<< "Root of cube(x)-10=0, with initial guess of 1.0 is "<<SolveNewtonRaphson(Cube10,Cube10prime,1.0,its)
        <<" obtained in "<<its<<" iterations"<<endl;
    return 0;
}

