#RUN SCRIPT. SOMETHING IS WRONG WITH RUNGE KUTTA SOLVER. DON'T UNDERSTAND WHAT
echo "Euler solver computation"
g++ Exception.cpp AbstractOdeSolver.cpp ForwardEulerSolver.cpp Test_euler.cpp
./a.out
echo "Removing junk"
rm a.out
echo "Plotting"
python plot.py