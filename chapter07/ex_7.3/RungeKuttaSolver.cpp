#include "RungeKuttaSolver.hpp"
#include <cmath>
#include <iostream>
using namespace std;

RungeKuttaSolver::RungeKuttaSolver(){
    stepSize = 0.0;
    initialTime = 0.0;
    finalTime = 0.0; 
    initialValue = 0.0;
}

double myFunction(double y, double t){
    return 1.0 + t;
}

double RungeKuttaSolver::RightHandSide(double y, double t){
    double (*p_function)(double y, double t);
    p_function = &myFunction;
    return p_function(y,t);
}

void RungeKuttaSolver::SolveEquation(){
    int N = (finalTime - initialTime)/stepSize +1;

    double* p_t = new double [N];
    double* p_y = new double [N];

    p_t[0] = initialTime;
    p_y[0] = initialValue;
    double k1,k2,k3,k4;
    cout<<p_t[0]<<"\t"<<p_y[0]<<endl; 
    for (int i=1; i<N; i++){
        p_t[i] = p_t[i-1]+stepSize;

        //Runge Kutta Cycle
        k1 = stepSize*RightHandSide(p_t[i-1],p_y[i-1]);
        k2 = stepSize*RightHandSide(p_t[i-1]+0.5*stepSize,p_y[i-1]+0.5*k1);
        k3 = stepSize*RightHandSide(p_t[i-1]+0.5*stepSize,p_y[i-1]+0.5*k2);
        k4 = stepSize*RightHandSide(p_t[i-1]+stepSize,p_y[i-1]+k3);

        p_y[i] = p_y[i-1]+(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);

        //output file
        cout<<p_t[i]<<"\t"<<p_y[i]<<endl; 
    }
}