#ifndef NODEHEADERDEF 
#define NODEHEADERDEF
//class to store the node cordinate of the finite difference grid
class Node {
    public:
        double coordinate;
        Node(double cord){
            coordinate = cord;
        } 
};
#endif