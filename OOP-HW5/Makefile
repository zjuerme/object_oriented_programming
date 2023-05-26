CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra

all: main

main: main.o Fraction.o
	$(CXX) $(CXXFLAGS) -o main main.o Fraction.o

main.o: main.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Fraction.o: Fraction.cpp Fraction.h
	$(CXX) $(CXXFLAGS) -c Fraction.cpp

.PHONY: clean

clean:
	del /f *.o main
