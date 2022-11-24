#RUN SCRIPT. SOMETHING IS WRONG WITH RUNGE KUTTA SOLVER. DON'T UNDERSTAND WHAT
echo "Euler solver computation"
g++ AbstractOdeSolver.cpp ForwardEulerSolver.cpp Test_euler.cpp
./a.out
echo "Runge Kutta solver computation"
g++ AbstractOdeSolver.cpp RungeKuttaSolver.cpp Test_rk.cpp
./a.out
echo "Removing junk"
rm a.out
echo "Plotting"
python plot.py