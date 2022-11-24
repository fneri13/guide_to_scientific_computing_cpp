#include <iostream> 
#include <fstream>
//code to explain how to write and read from files
//I still don't understand how it reads from file. Every situation must be its own

int main(int argc, char* argv[]) {
    std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open()){
        return 1; 
    }
    int number_of_rows = 0; 
    double dummy1, dummy2, dummy3, dummy4; 
    read_file >> dummy1 >> dummy2 >> dummy3 >> dummy4; 
    std::cout << "First row read is = " << dummy1 << dummy2 << dummy3 << dummy4 << "\n"; 
    read_file.close();
    return 0; 
}