all: test

test: ComplexNumber.o TestComplex.o
	g++ -o test ComplexNumber.o TestComplex.o

ComplexNumber.o: ComplexNumber.cpp ComplexNumber.hpp
	g++ -c ComplexNumber.cpp

TestComplex.o: TestComplex.cpp ComplexNumber.hpp
	g++ -c TestComplex.cpp

