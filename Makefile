EXEC=IloveC++
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
CCFLAGS=-Wall -Werror `sdl-config --cflags`
CC=g++
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) `sdl-config --libs` -o $(EXEC)
%.o: %.cc
	$(CC) $(CCFLAGS) -c $< -o $@ -std=c++11
clean:
	rm -f $(OBJECTS) $(EXEC)
