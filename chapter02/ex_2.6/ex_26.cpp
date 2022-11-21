#include <iostream>
#include <cmath>
using namespace std;

double ffunction(double x){
    return exp(x) + pow(x,3) -5.0;
}

double dderivative(double x){
    return exp(x) + 3.0*pow(x,2);
}

int main(int argc, char* argv[]) {
  int iter = 100;
  double x[iter];
  x[0] = 10.0;

  for (int i=1; i<iter; i++){
      x[i] = x[i-1] - ffunction(x[i-1])/dderivative(x[i-1]);
  }

  cout<<"Evolutions of the solution x= "<<endl;  
  for (int i=0; i<iter; i++){
      cout<<x[i]<<endl;
  }

  //variation using threshold criterion
  double y_old = 11.0;
  double y_new;
  double eps = 0.0001;
  double error = 1.0;
  int count = 0;
  while(error > eps){
      y_new = y_old - ffunction(y_old)/dderivative(y_old);
      error = abs((y_new - y_old)/y_old);
      count = count + 1;
      y_old = y_new;
  } 
  cout<<"With the second variant, the result is "<<y_new<<endl;
  cout<<"obtained with "<<count<<" iterations"<<endl;
  
  return 0; 
}