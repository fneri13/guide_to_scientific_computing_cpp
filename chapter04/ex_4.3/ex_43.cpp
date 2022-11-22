
#include <iostream> 
#include <fstream>
#include <cmath>
using namespace std;
//dynamic memory allocation for vectors. tested in a loop to see if memory is correctly deallocated

int main(int argc, char* argv[]) {
    for (int kk = 0; kk<100000; kk++){
        double* p1 = new double [3];
        double* p2 = new double [3];

        double scalProd = 0.0;
        for (int i=0; i<3; i++){
            p1[i] = i*1.0;
            p2[i] = i*2.0;
            scalProd = scalProd + p1[i]*p2[i];
        }
        cout<<"--------------------------LOOP "<<kk<<"--------------------------"<<endl;
        cout<<"First vector is ["<<p1[0]<<p1[1]<<p1[2]<<"]"<<endl;
        cout<<"Second vector is ["<<p2[0]<<p2[1]<<p2[2]<<"]"<<endl;
        delete[] p1;
        delete[] p2;
        cout<<"The scalar product is "<<scalProd<<endl;
    }
    return 0; 
}