#ifndef BOUNDARYCONDITIONSHEADERDEF
#define BOUNDARYCONDITIONSHEADERDEF
#include <iostream> 

using namespace std;
/*!
* \brief class to specify the boundary conditions
*/
class BoundaryConditions{   
    public:
    // The boundary value class is able to access the coefficients etc. of this equation
        friend class BvpOde;
    private:
        bool mLhsBcIsDirichlet;
        bool mRhsBcIsDirichlet;
        bool mLhsBcIsNeumann;
        bool mRhsBcIsNeumann;
        double mLhsBcValue;
        double mRhsBcValue;
    public:
    //default boundary conditions
        BoundaryConditions(){
            mLhsBcIsDirichlet = false;
            mRhsBcIsDirichlet = false;
            mLhsBcIsNeumann = false;
            mRhsBcIsNeumann = false;
            mLhsBcValue = 0.0;
            mRhsBcValue = 0.0;
        }
        void SetLhsDirichletBc(double lhsValue){
            assert (mLhsBcIsNeumann == false);
            mLhsBcIsDirichlet = true;
            mLhsBcValue = lhsValue;
        }
        void SetRhsDirichletBc(double rhsValue){
            assert (mRhsBcIsNeumann == false);
            mRhsBcIsDirichlet = true;
            mRhsBcValue = rhsValue;
        }
        void SetLhsNeumannBc(double lhsDerivValue){
            assert (mLhsBcIsDirichlet == false);
            mLhsBcIsNeumann = true;
            mLhsBcValue = lhsDerivValue;
        }
        void SetRhsNeumannBc(double rhsDerivValue){
            assert (mRhsBcIsDirichlet == false);
            mRhsBcIsNeumann = true;
            mRhsBcValue = rhsDerivValue;
        }
        void printBoundaryConditions(){
            cout << endl;
            cout << "BOUNDARY CONDITIONS" << endl;
            cout << "Left Dirichlet = " << mLhsBcIsDirichlet << endl;
            cout << "Left Neumann = " << mLhsBcIsNeumann << endl;
            cout << "Right Dirichlet = " << mRhsBcIsDirichlet << endl;
            cout << "Right Neumann = " << mRhsBcIsNeumann << endl;
            cout << "left value = " << mLhsBcValue << endl;
            cout << "Right value = " << mRhsBcValue << endl;
        }
};
#endif  
