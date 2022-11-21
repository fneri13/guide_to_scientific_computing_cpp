#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    const int N = 3;
    double vec1[N], vec2[N];
    for (int i=0; i<N; i++){
        vec1[i] = i*i*i;
        vec2[i] = i*i*i*i;
    }
    //compute scalar product of these two vectors:
    int scalProd = 0;
    for (int i=0; i<N; i++){
        scalProd = scalProd + vec1[i]*vec2[i];
    }

    cout<<"the scalar product is "<<scalProd<<endl;
}