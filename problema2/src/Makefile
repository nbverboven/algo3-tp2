CXXFLAGS = -g -Wall -Wextra -std=c++11
SOURCES = $(filter-out main.cpp, $(wildcard *.cpp))
OBJS = $(SOURCES:.cpp=.o)

TARGET = main

main: $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

all: $(TARGET)

clean:
	rm -f *.o $(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)
