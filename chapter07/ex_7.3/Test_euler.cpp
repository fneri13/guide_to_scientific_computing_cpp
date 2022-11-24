#include "ForwardEulerSolver.hpp"
#include "AbstractOdeSolver.hpp"
#include <cmath>


int main(){
    ForwardEulerSolver test;
    test.SetInitialValue(2.0);
    test.SetStepSize(0.05);
    test.SetTimeInterval(0.0,1.0);
    test.SolveEquation("eul.txt");

    return 0;
}

