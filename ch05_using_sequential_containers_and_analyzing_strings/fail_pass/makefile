# Compiler of choice
CC=g++

# Flags for the compiler
CFLAGS=-c -Wall -g -ggdb -Ofast -pedantic-errors -std=c++0x

# Flags for compilers that need invoke the linker (e.g. libraries)
LDFLAGS=

# Change filenames accordingly per project
SOURCES=main.cpp grade.cpp Student_info.cpp median.cpp
EXECUTABLE=grade

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
