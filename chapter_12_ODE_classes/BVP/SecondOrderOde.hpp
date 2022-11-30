#ifndef SECONDORDERODEHEADERDEF
#define SECONDORDERODEHEADERDEF

#include <iostream> 
using namespace std;
/*!
* \brief class to specify the differential equation
*/
class SecondOrderOde{
    //The boundary value class is able to access the coefficients of this equation
    friend class BvpOde;
    private: 
        //coefficients on LHS of ODE
        double mCoeffOfUxx;
        double mCoeffOfUx;
        double mCoeffOfU; 
        // Function on RHS of ODE
        double (*mpRhsFunc)(double x);
        // Interval for domain
        double mXmin;
        double mXmax;        
    public:
        /*!
        * \param[in] coeffUxx - coefficient of 2nd derivative
        * \param[in] coeffUxx - coefficient of 1st derivative
        * \param[in] coeffU - coefficient of the function
        * \param[in] righthandSide - pointer to a double function for the RHS
        * \param[in] xMinimum - left side of the domain
        * \param[in] xMaximum - right side of the domain
        */
        SecondOrderOde(double coeffUxx, double coeffUx, double coeffU, double (*righthandSide)(double),
                        double xMinimum, double xMaximum){
        mCoeffOfU = coeffU;
        mCoeffOfUx = coeffUx;
        mCoeffOfUxx = coeffUxx;
        mpRhsFunc = righthandSide;
        mXmin = xMinimum;
        mXmax = xMaximum;
        }
        
        void printInfoProblem(){
            cout <<"The differential equation is: "<<mCoeffOfUxx<<"Uxx + "<<mCoeffOfUx<<"Ux + "<<mCoeffOfU<<"U = f(x)" <<endl;
            cout <<"The domain is  ["<<mXmin<<","<<mXmax<<"]"<<endl;
        }
};
#endif
