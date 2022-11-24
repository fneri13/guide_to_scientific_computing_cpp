#include <iostream>

//prototypes of functions
double myFunction(double x);
double myOtherFunction(double x);

int main(int argc, char* argv[]) {
    
    //way to declare a pointer to a function
    double (*p_function)(double x); 
    
    p_function = &myFunction;
    std::cout << p_function(2.0) << "\n";
    p_function = &myOtherFunction;
    std::cout << p_function(2.0) << "\n";
return 0;
}

//square function
double myFunction(double x){
    return x*x;
}

//cube function
double myOtherFunction(double x){
    return x*x*x;
}