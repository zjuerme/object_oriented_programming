CC = g++
CFLAGS = -Wall -g -std=c++17
TARGET = main
SRCS = $(wildcard thirdpart/*.cpp) $(wildcard src/*.cpp) main.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = -I. -Ithirdpart

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)