EXE=main
SRC=$(filter-out main.cpp, $(wildcard *.cpp))
HEADERS=$(wildcard *.h)
OBJS=$(SRC:.cpp=.o)
FLAGS=-Wall -ggdb -std=c++11

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS) $(HEADERS) main.cpp
	g++ main.cpp $(OBJS) -o $(EXE) $(FLAGS)

%.o: %.cpp %.h
	g++ $< -c -o $@ $(FLAGS)

clean:
	rm -f $(OBJS) $(EXE)
