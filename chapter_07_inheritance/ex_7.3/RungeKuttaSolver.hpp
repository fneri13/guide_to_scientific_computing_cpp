#ifndef RUNGEKUTTASOLVER
#define RUNGEKUTTASOLVER
#include "AbstractOdeSolver.hpp"
#include <string>

class RungeKuttaSolver: public AbstractOdeSolver{
    public:
        RungeKuttaSolver();
        double RightHandSide(double y, double t);
        void SolveEquation(std::string output_name);
};
#endif