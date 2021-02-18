CC=g++
CFLAGS=-Wall -Werror
LDFLAGS=
SOURCES=geometry.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=geometry

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
