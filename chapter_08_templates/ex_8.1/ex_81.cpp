/*example of a templated function that works with arrays of double here.
but of course could work with arrays of other data variables */
#include <iostream>
#include <cmath>
using namespace std;

template<class T> double GetData(T* rawData, int index); 

int main(int argc, char* argv[]){
    double dataRaw[5] = {1.000001, 0.2, 0.1, 0.2, 0.4};
    double dataClean[5];
    //test the code
    for (int i=0; i<5; i++){
        dataClean[i] = GetData<double>(dataRaw,i);
        cout<<dataClean[i]<<endl;
    }
    return 0;
}

//return the numbers of the arrays following some rules described in the exercise
template<class T> double GetData(T* rawData, int index){
    assert(rawData[index]>=-1e-6 && rawData[index]<=1+1.0e-6);
    if (rawData[index]>=0.0 && rawData[index]<=1.0){
        double result = rawData[index];
        return result;
    }
    else if (rawData[index]>=-1.0e-06 && rawData[index]<=0.0){
        return 0.0;
    }
    else if (rawData[index]>=1.0 && rawData[index]<=1+1.0e+06){
        return 1.0;
    }
}
