#Compiler to user
COMPILER=g++
#Compiler arguments
CFLAGS=-c -g -Wall
LDFLAGS=
SOURCES=main.cpp problem.cpp solver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(COMPILER) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(COMPILER) $(CFLAGS) $< -o $@
