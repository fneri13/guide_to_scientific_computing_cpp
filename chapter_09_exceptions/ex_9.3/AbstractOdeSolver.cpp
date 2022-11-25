#include "AbstractOdeSolver.hpp"
#include <cmath>

void AbstractOdeSolver::SetStepSize(double h){
    stepSize = h;
}

void AbstractOdeSolver::SetTimeInterval(double t0, double t1){
    initialTime = t0;
    finalTime = t1;
}

void AbstractOdeSolver::SetInitialValue(double y0){
    initialValue = y0;
}

//the virtual methods don't need to be specified because they will be inherited and overridden