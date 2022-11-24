#include <iostream> 
#include <fstream>
//code to explain how to write and read from files

int main(int argc, char* argv[]) {
    double x[4] = {0.0, 1.0, 1.0, 0.0}; 
    double y[4] = {0.0, 0.0, 1.0, 1.0};
    
    std::ofstream write_output_x("x.dat");
    write_output_x.setf(std::ios::scientific);
    write_output_x.setf(std::ios::showpos);
    write_output_x.precision(10);    
    write_output_x << x[0] << "," << x[1] << "," << x[2] << "," << x[3];
    write_output_x.flush();
    write_output_x.close();

    std::ofstream write_output_y("y.dat");
    write_output_y.setf(std::ios::scientific);
    write_output_y.setf(std::ios::showpos);
    write_output_y.precision(10);
    write_output_y << y[0] << "," << y[1] << "," << y[2] << "," << y[3];
    write_output_y.flush();
    write_output_y.close();

    return 0; 
}