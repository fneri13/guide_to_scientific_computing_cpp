#include <iostream> 
#include <cmath>
using namespace std;
//send address of an integer to a function that prints out the value. Comprehensive of exercise 5.2 request

void print_value(int &number);

int main(int argc, char* argv[]) {
    int num = 9;
    cout<<num<<endl;
    print_value(num);
    cout<<num<<endl;
}

//this function modifies the value of the number also outside of the function scope
void print_value(int &number){
    number = number - 1;
    cout << "Number = "<< number << endl;
}
