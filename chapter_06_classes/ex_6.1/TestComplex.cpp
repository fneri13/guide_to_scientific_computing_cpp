#include "ComplexNumber.hpp"
using namespace std;

int main(int argc, char* argv[]){
    ComplexNumber z1(4.0,3.0);
    cout<<"z1="<<z1<<endl;
    cout<<"Real(z1)="<<z1.GetRealPart()<<endl;
    cout<<"Friend Real(z1)="<<RealPart(z1)<<endl;
    cout<<"Imag(z1)="<<z1.GetImagPart()<<endl;
    cout<<"Friend Imag(z1)="<<ImagPart(z1)<<endl;
    cout<<"mod(z1)="<<z1.CalculateModulus()<<endl;
    cout<<"arg(z1)="<<z1.CalculateArgument()<<endl;
    cout<<"conj(z1)="<<z1.CalculateConjugate()<<endl;
    
    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    cout<<"z2=z1**3="<<z2<<endl;

    ComplexNumber z3;
    z3 = -z2;
    cout<<"z3=-z2="<<z3<<endl;

    ComplexNumber z4;
    z4 = z1+z2;
    cout<<"z4=z1+z2="<<z4<<endl;

    ComplexNumber zs[2];
    zs[0]=z1;
    zs[1]=z2;
    cout<<"second element of zs is "<<zs[1]<<endl;

    return 0;
}