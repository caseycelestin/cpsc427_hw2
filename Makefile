CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++17

SpinOut: main.o spinout.o
	${CXX} ${CXXFLAGS} -o SpinOut main.o spinout.o

main.o: spinout.hpp
spinout.o: spinout.hpp

