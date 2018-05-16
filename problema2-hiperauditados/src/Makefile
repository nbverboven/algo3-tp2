CXXFLAGS = -g -Wall -std=c++11

SOURCES = main.cpp
HEADERS = Grafo.hpp
OBJS = $(SOURCES:.cpp=.o)

LIBS = 

TARGET = main

$(TARGET): $(OBJS) $(HEADERS)  
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)
