echo "compile.."
g++ testSystem.cpp LinearSystem.cpp ../Matrix/Matrix.cpp ../Vector/Vector.cpp 
echo "execute.."
./a.out
rm a.out