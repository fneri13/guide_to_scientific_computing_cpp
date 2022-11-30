#include <iostream> 
#include <cmath>
#include "SecondOrderOde.hpp"
using namespace std;

double functionRight(double x){
    return x + 1.0;
}

int main(int argc, char* argv[]) {
    cout <<endl;
    cout << "-------------------BEGIN OF PROGRAM-------------------" <<endl;
    double Uxx = 1.0;
    double Ux = 0.5;
    double U = 2.0;
    double (*righthandSide)(double);
    righthandSide = &functionRight;
    double xMin = 0.0;
    double xMax = 1.0;

    SecondOrderOde problem_01(Uxx,Ux,U,righthandSide,xMin,xMax);
    problem_01.printInfoProblem();
    
    
    
    
    
    
    
    cout << "-------------------END OF PROGRAM-------------------" <<endl;
    cout <<endl;
    return 0;
}

