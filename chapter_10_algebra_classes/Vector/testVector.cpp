#include <iostream>
using namespace std;
#include <cmath>
#include <cassert>
#include "Vector.hpp"

int main(int argc, char* argv[]){
    Vector v(3);
    double a=3.0;
    v[1] = 1.1;
    v = v*a;
    
    cout<<v.GetSize()<<endl;
    cout<<v[1]<<endl;

    return 0;
}