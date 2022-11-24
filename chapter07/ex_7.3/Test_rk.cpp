#include "RungeKuttaSolver.hpp"
#include "AbstractOdeSolver.hpp"
#include <cmath>

//there's something wrong in the implementation I think
int main(){
    RungeKuttaSolver test;
    test.SetInitialValue(2.0);
    test.SetStepSize(0.05);
    test.SetTimeInterval(0.0,1.0);
    test.SolveEquation("rk4.txt");
    
    return 0;
}

