#include "ForwardEulerSolver.hpp"
#include <cmath>
#include <iostream>
using namespace std;

ForwardEulerSolver::ForwardEulerSolver(){
    stepSize = 0.0;
    initialTime = 0.0;
    finalTime = 0.0; 
    initialValue = 0.0;
}

//function to be solved. This may be in the main file. let's try later
double myFunction(double y, double t){
    return 1.0 + t;
}

double ForwardEulerSolver::RightHandSide(double y, double t){
    double (*p_function)(double y, double t);
    p_function = &myFunction;
    return p_function(y,t);
}

void ForwardEulerSolver::SolveEquation(){
    int N = (finalTime - initialTime)/stepSize +1;

    double* p_t = new double [N];
    double* p_y = new double [N];

    p_t[0] = initialTime;
    p_y[0] = initialValue;
    
    cout<<p_t[0]<<"\t"<<p_y[0]<<endl; 
    for (int i=1; i<N; i++){
        p_t[i] = p_t[i-1]+stepSize;
        p_y[i] = p_y[i-1]+stepSize*RightHandSide(p_y[i-1],p_t[i-1]);
        cout<<p_t[i]<<"\t"<<p_y[i]<<endl; 
    }
}