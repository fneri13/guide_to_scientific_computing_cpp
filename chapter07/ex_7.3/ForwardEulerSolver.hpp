/*specification of a child class, that inherits everything from AbstractOdeSolver
Class, and overrides the two virtual methods*/
#ifndef FORWARDEULERSOLVER
#define FORWARDEULERSOLVER
#include "AbstractOdeSolver.hpp"

class ForwardEulerSolver: public AbstractOdeSolver{
    public:
        ForwardEulerSolver();
        double RightHandSide(double y, double t);
        void SolveEquation();
};
#endif