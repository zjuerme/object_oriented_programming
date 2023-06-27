# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Build target executable
TARGET = VectorTest

all: $(TARGET)

$(TARGET): main.o
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.o

main.o: main.cpp Vector.h
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)
