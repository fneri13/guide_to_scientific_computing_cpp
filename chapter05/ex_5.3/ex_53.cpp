#include <iostream> 
#include <cmath>
using namespace std;
//swap values using pointers and references through function

void swap_values_ref(int &a, int &b);
void swap_values_ptr(int *p_a, int *p_b);

int main(int argc, char* argv[]) {
    int a = 1;
    int b = 2;
    swap_values_ref(a,b);
    cout<<"a="<<a<<" b="<<b<<endl;

    int *p_a = &b;
    int *p_b = &a;
    swap_values_ptr(p_a, p_b);
    cout<<"a="<<*p_a<<" b="<<*p_b<<endl;
}

//this function modifies the value of the number also outside of the function scope using references
void swap_values_ref(int &a, int&b){
    int c = a;
    a = b;
    b = c;
}

//this function modifies the value of the number also outside of the function scope using pointers
void swap_values_ptr(int *p_a, int *p_b){
    int c = *p_a;
    *p_a = *p_b;
    *p_b = c;
}
