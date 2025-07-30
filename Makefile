# Compiler and flags
CC = g++
CFLAGS = -std=c++20 -Wall -Werror -pedantic -g
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Files
SRC = main.cpp hexa.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = Hexa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(SFML_LIBS)

%.o: %.cpp hexa.hpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)

lint:
	cpplint *.cpp *.hpp

.PHONY: all clean lint

