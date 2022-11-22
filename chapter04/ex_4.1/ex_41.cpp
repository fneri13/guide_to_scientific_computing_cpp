#include <iostream> 
#include <fstream>
#include <cmath>
using namespace std;
//code used to understand pointers and references/dereferences

int main(int argc, char* argv[]) {
    //declare an int variable i = 5
    int i = 5;

    //declare a pointer to an integer, who points at variable i
    int* p_j = &i;

    //modify the content of i times 5, only using the pointer variable
    *p_j = *p_j * 5;

    //declare a new pointer to an int, initialized memory location
    int* p_k = new int;

    //store the content of i variable in this location
    *p_k = i;

    //change the value pointed by p_j to 0
    *p_j = *p_j * 0;

    cout<<"-----------------------NOTICE THE FOLLOWING-----------------------"<<endl;
    cout<<"i = "<<i<<endl;
    cout<<"address of i = "<<&i<<endl;
    cout<<"*p_j = "<<*p_j<<endl;
    cout<<"address of *p_j = "<<p_j<<endl;
    cout<<"*p_k = "<<*p_k<<endl;
    cout<<"address of *p_k = "<<p_k<<endl;
    cout<<"-----------------------END OF PROGRAM-----------------------"<<endl;

    return 0; 
}