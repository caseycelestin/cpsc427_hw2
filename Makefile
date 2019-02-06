CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++17

all: SpinOut Unit

SpinOut: main.o spinout.o
	${CXX} ${CXXFLAGS} -o SpinOut main.o spinout.o

Unit: spinout_unit.o spinout.o
	${CXX} ${CXXFLAGS} -o Unit spinout_unit.o spinout.o

main.o: spinout.hpp
spinout.o: spinout.hpp
spinout_unit.o: spinout.hpp

