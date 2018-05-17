CXXFLAGS = -g -Wall -Wextra -std=c++11
SOURCES = Grafo.cpp Algoritmos.cpp
OBJS = $(SOURCES:.cpp=.o)

TARGET = main

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o $(TARGET)

main: $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) $(OBJS) main.cpp -o main

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

all: $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)
