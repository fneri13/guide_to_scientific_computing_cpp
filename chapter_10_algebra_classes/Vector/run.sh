#RUN SCRIPT. SOMETHING IS WRONG WITH RUNGE KUTTA SOLVER. DON'T UNDERSTAND WHAT
echo "Compiling"
g++ Vector.cpp testVector.cpp
echo "Executing"
echo "-------------------BEGIN PROGRAM----------------------"
./a.out
echo "--------------------END PROGRAM-----------------------"
echo "Removing junk"
rm a.out