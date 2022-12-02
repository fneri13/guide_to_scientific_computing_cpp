#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "../Matrix/Matrix.hpp"
#include "../Vector/Vector.hpp"
#include <iostream>
using namespace std;

class LinearSystem{
    private:
        int mSize; //size of the linear system
        Matrix* mpA; //matrix of the linear system
        Vector* mpb; //vector of linear system
        
        //construct of system by copy, but copy constructor is private.
        LinearSystem(const LinearSystem &otherLinearSystem);
    
    public:
        LinearSystem(); //non-implemented default constructor to avoid implicitly constructed
        LinearSystem(const Matrix &A, const Vector &b); // normal constructor 
        ~LinearSystem(); //frees up the memory
        Vector Solve(); //method for solving the system that will be specified in the different methods
};

#endif

