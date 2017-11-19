#Compiler to user
COMPILER=g++
#Compiler arguments
CFLAGS=-c -g -Wall -I/usr/include/SDL2
LDFLAGS=-lSDL2
SOURCES=main.cpp problem.cpp solver.cpp control.cpp render.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(COMPILER) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(COMPILER) $(CFLAGS) $< -o $@
