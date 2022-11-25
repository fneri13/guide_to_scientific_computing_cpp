/*example of a templated function absolute value that works with double and int number */
#include <iostream>
#include <cmath>
using namespace std;

template<class T> T AbsoluteValue(T number); 

int main(int argc, char* argv[]){
    double x1 = -3.1;
    double x2 = 3.1;
    int x3 = -1;
    int x4 = 1;
    
    //test the code
    cout<<AbsoluteValue(x1)<<endl;
    cout<<AbsoluteValue(x2)<<endl;
    cout<<AbsoluteValue(x3)<<endl;
    cout<<AbsoluteValue(x4)<<endl;
    return 0;
}

//return the absolute value of a double or an int number
template<class T> T AbsoluteValue(T number){
    if (number >= 0.0){
        return number;
    }
    else {
        return -number;
    }
}
