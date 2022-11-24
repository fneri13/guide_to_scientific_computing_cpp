#include "ForwardEulerSolver.hpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>


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

void ForwardEulerSolver::SolveEquation(std::string output_file_name){
    int N = (finalTime - initialTime)/stepSize +1;

    double* p_t = new double [N];
    double* p_y = new double [N];

    p_t[0] = initialTime;
    p_y[0] = initialValue;
    
    //write the solution to a file_output
    std::ofstream write_output(output_file_name);
    write_output<<p_t[0]<<"\t"<<p_y[0]<<std::endl; 
    write_output.setf(std::ios::showpos);    write_output.precision(6);
    for (int i=1; i<N; i++){
        p_t[i] = p_t[i-1]+stepSize;
        p_y[i] = p_y[i-1]+stepSize*RightHandSide(p_y[i-1],p_t[i-1]);
        write_output<<p_t[i]<<"\t"<<p_y[i]<<std::endl; 
    }
    write_output.close();
}