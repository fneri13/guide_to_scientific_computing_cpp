#include "ForwardEulerSolver.hpp"
#include "AbstractOdeSolver.hpp"
#include <cmath>
#include "Exception.hpp"


int main(){
    ForwardEulerSolver test;
    test.SetInitialValue(0.8);
    test.SetStepSize(0.001);
    test.SetTimeInterval(0.0,100.0);
    try{
    test.SolveEquation("eul.txt");
    }
    catch (Exception& error){
        error.PrintDebug();
    }

    return 0;
}

