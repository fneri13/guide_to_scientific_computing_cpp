/* Definition of an abstract class, that will provide the basis for an ODE solver */
#ifndef ABSTRACTODESOLVER
#define ABSTRACTODESOLVER

class AbstractOdeSolver{
    public:
        double stepSize; //in time for example
        double initialTime; 
        double finalTime; 
        double initialValue;
    public:
        void SetStepSize(double h);
        void SetTimeInterval(double t0, double t1);
        void SetInitialValue(double y0);
        
        /*The following two methods are virtual type, because they will never be called for this abstract
        class, but will be useful only to be inherited from child classes, that will override them thanks to 
        polymorphism. Every child class will specify its on methods*/
        virtual double RightHandSide(double y, double t) = 0; 
        virtual void SolveEquation() = 0;
};
#endif