CXX = g++
CXXFLAGS = -Wall -std=c++17

OBJS = FilaCircular.o

all: main

main: main.o $(OBJS)
	$(CXX) $(CXXFLAGS) -o main main.o $(OBJS)

main.o: main.cpp FilaCircular.h
	$(CXX) $(CXXFLAGS) -c main.cpp

FilaCircular.o: FilaCircular.cpp FilaCircular.h
	$(CXX) $(CXXFLAGS) -c FilaCircular.cpp

clean:
	rm -f *.o main
