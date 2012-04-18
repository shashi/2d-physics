# Makefile: helps in effeciently compiling the project
#
# Run `make` from the root directory to compile the project
# this only compiles modified files when rerun
#
# - Shashi Gowda
#

CC=g++
CFLAGS=-c -Wall -I.
LDFLAGS=-lGL -lglut -lGLU -I.
SOURCES=$(wildcard */*.cc)
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=main

all: $(EXECUTABLE)

clean:
	rm */*.o
	rm main
	
$(EXECUTABLE): $(OBJECTS) main.cc
	$(CC) $(LDFLAGS) $(OBJECTS) main.cc -o $@

%.o: %.cc
	$(CC) $(CFLAGS) $< -o $@
