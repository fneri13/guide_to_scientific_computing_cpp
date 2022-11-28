#RUN SCRIPT. SOMETHING IS WRONG WITH RUNGE KUTTA SOLVER. DON'T UNDERSTAND WHAT
echo "Runge Kutta solver computation"
g++ AbstractOdeSolver.cpp RungeKuttaSolver.cpp test_main.cpp
./a.out
echo "Removing junk"
rm a.out
echo "Plotting"
python plot.py