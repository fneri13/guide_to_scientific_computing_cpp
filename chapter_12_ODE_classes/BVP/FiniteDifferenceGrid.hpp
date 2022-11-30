#ifndef FINITEDIFFERENCEGRIDHEADERDEF 
#define FINITEDIFFERENCEGRIDHEADERDEF 
#include <vector>
#include <iostream>
#include "Node.hpp"
using namespace std;

class FiniteDifferenceGrid {
    public:
    // The boundary value class is able to // access the nodes
        friend class BvpOde;
    private:
        std::vector<Node> mNodes; //vector of nodes
    public:
        FiniteDifferenceGrid(int numNodes, double xMin, double xMax){
            Node dum_min(xMin);
            Node dum_max(xMax);
            mNodes.push_back(dum_min);
            for (int i=1; i<numNodes-1;i++){
                double step = (xMax-xMin)/(numNodes-1.0);
                double coord = step*i;
                Node dum(coord);
                mNodes.push_back(dum);
            }
            mNodes.push_back(dum_max);
        }
        void printInfoGrid(){
            int len = mNodes.size();
            cout << endl;
            cout << "GRID INFORMATION" << endl;
            cout << "Number of nodes: " << len << endl;
            cout << "The left boundary is at x=" << mNodes[0].coordinate << " mm" << endl;
            //cout << "The middle point is at x=" << mNodes[len/2].coordinate << " mm" << endl;
            cout << "The right boundary is at x=" << mNodes[len-1].coordinate << " mm" << endl;
        }

};
#endif