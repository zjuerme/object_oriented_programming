CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

all: Add List Remove Show

Add: Add.cpp Diary.cpp
	$(CXX) $(CXXFLAGS) -o Add.exe Add.cpp Diary.cpp

List: List.cpp Diary.cpp
	$(CXX) $(CXXFLAGS) -o List.exe List.cpp Diary.cpp

Remove: Remove.cpp Diary.cpp
	$(CXX) $(CXXFLAGS) -o Remove.exe Remove.cpp Diary.cpp

Show: Show.cpp Diary.cpp
	$(CXX) $(CXXFLAGS) -o Show.exe Show.cpp Diary.cpp

clean:
	rm -f Add.exe List.exe Remove.exe Show.exe
