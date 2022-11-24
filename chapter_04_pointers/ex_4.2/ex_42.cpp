
#include <iostream> 
#include <fstream>
#include <cmath>
using namespace std;
//swap the values of two integers variables using only pointers

int main(int argc, char* argv[]) {
    int a = 10;
    int b = 20;
    cout << "Before swapping a="<<a<<" and b="<<b<<endl;  

    //declare pointers, with a third one needed to store information
    int* p1 = &a;
    int* p2 = &b;
    int* p3 = new int;

    *p3 = *p1;
    *p1 = *p2;
    *p2 = *p3;
    delete p3; //this pointer must be deallocated
    
    //check the swapping
    cout << "After swapping a="<<a<<" and b="<<b<<endl;  

    return 0; 
}