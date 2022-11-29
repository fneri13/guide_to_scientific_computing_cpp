#include <mpi.h>
#include <cmath>
#include <iostream>

//Program to sum Pi using Leibniz formula:
// Pi = 4 * Sum_n ( (-1)**n/(2*n+1) )
int main(int argc, char* argv[]){
    int max_n = 1000; //truncation number of the series. Ideally is a multiple of number of processes
    double sum = 0;
    MPI::Init(argc, argv); //initialize a parallel execution on argc processes
    int num_procs = MPI::COMM_WORLD.Get_size(); //how many processes
    int rank = MPI::COMM_WORLD.Get_rank(); //get the first index of these processes
    
    for (int n=rank; n<max_n; n+=num_procs){
        double temp = 1.0/(2.0*((double)(n))+1.0);
        if(n%2==0)//niseven
        {
            sum += temp;
        }
        else
        {// n is odd
            sum -= temp;
        }
    }
    double global_sum;
    MPI::COMM_WORLD.Reduce(&sum, &global_sum, 1,MPI::DOUBLE, MPI::SUM, 0); //tranfer info from all to one process
    if (rank == 0){
    std::cout << "Pi is about " << 4.0*global_sum
        << " with error " << 4.0*global_sum-M_PI
        << "\n";
    }
    MPI::Finalize(); //close the parallelization process
    return 0;
    }