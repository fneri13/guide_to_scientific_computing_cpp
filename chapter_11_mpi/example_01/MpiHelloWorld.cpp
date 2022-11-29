#include <iostream> 
#include <mpi.h>

int main(int argc, char* argv[]) {
    MPI::Init(argc, argv);
    int num_procs = MPI::COMM_WORLD.Get_size(); //returns how many processes are initialized (with mpirun command)
    int rank = MPI::COMM_WORLD.Get_rank(); //returns the first index of the list of process available
    std::cout << "Hello world from process " << rank
              << " of " << num_procs << "\n";
    MPI::Finalize();
return 0; 
}