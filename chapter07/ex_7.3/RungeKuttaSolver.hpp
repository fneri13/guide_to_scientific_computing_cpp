#ifndef RUNGEKUTTASOLVER
#define RUNGEKUTTASOLVER
#include "AbstractOdeSolver.hpp"

class RungeKuttaSolver: public AbstractOdeSolver{
    public:
        RungeKuttaSolver();
        double RightHandSide(double y, double t);
        void SolveEquation();
};
#endif