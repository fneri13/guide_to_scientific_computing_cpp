#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, char* argv[]) {
  //initial data
  double u[3] = {1.0, 2.0, 3.0}; 
  double v[3] = {6.0, 5.0, 4.0}; 
  double A[3][3] = {{1.0, 5.0, 0.0},
                      {7.0, 1.0, 2.0},
                      {0.0, 0.0, 1.0}}; 
  double B[3][3] = {{-2.0, 0.0, 1.0},
                      {1.0, 0.0, 0.0},
                      {4.0, 1.0, 0.0}};
  double w[3];
  for (int i=0; i<3; i++) {
      w[i] = u[i] - 3.0*v[i];
  }


  //beginning of computation, initialization of results
  double x[3] = {0.0,0.0,0.0};
  double y[3] = {0.0,0.0,0.0};
  double z[3] = {0.0,0.0,0.0};
  double C[3][3];
  double D[3][3];

  //computation

  //x
  cout<<endl;
  cout << "x=[";
  for (int i=0; i<3; i++){
    x[i] = u[i] - v[i];
    cout<<x[i]<<endl;
  }
  cout << "]"<<endl;

  //y
  cout<<endl;
  cout << "y=[";
  double dummy = 0.0;
  for (int i=0; i<3; i++){
    double dummy = 0.0;
    for (int j=0; j<3; j++){
      dummy = dummy + A[i][j]*u[j];
    }
    y[i] = dummy;
    cout<<y[i]<<endl;
  }
  cout << "]"<<endl;

  //z
  cout<<endl;
  cout << "z=[";
  for (int i=0; i<3; i++){
    z[i] = y[i] - v[i];
    cout<<z[i]<<endl;
  }
  cout << "]"<<endl;

  //C
  cout<<endl;
  cout << "C=[";
  for (int i=0; i<3; i++){
    cout<<endl;
    for (int j=0; j<3; j++){
      C[i][j] = 4.0*A[i][j] - 3.0*B[i][j];
      cout<<C[i][j]<<" ";
    }
  }
  cout << "]"<<endl;

  return 0; 
}