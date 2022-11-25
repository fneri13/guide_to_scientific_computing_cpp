#ifndef EXCEPTIONDEF 
#define EXCEPTIONDEF
#include <string>
class Exception {
    private:
        std::string mTag, mProblem; 
    public:
        Exception(std::string tagString, std::string probString);
        void PrintDebug() const; //define what happens in this case, using mTag and mProblem
};
#endif //EXCEPTIONDEF